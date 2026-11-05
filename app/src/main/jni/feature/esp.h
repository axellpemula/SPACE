#include "class.h"
#include "monster.h"
#include <cmath>
#include <string>

bool Line;
bool Box;
bool Health;
bool PlayerName;
bool HeroName;
bool IconAlert;

bool MinionDot;
bool MonsterBox;
bool MonsterHealth;
bool JungleDot;
bool MonsterName;

bool SkillCD;
bool SpellCD;

// [ CONFIG & CAMERA ]
float SetFieldOfView = 0;
void* get_main() { static auto f = (void*(*)())Camera_get_main; return f ? f() : nullptr; }
Vector3 WorldToScreen(Vector3 p) { static auto f = (Vector3(*)(void*, Vector3))Camera_WorldToScreenPoint; void* c = get_main(); return (f && c) ? f(c, p) : Vector3{0,0,0}; }
float get_FOV() { static auto f = (float(*)(void*))Camera_get_fieldOfView; void* c = get_main(); return (f && c) ? f(c) : 0.0f; }
void set_FOV(float v) { static auto f = (void(*)(void*, float))Camera_set_fieldOfView; void* c = get_main(); if (f && c) f(c, v); }

// [ SYSTEMS & MATH ]
void DroneView() {
    static float Def = 0; float cur = get_FOV(); if (Def == 0 && cur > 0) Def = cur; if (Def == 0) return;
    float tar = (SetFieldOfView > 0) ? (Def + SetFieldOfView) : Def;
    if (std::abs(cur - tar) > 0.1f) set_FOV(tar);
}

bool isOutside(ImVec2 p, ImVec2 s) { return (p.x < 0 || p.x > s.x || p.y < 0 || p.y > s.y); }

ImVec2 getPosVec2(Vector3 p, int w, int h) {
    Vector3 v = WorldToScreen(p);
    return (v.z > 0) ? ImVec2(v.x, (float)h - v.y) : ImVec2((float)w - v.x, (float)h + v.y);
}

ImVec2 pushToBorder(Vector3 p, ImVec2 s, float pad) {
    Vector3 v = WorldToScreen(p); float x = v.x, y = v.y; if (v.z < 0) { x = s.x - x; y = s.y - y; }
    float cX = s.x/2, cY = s.y/2, ang = atan2f(y-cY, x-cX), cA = cosf(ang), sA = sinf(ang);
    float m = sA/cA, sX = cX-pad, sY = cY-pad;
    if (cA > 0) { x = sX; y = m*sX; } else { x = -sX; y = m*-sX; }
    if (y > sY) { y = sY; x = sY/m; } else if (y < -sY) { y = -sY; x = -sY/m; }
    return ImVec2(x + cX, y + cY);
}

// [ DRAWING ]
void DrawHealth(ImVec2 p, int h, int m, float r) {
    if (m <= 0) return;
    ImU32 col = (h <= m*0.3f) ? IM_COL32(255,55,55,255) : (h <= m*0.6f) ? IM_COL32(180,180,45,255) : IM_COL32(75,205,75,255);
    float start = -1.570796f, end = start + (6.283185f * ((float)h/(float)m));
    ImGui::GetForegroundDrawList()->PathArcTo(p, r, start, end, 32);
    ImGui::GetForegroundDrawList()->PathStroke(col, 0, 3.5f);
}

struct CooldownValues {
    int skillCount, skill1, skill2, skill3, skill4, spell;
};

