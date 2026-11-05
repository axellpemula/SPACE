#pragma once

#include <atomic>
#include <chrono>
#include <mutex>
#include <thread>

enum TouchPhase {
	Began = 0,
	Moved = 1,
	Stationary = 2,
	Ended = 3,
	Canceled = 4,
};

enum TouchType {
	Direct = 1,
	Indirect = 2,
	Stylus = 2,
};

struct Touch {
	int m_FingerId;
	Vector2 m_Position;
	Vector2 m_RawPosition;
	Vector2 m_PositionDelta;
	float m_TimeDelta;
	int m_TapCount;
	TouchPhase m_Phase;
	TouchType m_Type;
	float m_Pressure;
	float m_maximumPossiblePressure;
	float m_Radius;
	float m_RadiusVariance;
	float m_AltitudeAngle;
	float m_AzimuthAngle;
};

// ========== THREAD-SAFE TOUCH CACHE ==========
struct CachedTouchData {
	std::atomic<bool> hasTouch{false};
	std::atomic<int> touchCount{0};
	std::atomic<int> phase{-1};
	std::atomic<float> posX{0};
	std::atomic<float> posY{0};
	std::atomic<bool> isValid{false};
	std::chrono::steady_clock::time_point lastUpdate;
};

static CachedTouchData g_CachedTouch;
static std::mutex g_TouchMutex;
static int g_ScreenHeight = 0;

// Unity function pointers - ONLY call from main thread!
int get_touchCount(void *_this) {
	int (*_get_touchCount)(void *_this) = (int (*)(void *)) (Il2CppGetMethodOffset("UnityEngine.InputLegacyModule.dll", "UnityEngine", "Input", "get_touchCount", 0));
	return _get_touchCount(_this);
}

bool get_touchSupported(void *_this) {
	bool (*_get_touchSupported)(void *_this) = (bool (*)(void *)) (Il2CppGetMethodOffset("UnityEngine.InputLegacyModule.dll", "UnityEngine", "Input", "get_simulateMouseWithTouches", 0));
	return _get_touchSupported(_this);
}

Vector3 get_mousePosition(void *_this) {
	Vector3 (*_get_mousePosition)(void *_this) = (Vector3 (*)(void *)) (Il2CppGetMethodOffset("UnityEngine.InputLegacyModule.dll", "UnityEngine", "Input", "get_mousePosition", 0));
	return _get_mousePosition(_this);
}

Touch GetTouch(void *_this, int index) {
	Touch (*_GetTouch)(void *_this, int index) = (Touch (*)(void *, int)) (Il2CppGetMethodOffset("UnityEngine.InputLegacyModule.dll", "UnityEngine", "Input", "GetTouch", 1));
	return _GetTouch(_this, index);
}

// ========== CALL THIS FROM MAIN THREAD ONLY ==========
void UpdateTouchCacheFromMainThread() {
	std::lock_guard<std::mutex> lock(g_TouchMutex);
	
	void *_this = nullptr;
	int count = get_touchCount(_this);
	g_CachedTouch.touchCount = count;
	
	if (count > 0) {
		Touch touch = GetTouch(_this, 0);
		g_CachedTouch.hasTouch = true;
		g_CachedTouch.phase = touch.m_Phase;
		g_CachedTouch.posX = touch.m_Position.x;
		g_CachedTouch.posY = g_ScreenHeight - touch.m_Position.y;
		g_CachedTouch.isValid = true;
	} else {
		g_CachedTouch.hasTouch = false;
		g_CachedTouch.isValid = true;
	}
	
	g_CachedTouch.lastUpdate = std::chrono::steady_clock::now();
}

// ========== SET SCREEN HEIGHT FROM MAIN THREAD ==========
void SetTouchScreenHeight(int height) {
	g_ScreenHeight = height;
}

// ========== CALL THIS FROM RENDER THREAD ONLY - NO UNITY CALLS! ==========
void OnTouchEvent() {
	ImGuiIO* io = &ImGui::GetIO();
	
	// Check if cache is valid and not too old (>100ms)
	auto now = std::chrono::steady_clock::now();
	auto age = std::chrono::duration_cast<std::chrono::milliseconds>(now - g_CachedTouch.lastUpdate).count();
	
	if (!g_CachedTouch.isValid.load() || age > 100) {
		io->MouseDown[0] = false;
		return;
	}
	
	if (!g_CachedTouch.hasTouch.load()) {
		io->MouseDown[0] = false;
		return;
	}
	
	int phase = g_CachedTouch.phase.load();
	ImVec2 mousePos(g_CachedTouch.posX.load(), g_CachedTouch.posY.load());
	
	switch (phase) {
		case TouchPhase::Began:
		case TouchPhase::Stationary:
			io->MouseDown[0] = true;
			io->MousePos = mousePos;
			break;
			
		case TouchPhase::Ended:
		case TouchPhase::Canceled:
			io->MouseDown[0] = false;
			clearMousePos = true;
			break;
			
		case TouchPhase::Moved:
			io->MousePos = mousePos;
			break;
		default:
			break;
	}
}