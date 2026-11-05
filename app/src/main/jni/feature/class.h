#pragma once

//========================================================
// UNYENGINE / CORE OFFSETS
//========================================================

//Class Screen
#define Screen_get_width (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Screen"), OBFUSCATE("get_width"))
#define Screen_get_height (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Screen"), OBFUSCATE("get_height"))
#define Screen_get_dpi (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Screen"), OBFUSCATE("get_dpi"))
#define Screen_SetResolution (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Screen"), OBFUSCATE("SetResolution"), 3)

class Screen {
public:
    static void SetResolution(int width, int height, bool fullscreen) {
        auto _ = reinterpret_cast<void(*)(int, int, bool)>((uintptr_t)Screen_SetResolution);
        _(width, height, fullscreen);
    }
    static int get_width() {
        return reinterpret_cast<int(*)()>((uintptr_t)Screen_get_width)();
    }
    static int get_height() {
        return reinterpret_cast<int(*)()>((uintptr_t)Screen_get_height)();
    }
    static int get_dpi() {
        return (int)reinterpret_cast<float(*)()>((uintptr_t)Screen_get_dpi)();
    }
};

//Clads Camera
#define Camera_get_main (uintptr_t) Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Camera", "get_main", 0)
#define Camera_WorldToScreenPoint (uintptr_t) Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Camera", "WorldToScreenPoint", 1)
#define Camera_get_fieldOfView (uintptr_t) Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Camera", "get_fieldOfView", 0)
#define Camera_set_fieldOfView (uintptr_t) Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Camera", "set_fieldOfView", 1)

//========================================================
// BATTLE / GAME LOGIC OFFSETS
//========================================================

//Class ShowEntity
#define ShowEntity__Position (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("ShowEntity"), OBFUSCATE("m_vCachePosition"))
#define ShowEntity_m_RoleName (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", OBFUSCATE("m_RoleName"))

//Class ShowPlayer
#define ShowPlayer_m_HeroName (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("ShowPlayer"), OBFUSCATE("m_HeroName"))

//Class EntityBase
#define EntityBase_m_ID (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("ShowEntity"), OBFUSCATE("m_ID"))
#define EntityBase_m_Level (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("ShowEntity"), OBFUSCATE("m_Level"))
#define EntityBase_m_bDeath (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("ShowEntity"), OBFUSCATE("m_bDeath"))
#define EntityBase_m_bSameCampType (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("ShowEntity"), OBFUSCATE("m_bSameCampType"))
#define EntityBase_m_Hp (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("ShowEntity"), OBFUSCATE("m_Hp"))
#define EntityBase_m_HpMax (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("ShowEntity"), OBFUSCATE("m_HpMax"))
#define EntityBase_m_iType (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", OBFUSCATE("m_iType"))

//Class BattleManager
#define BattleManager_m_LocalPlayerShow (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "BattleManager", OBFUSCATE("m_LocalPlayerShow"))
#define BattleManager_m_ShowPlayers (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "BattleManager", OBFUSCATE("m_ShowPlayers"))
#define BattleManager_m_ShowMonsters (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "BattleManager", "m_ShowMonsters")
#define BattleManager_m_dicPlayerShow (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BattleManager"), OBFUSCATE("m_dicPlayerShow"))
#define BattleManager_m_dicMonsterShow (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BattleManager"), OBFUSCATE("m_dicMonsterShow"))

//Class BattleData
#define BattleData_battleManager (uintptr_t) Il2CppGetStaticFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BattleManager"), OBFUSCATE("Instance"))
#define BattleData_m_BattleBridge (uintptr_t) Il2CppGetStaticFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BattleData"), OBFUSCATE("m_BattleBridge"))

//Class BattleBridge
#define BattleBridge_get_bStartBattle (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BattleBridge"), OBFUSCATE("get_bStartBattle"))

//Class LogicBattleManager
#define LogicBattleManager_Instan (uintptr_t) Il2CppGetStaticFieldOffset("Assembly-CSharp.dll", "", "LogicBattleManager", OBFUSCATE("Instance"))
#define LogicBattleManager_GetPlayerLogic (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "LogicBattleManager", OBFUSCATE("GetPlayerLogic"), 1)

//Class ShowSkillData
#define ShowSkillData_m_TranID (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", OBFUSCATE("ShowSkillData"), OBFUSCATE("m_TranID"))

//Class ShowEntity
#define ShowEntity_m_OwnSkillComp (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", OBFUSCATE("m_OwnSkillComp"))

//Class ShowOwnSkillComp
#define ShowOwnSkillComp_m_SkillList (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", OBFUSCATE("ShowOwnSkillComp"), OBFUSCATE("m_SkillList"))
#define ShowOwnSkillComp_skillUseTypeList (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", OBFUSCATE("ShowOwnSkillComp"), OBFUSCATE("skillUseTypeList"))

//Class ShowPlayer
#define ShowPlayer_m_iSummonSkillId (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowPlayer", OBFUSCATE("m_iSummonSkillId"))

//Class Logic
#define LogicFighter_m_SkillComp (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", OBFUSCATE("LogicFighter"), OBFUSCATE("m_SkillComp"))
#define LogicSkillComp_m_CoolDownComp (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", OBFUSCATE("LogicSkillComp"), OBFUSCATE("m_CoolDownComp"))

//Class CoolDown
#define CoolDownComp_m_DicCoolInfo (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", OBFUSCATE("CoolDownComp"), OBFUSCATE("m_DicCoolInfo"))
#define CoolDownData_GetCoolTime (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "Battle", OBFUSCATE("CoolDownData"), OBFUSCATE("GetCoolTime"))

//Functions
uintptr_t GetPlayerLogic(uint id) {
    auto instance = *(uintptr_t *) ((uintptr_t)LogicBattleManager_Instan);
    if (!instance) return 0;
    return reinterpret_cast<uintptr_t(__fastcall *)(void *, uint)>(LogicBattleManager_GetPlayerLogic)((void *)instance, id);
}

int GetCoolTime(void* instance) {
    return reinterpret_cast<int(__fastcall *)(void *)>(CoolDownData_GetCoolTime)(instance);
}