CooldownValues getPlayerCoolDown(int keys, uintptr_t values) {
    // 1. Initial Validations (Same Logic)
    auto logicFighter = GetPlayerLogic((uint)keys);
    if (!logicFighter) return {0, 0, 0, 0, 0, 0};
    
    auto m_SkillComp = *(uintptr_t *)((uintptr_t)logicFighter + LogicFighter_m_SkillComp);
    if (!m_SkillComp) return {0, 0, 0, 0, 0, 0};
    
    auto m_CoolDownComp = *(uintptr_t *)((uintptr_t)m_SkillComp + LogicSkillComp_m_CoolDownComp);
    if (!m_CoolDownComp) return {0, 0, 0, 0, 0, 0};
    
    auto m_OwnSkillComp = *(uintptr_t *)((uintptr_t)values + ShowEntity_m_OwnSkillComp);
    if (!m_OwnSkillComp) return {0, 0, 0, 0, 0, 0};
    
    auto skillUseTypeList = *(Dictionary<int, List<int> *> **)((uintptr_t)m_OwnSkillComp + ShowOwnSkillComp_skillUseTypeList);
    if (!skillUseTypeList) return {0, 0, 0, 0, 0, 0};

    int sCount = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, spell = 0;
    int summonSkillId = *(int *)((uintptr_t)values + ShowPlayer_m_iSummonSkillId);

    // 2. Optimized Loops
    for (int v = 0; v < skillUseTypeList->getNumKeys(); v++) {
        if (skillUseTypeList->getKeys()[v] != 1) continue;
        
        auto valuesskillUseType = skillUseTypeList->getValues()[v];
        if (!valuesskillUseType) continue;
        sCount = valuesskillUseType->getSize();

        auto m_SkillList = *(List<uintptr_t> **)((uintptr_t)m_OwnSkillComp + ShowOwnSkillComp_m_SkillList);
        if (!m_SkillList) break;

        auto m_DicCoolInfo = *(Dictionary<int, uintptr_t> **)((uintptr_t)m_CoolDownComp + CoolDownComp_m_DicCoolInfo);
        if (!m_DicCoolInfo) break;

        // Optimization: Pre-fetch keys and values arrays
        auto coolKeys = m_DicCoolInfo->getKeys();
        auto coolVals = m_DicCoolInfo->getValues();
        int numCoolKeys = m_DicCoolInfo->getNumKeys();

        for (int i = 0; i < 5; i++) {
            auto p_SkillList = m_SkillList->getItems()[i];
            if (!p_SkillList) continue;
            
            int m_TranID = *(int *)((uintptr_t)p_SkillList + ShowSkillData_m_TranID);
            
            for (int l = 0; l < numCoolKeys; l++) {
                auto kC = coolKeys[l];
                auto vC = coolVals[l];
                if (!kC || !vC) continue;
                
                int coolTime = GetCoolTime((void*)vC) / 1000;
                
                // Spell detection
                if (kC == summonSkillId) spell = coolTime;
                
                // Skill detection using TranID
                if (m_TranID == kC) {
                    if (i == 1) s1 = coolTime;
                    else if (i == 2) s2 = coolTime;
                    else if (i == 3) s3 = coolTime;
                    else if (i == 4) s4 = coolTime;
                }
            }
        }
    }
    return {sCount, s1, s2, s3, s4, spell};
}

void DrawESP(ImDrawList *draw, float screenWidth, float screenHeight) {
    // 1. INITIALIZATION & VALIDATION
    void *BattleBridge_Instance = nullptr;
    Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleData", "m_BattleBridge", &BattleBridge_Instance);
    
    if (!BattleBridge_Instance) return;

    auto getter = reinterpret_cast<bool (__fastcall*)(void*)>(BattleBridge_get_bStartBattle);
    if (!getter || !getter(BattleBridge_Instance)) return;

    DroneView();

    auto battleManager = *(uintptr_t *)((uintptr_t)BattleData_battleManager);
    if (!battleManager) return;

    auto m_LocalPlayerShow = *(uintptr_t *)((uintptr_t)battleManager + BattleManager_m_LocalPlayerShow);
    if (!m_LocalPlayerShow) return;

    // 2. GET DICTIONARIES
    auto m_dicPlayerShow = *(Dictionary<int, uintptr_t> **)((uintptr_t)battleManager + BattleManager_m_dicPlayerShow);
    auto m_dicMonsterShow = *(Dictionary<int, uintptr_t> **)((uintptr_t)battleManager + BattleManager_m_dicMonsterShow);

    // RGB Glow for Line & Dot only
    float time = ImGui::GetTime() * 2.0f;
    ImU32 rgbCol = IM_COL32((int)(sinf(time)*127+128), (int)(sinf(time+2.094f)*127+128), (int)(sinf(time+4.188f)*127+128), 255);

    auto selfPos = *(Vector3 *)((uintptr_t)m_LocalPlayerShow + ShowEntity__Position);
    auto selfPosVec2 = getPosVec2(selfPos, screenWidth, screenHeight);

    // --- 3. MONSTER & MINION LOOP (3D RED HEALTH) ---
    if (m_dicMonsterShow) {
        for (int i = 0; i < m_dicMonsterShow->getNumKeys(); i++) {
            auto mValues = m_dicMonsterShow->getValues()[i];
            if (!mValues) continue;

            if (*(bool *)((uintptr_t)mValues + EntityBase_m_bDeath)) continue;
            if (*(bool *)((uintptr_t)mValues + EntityBase_m_bSameCampType)) continue;

            int monsterType = *(int *)((uintptr_t)mValues + EntityBase_m_iType);
            
            if (monsterType == 2 || monsterType == 5) {
                auto mPos = *(Vector3 *)((uintptr_t)mValues + ShowEntity__Position);
                auto mPosVec2 = getPosVec2(mPos, screenWidth, screenHeight);

                if (MonsterName) {
                    int m_ID = *(int *)((uintptr_t)mValues + EntityBase_m_ID);
                    std::string mName = MonsterToString(m_ID);
                    draw->AddText(NULL, 39.0f, {mPosVec2.x, mPosVec2.y - 45}, IM_COL32(255, 255, 0, 255), mName.c_str());
                }

                if (JungleDot) {
                    draw->AddCircleFilled(mPosVec2, 6.0f, rgbCol); 
                    draw->AddCircle(mPosVec2, 10.5f, IM_COL32(255, 255, 255, 200));
                }

                if (MonsterBox) {
                    float bH = screenHeight / 15.0f, bW = bH, lLen = bW * 0.35f;
                    ImVec2 tL = {mPosVec2.x - bW/2, mPosVec2.y - bH}, bR = {mPosVec2.x + bW/2, mPosVec2.y};
                    draw->AddLine(tL, {tL.x + lLen, tL.y}, IM_COL32(255, 255, 255, 255), 2.0f);
                    draw->AddLine(tL, {tL.x, tL.y + lLen}, IM_COL32(255, 255, 255, 255), 2.0f);
                    draw->AddLine({bR.x, tL.y}, {bR.x - lLen, tL.y}, IM_COL32(255, 255, 255, 255), 2.0f);
                    draw->AddLine({bR.x, tL.y}, {bR.x, tL.y + lLen}, IM_COL32(255, 255, 255, 255), 2.0f);
                    draw->AddLine({tL.x, bR.y}, {tL.x + lLen, bR.y}, IM_COL32(255, 255, 255, 255), 2.0f);
                    draw->AddLine({tL.x, bR.y}, {tL.x, bR.y - lLen}, IM_COL32(255, 255, 255, 255), 2.0f);
                    draw->AddLine(bR, {bR.x - lLen, bR.y}, IM_COL32(255, 255, 255, 255), 2.0f);
                    draw->AddLine(bR, {bR.x, bR.y - lLen}, IM_COL32(255, 255, 255, 255), 2.0f);
                }

                // --- 3D RED GRADIENT MONSTER HEALTH ---
                if (MonsterHealth) {
                    int mCurHP = *(int *)((uintptr_t)mValues + EntityBase_m_Hp), mMaxHP = *(int *)((uintptr_t)mValues + EntityBase_m_HpMax);
                    if (mMaxHP > 0) {
                        float bW = 90.0f, bH = 14.0f, hpP = (float)mCurHP / (float)mMaxHP;
                        ImVec2 bgS = {mPosVec2.x - bW/2, mPosVec2.y + 10}, bgE = {mPosVec2.x + bW/2, mPosVec2.y + 10 + bH};
                        
                        // Red 3D Gradient Colors
                        ImU32 colRedMain = IM_COL32(255, 0, 0, 255);   // Top color (Bright Red)
                        ImU32 colRedDark = IM_COL32(120, 0, 0, 255);   // Bottom color (Dark Red)

                        draw->AddRectFilled(bgS, bgE, IM_COL32(0, 0, 0, 180)); // Background shadow
                        
                        // 3D Fill using MultiColor for depth
                        draw->AddRectFilledMultiColor({bgS.x, bgS.y}, {bgS.x + (bW * hpP), bgE.y}, colRedMain, colRedMain, colRedDark, colRedDark);
                        
                        // Border to keep it clean
                        draw->AddRect(bgS, bgE, IM_COL32(255, 255, 255, 255), 0, 0, 1.0f);
                    }
                }
            }
              else if (MinionDot && monsterType == 1) {
                auto mPos = *(Vector3 *)((uintptr_t)mValues + ShowEntity__Position);
                auto mPosVec2 = getPosVec2(mPos, screenWidth, screenHeight);
                draw->AddCircleFilled(mPosVec2, 10.0f, IM_COL32(0, 0, 255, 255)); 
                draw->AddCircle(mPosVec2, 10.5f, IM_COL32(255, 255, 255, 255), 0, 1.0f);
            }
        }
    }

    // --- 4. PLAYER LOOP (3D HEALTH & DIAMOND CD) ---
    if (m_dicPlayerShow) {
        for (int i = 0; i < m_dicPlayerShow->getNumKeys(); i++) {
            auto values = m_dicPlayerShow->getValues()[i];
            if (!values || (uintptr_t)values == m_LocalPlayerShow) continue;

            if (*(bool *)((uintptr_t)values + EntityBase_m_bDeath)) continue;
            if (*(bool *)((uintptr_t)values + EntityBase_m_bSameCampType)) continue;

            auto __Pos = *(Vector3 *)((uintptr_t)values + ShowEntity__Position);
            auto rPos = getPosVec2(__Pos, screenWidth, screenHeight);
            auto hPos = Vector2(rPos.x, rPos.y - (screenHeight / 6.35));

            float boxHeight = abs(hPos.y - rPos.y);
            float halfWidth = (boxHeight * 0.60f) / 2.0f;

            // --- HERO & PLAYER NAME (RIGHT SIDE) ---
            if (PlayerName || HeroName) {
                auto *mH = *(String **) ((uintptr_t)values + ShowPlayer_m_HeroName);
                auto *mR = *(String **) ((uintptr_t)values + ShowEntity_m_RoleName);
                std::string info = (HeroName && mH ? mH->toString() : "") + (PlayerName && mR ? "\n" + mR->toString() : "");
                draw->AddText(NULL, 39.0f, {hPos.x + halfWidth + 12.0f, hPos.y}, IM_COL32(255, 255, 255, 255), info.c_str());
            }

            if (Line) {
                draw->AddLine(selfPosVec2, rPos, rgbCol, 1.5f);
                draw->AddCircleFilled(rPos, 5.0f, rgbCol);
            }

            if (Box) {
                float lLen = halfWidth * 0.6f;
                ImVec2 tL = {hPos.x - halfWidth, hPos.y}, bR = {hPos.x + halfWidth, rPos.y};
                draw->AddLine(tL, {tL.x + lLen, tL.y}, IM_COL32(255, 255, 255, 255), 2.5f);
                draw->AddLine(tL, {tL.x, tL.y + lLen}, IM_COL32(255, 255, 255, 255), 2.5f);
                draw->AddLine({bR.x, tL.y}, {bR.x - lLen, tL.y}, IM_COL32(255, 255, 255, 255), 2.5f);
                draw->AddLine({bR.x, tL.y}, {bR.x, tL.y + lLen}, IM_COL32(255, 255, 255, 255), 2.5f);
                draw->AddLine({tL.x, bR.y}, {tL.x + lLen, bR.y}, IM_COL32(255, 255, 255, 255), 2.5f);
                draw->AddLine({tL.x, bR.y}, {tL.x, bR.y - lLen}, IM_COL32(255, 255, 255, 255), 2.5f);
                draw->AddLine(bR, {bR.x - lLen, bR.y}, IM_COL32(255, 255, 255, 255), 2.5f);
                draw->AddLine(bR, {bR.x, bR.y - lLen}, IM_COL32(255, 255, 255, 255), 2.5f);
            }

            // --- 3D GRADIENT HEALTH BAR ---
            if (Health) {
                int pCur = *(int *)((uintptr_t)values + EntityBase_m_Hp), pMax = *(int *)((uintptr_t)values + EntityBase_m_HpMax);
                if (pMax > 0) {
                    float bH = 16.0f, hpP = (float)pCur / (float)pMax;
                    ImVec2 bgS = {rPos.x - halfWidth, rPos.y + 12}, bgE = {rPos.x + halfWidth, rPos.y + 12 + bH};
                    
                    // Base Colors
                    ImU32 colMain = (hpP >= 0.7f) ? IM_COL32(0, 255, 0, 255) : (hpP >= 0.3f) ? IM_COL32(255, 255, 0, 255) : IM_COL32(255, 0, 0, 255);
                    ImU32 colDark = (hpP >= 0.7f) ? IM_COL32(0, 100, 0, 255) : (hpP >= 0.3f) ? IM_COL32(100, 100, 0, 255) : IM_COL32(100, 0, 0, 255);

                    draw->AddRectFilled(bgS, bgE, IM_COL32(0, 0, 0, 180)); // Background
                    // 3D Gradient Fill
                    draw->AddRectFilledMultiColor({bgS.x, bgS.y}, {bgS.x + ((halfWidth * 2) * hpP), bgE.y}, colMain, colMain, colDark, colDark);
                    draw->AddRect(bgS, bgE, IM_COL32(255, 255, 255, 255), 0, 0, 1.0f); // Border
                    
                    char buf[16]; sprintf(buf, "%.0f%%", hpP * 100);
                    ImVec2 tS = ImGui::CalcTextSize(buf);
                    draw->AddText(NULL, 15.0f, {rPos.x - (tS.x/2), bgS.y + 1}, IM_COL32(255, 255, 255, 255), buf);
                }
            }

            // --- DIAMOND STYLE SKILL CD (PURPLE SKILLS, RED SPELL) ---
            if (SkillCD || SpellCD) {
                auto coolData = getPlayerCoolDown(m_dicPlayerShow->getKeys()[i], values);
                
                // Color Definitions
                ImU32 purpleCol = IM_COL32(128, 0, 128, 255); // Purple for Skills
                ImU32 redCol    = IM_COL32(255, 0, 0, 255);   // Red for Spell

                auto drawDiamond = [&](int val, int off, ImU32 col) {
                    ImVec2 cPos = {rPos.x + 55 + (40 * off), rPos.y - 15};
                    if (val > 0) {
                        std::string s = to_string(val);
                        ImVec2 sz = ImGui::CalcTextSize(s.c_str(), 0, 30);
                        // Text color follows the diamond color
                        draw->AddText(NULL, 30, {cPos.x - (sz.x / 2), rPos.y - 30}, col, s.c_str());
                    } else {
                        // Diamond Shape
                        ImVec2 p[4] = {
                            {cPos.x, cPos.y - 12}, // Top
                            {cPos.x + 12, cPos.y}, // Right
                            {cPos.x, cPos.y + 12}, // Bottom
                            {cPos.x - 12, cPos.y}  // Left
                        };
                        draw->AddConvexPolyFilled(p, 4, col);
                        draw->AddPolyline(p, 4, IM_COL32(255, 255, 255, 200), true, 1.5f);
                    }
                };

                // --- SKILLS (Purple) ---
                if (SkillCD) {
                    drawDiamond(coolData.skill1, 0, purpleCol);
                    drawDiamond(coolData.skill2, 1, purpleCol);
                    drawDiamond(coolData.skill3, 2, purpleCol);
                    if (coolData.skillCount >= 4) drawDiamond(coolData.skill4, 3, purpleCol);
                }
                
                // --- SPELL (Red) ---
                if (SpellCD) {
                    int spOff = (SkillCD) ? coolData.skillCount : 0;
                    drawDiamond(coolData.spell, spOff, redCol);
                }

                float lW = 55 + (40 * ((SkillCD ? coolData.skillCount : 0) + (SpellCD ? 1 : 0)));
                draw->AddLine(rPos, {rPos.x + lW, rPos.y}, IM_COL32(255, 255, 255, 255));
            }
        }
    }
}
