bool showMenu = true;
bool bFullChecked = false;

static bool MinimapSetting;

std::string toastsaveload = OBFUSCATE("");
std::string toastsaveload1 = OBFUSCATE("");

bool bShowMenu = true;

void ModernRadioButton(const char* label, int* v, int button_value) {

    ImGui::PushStyleColor(ImGuiCol_CheckMark, ImVec4(0.0f, 1.0f, 0.0f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.0f, 0.2f, 0.0f, 0.9f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0.0f, 0.4f, 0.0f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0.0f, 0.6f, 0.0f, 1.0f));
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 10.0f);
    ImGui::RadioButton(label, v, button_value);
    ImGui::PopStyleVar();
    ImGui::PopStyleColor(4);
}

void HideMenu(bool& bShow) 
{
    if (bShow) {
        ImGui::OpenPopup("ConfirmHide");
    }

    ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    if (ImGui::BeginPopupModal("ConfirmHide", 0, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse)) {
        ImGui::Text("Are you sure you want to hide the menu?");
        if (ImGui::Button("Yes", ImVec2(ImGui::GetContentRegionAvail().x / 2, 0))) {
            bShowMenu = false;
            bShow = false;
            ImGui::CloseCurrentPopup();
        }
        ImGui::SameLine();
        if (ImGui::Button("No", ImVec2(ImGui::GetContentRegionAvail().x, 0))) {
            bShow = false;
            ImGui::CloseCurrentPopup();
        }
        ImGui::EndPopup();
    }
}

static bool Show_Window = true;

void ShowMenu() 
{
    bFullChecked = true;

    const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x + 650, main_viewport->WorkPos.y + 20), ImGuiCond_FirstUseEver);

    // FIXED SIZE: Dito natin ise-set ang size para maging Box/Rectangle at hindi na gagalaw
    // Pwede mong palitan ang 450 (lapad) at 600 (taas) base sa trip mo
    ImGui::SetNextWindowSize(ImVec2(550, 600), ImGuiCond_FirstUseEver);

    ImGuiIO& io = ImGui::GetIO();

    static float window_scale;
    if (window_scale <= 0.0f) window_scale = 1.0f; 
    io.FontGlobalScale = window_scale;

    static bool isLogin = false, isSave = false;
    static char s[64] = ""; 
    static std::string err = ""; 

    // --- AUTO LOGIN LOGIC ---
    static bool isFirstRun = true;
    if (isFirstRun) {
        SharedPreferences sharedPref(GetJNIEnv(g_vm), OBFUSCATE("divarvian_sharedpref"));
        std::string savedKey = sharedPref.getString(OBFUSCATE("key"));
        if (!savedKey.empty()) {
            memset(s, 0, sizeof(s));
            strncpy(s, savedKey.c_str(), sizeof(s) - 1);
            err = Login(s);
            if (err == "OK") {
                isLogin = (bValid && g_Auth == g_Token);
                isSave = true;
            }
        }
        isFirstRun = false;
    }

    if (isLogin && !isSave) {
        SharedPreferences sharedPref(GetJNIEnv(g_vm), OBFUSCATE("divarvian_sharedpref"));
        SharedPreferences_Editor editor = sharedPref.edit();
        editor.putString(OBFUSCATE("key"), s);
        editor.commit();
        isSave = true;
    }

    static bool isPopUpHide = false;
    HideMenu(isPopUpHide);
    
    // TINANGGAL ANG AlwaysAutoResize flag para hindi na lumiliit bigla
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_None;

    if (isLogin && title != "") {
        bFullChecked = true;
    }
    
    std::string strTittle(std::string(OBFUSCATE("SPACE MLBB | SIMPLE VERSION")).append(tittle.c_str() + std::string(ABI)));

    if (ImGui::Begin(strTittle.c_str(), &bShowMenu, window_flags)) {
        if (!isLogin) {
            ImGui::BeginGroupPanel(OBFUSCATE(" Login Key Page "), ImVec2(ImGui::GetContentRegionAvail().x, 0));
            {
                ImGui::PushItemWidth(-1);
                ImGui::InputText(OBFUSCATE("##licencelogin"), s, sizeof s);
                ImGui::PopItemWidth();

                ImGui::Spacing();
                if (ImGui::Button(OBFUSCATE("Paste"), ImVec2(ImGui::GetContentRegionAvail().x / 2.1f, 0))) {
                    auto key = getClipboardText(g_vm);
                    strncpy(s, key.c_str(), sizeof s);
                }
                ImGui::SameLine();
                if (ImGui::Button(OBFUSCATE("Load"), ImVec2(ImGui::GetContentRegionAvail().x, 0))) {
                    SharedPreferences sharedPref(GetJNIEnv(g_vm), OBFUSCATE("divarvian_sharedpref"));
                    auto key = sharedPref.getString(OBFUSCATE("key"));
                    strncpy(s, key.c_str(), sizeof s);
                }

                if (ImGui::Button(OBFUSCATE("Login"), ImVec2(ImGui::GetContentRegionAvail().x, 0))) {
                    err = Login(s);
                    if (err == "OK") {
                        isLogin = bValid && g_Auth == g_Token;
                    }
                }

                if (!err.empty() && err != std::string(OBFUSCATE("OK"))) {
                    ImGui::Text(OBFUSCATE("Error: %s"), err.c_str());
                }
                ImGui::EndGroupPanel();
            }
        } else {
            // LOGIN SUCCESS - START TAB BAR
            if (ImGui::BeginTabBar("##Tabs")) {

                // --- TAB: HOME ---
                if (ImGui::BeginTabItem("HOME")) {
                    ImGui::BeginGroupPanel("Menu Setting", ImVec2(0.0f, 0.0f));
                    {
                        static int e = 0;
                        ImGui::BeginGroupPanel("Choose Themes", ImVec2(0.0f, 0.0f));
                        {
                            ImGui::RadioButton(" PURPLE ", &e, 1); ImGui::SameLine();
                            ImGui::RadioButton(" RED ", &e, 2); ImGui::SameLine();
                            ImGui::RadioButton(" LIGHT ", &e, 3);
                            switch (e) {
                                case 1: ImGui::StyleColorsClassic(); break;
                                case 2: ImGui::StyleColorsDark(); break;
                                case 3: ImGui::StyleColorsLight(); break;
                            }
                        }
                        ImGui::EndGroupPanel();
                        
                        ImGui::BeginGroupPanel("Window Size", ImVec2(0.0f, 0.0f));
                        {
                            ImGui::PushItemWidth(-1);
                            ImGui::SliderFloat("##Scale", &window_scale, 0.5f, 1.5f, "%.1f");
                            ImGui::PopItemWidth();
                        }
                        ImGui::EndGroupPanel();
  
                        if (ImGui::Button("Hide Menu", ImVec2(ImGui::GetContentRegionAvail().x, 0))) { isPopUpHide = true; }
                        if (ImGui::Button("Logout", ImVec2(ImGui::GetContentRegionAvail().x, 0))) { isLogin = false; isSave = false; }
                    }
                    
                    ImGui::EndGroupPanel();

                    if (selectedFeature == 1 || selectedFeature == 2) {
                        if (ImGui::Button("Save Setting", ImVec2(ImGui::GetContentRegionAvail().x / 2.1f, 0))) {
                            SharedPreferences sharedPref(GetJNIEnv(g_vm), "divarvian_sharedpref");
                            SharedPreferences_Editor editor = sharedPref.edit();
                            editor.putFloat("SetFieldOfView", SetFieldOfView);
                            
                            // --- PLAYER ESP SAVE ---
                            editor.putBoolean("Line", Line); 
                            editor.putBoolean("Box", Box);
                            editor.putBoolean("Health", Health);
                            editor.putBoolean("Name", PlayerName);
                            editor.putBoolean("Name", HeroName);

                            // --- MONSTER ESP SAVE ---
                            editor.putBoolean("MinionDot", MinionDot);
                            editor.putBoolean("MonsterBox", MonsterBox);
                            editor.putBoolean("MonsterHealth",MonsterHealth);
                            editor.putBoolean("MonsterHealth",JungleDot);
                            editor.putBoolean("MonsterHealth",MonsterName);
                    
                            editor.commit(); toastsaveload = "Save Config Success";
                        }
                        ImGui::SameLine();
                        if (ImGui::Button("Load Setting", ImVec2(ImGui::GetContentRegionAvail().x, 0))) {
                            SharedPreferences sharedPref(GetJNIEnv(g_vm), "divarvian_sharedpref");
                            SetFieldOfView = sharedPref.getFloat("SetFieldOfView");
                            
                            // --- PLAYER ESP LOAD ---
                            Line = sharedPref.getBoolean("Line"); 
                            Box = sharedPref.getBoolean("Box");
                            Health = sharedPref.getBoolean("Health");
                            PlayerName = sharedPref.getBoolean("Name");
                            HeroName = sharedPref.getBoolean("Name");

                            // --- MONSTER ESP LOAD ---
                            MinionDot = sharedPref.getBoolean("MinionDot");
                            MonsterBox = sharedPref.getBoolean("MonsterBox");
                            MonsterHealth = sharedPref.getBoolean("Health");
                            MonsterName = sharedPref.getBoolean("Health");
                            JungleDot = sharedPref.getBoolean("Health");
                        
                            toastsaveload = "Load Config Success";
                        }
                        ImGui::TextColored(ImVec4(0,1,0,1), "%s", toastsaveload.c_str());
                    }
                    
                    ImGui::Spacing();
                    ImGui::Separator();
                    ImGui::TextDisabled("(C) 2026 PROJECT SPACE MLBB");
                    
                    ImGui::EndTabItem();
                }
                // --- TAB: VISUAL ---
                if (ImGui::BeginTabItem("VISUAL")) {
                    // --- START OF COLUMNS ---
                    ImGui::Columns(3, NULL, false); 

                    // COLUMN 1: PLAYER ESP
                    ImGui::BeginGroupPanel(OBFUSCATE("PLAYER ESP"), ImVec2(-1.0f, 0.0f));
                    {
                        ImGui::Checkbox(OBFUSCATE("Player Line"), &Line);
                        ImGui::Checkbox(OBFUSCATE("Player Box"), &Box);
                        ImGui::Checkbox(OBFUSCATE("Player Health"), &Health);
                        ImGui::Checkbox(OBFUSCATE("Player Name"), &PlayerName);
                        ImGui::Checkbox(OBFUSCATE("Hero Name"), &HeroName);
                    }
                    ImGui::EndGroupPanel();

                    ImGui::NextColumn();

                    // COLUMN 2: MONSTER ESP
                    ImGui::BeginGroupPanel(OBFUSCATE("MONSTER ESP"), ImVec2(-1.0f, 0.0f));
                    {
                        ImGui::Checkbox(OBFUSCATE("Minion Dot"), &MinionDot);
                        ImGui::Checkbox(OBFUSCATE("Jungle Dot"), &JungleDot);
                        ImGui::Checkbox(OBFUSCATE("Monster Box"), &MonsterBox);
                        ImGui::Checkbox(OBFUSCATE("Monster Health"), &MonsterHealth);
                        ImGui::Checkbox(OBFUSCATE("Monster Name"), &MonsterName);
                    }
                    ImGui::EndGroupPanel();
                    
                    ImGui::NextColumn(); 
                    
                    ImGui::BeginGroupPanel(OBFUSCATE("OTHER ESP"), ImVec2(-1.0f, 0.0f));
                    {
                        ImGui::Checkbox(OBFUSCATE("Spell CD"), &SpellCD);
                        ImGui::Checkbox(OBFUSCATE("Skill CD"), &SkillCD);
                    }
                    ImGui::EndGroupPanel();

                    ImGui::Columns(1);
                    
                    ImGui::BeginGroupPanel(" Drone View", ImVec2(0.0f, 0.0f));
                    {
                        ImGui::Spacing();
                        ImGui::Text(OBFUSCATE("Drone Horizontal:"));
                        ImGui::PushItemWidth(-1);
                        ImGui::SliderFloat(OBFUSCATE("##Drone Horizontal"), &SetFieldOfView, 0, 30, "%.1f");
                        ImGui::PopItemWidth();
                    }
                    ImGui::EndGroupPanel();
                    
                    ImGui::Spacing();
                    ImGui::Separator();
                    ImGui::TextDisabled("(C) 2026 PROJECT SPACE MLBB");
                    
                    ImGui::EndTabItem();
                }
                
                // --- TAB: MOD INFO ---
                if (ImGui::BeginTabItem("MOD INFO")) {
                    float time = ImGui::GetTime() * 2.0f;
                    ImVec4 rgbCol = ImVec4((sinf(time)*0.5f)+0.5f, (sinf(time+2.094f)*0.5f)+0.5f, (sinf(time+4.188f)*0.5f)+0.5f, 1.0f);

                    ImGui::BeginGroupPanel("INFO", ImVec2(-1.0f, 0.0f));
                    {
                        ImGui::Spacing();
                        ImGui::TextColored(rgbCol, " [!] MOD DETAILS");
                        ImGui::Separator();
                        
                        ImGui::Columns(2, "mod_info_cols", false);
                        ImGui::SetColumnWidth(0, 120.0f);
                        
                        ImGui::Text("GAME:");     ImGui::NextColumn(); ImGui::TextColored(ImVec4(1, 1, 0, 1), "%s", gamemod.c_str()); ImGui::NextColumn();
                        ImGui::Text("VERSION:");  ImGui::NextColumn(); ImGui::Text("%s", Version.c_str()); ImGui::NextColumn();
                        ImGui::Text("PATCH:");    ImGui::NextColumn(); ImGui::Text("%s", Patch.c_str()); ImGui::NextColumn();
                        ImGui::Text("STATUS:");   ImGui::NextColumn(); ImGui::TextColored(ImVec4(0, 1, 0, 1), "%s", Status.c_str()); ImGui::NextColumn();
                        ImGui::Text("DEVELOPER:"); ImGui::NextColumn(); ImGui::TextColored(rgbCol, "%s", Devv1.c_str()); ImGui::NextColumn();
                        
                        ImGui::Columns(1);
                        ImGui::Spacing();
                        ImGui::Separator();
                        ImGui::Spacing();

                        ImGui::TextColored(rgbCol, " [!] USER & LICENSE");
                        ImGui::Separator();
                        
                        ImGui::Columns(2, "user_info_cols", false);
                        ImGui::SetColumnWidth(0, 120.0f);
                        
                        ImGui::Text("DEVICE ID:");  ImGui::NextColumn(); ImGui::Text("%s", DeviceID.c_str()); ImGui::NextColumn();
                        ImGui::Text("BRAND:");      ImGui::NextColumn(); ImGui::Text("%s", DeviceBrand.c_str()); ImGui::NextColumn();
                        ImGui::Text("LICENSE EXPIRY:"); ImGui::NextColumn(); ImGui::TextColored(ImVec4(1, 0, 0, 1), "%s", EXP.c_str()); ImGui::NextColumn();
                        
                        ImGui::Columns(1);
                        ImGui::Spacing();
                    }
                    ImGui::EndGroupPanel();
                    
                    ImGui::Spacing();
                    ImGui::Separator();
                    ImGui::TextDisabled("(C) 2026 PROJECT SPACE MLBB");
                    
                    ImGui::EndTabItem();
                }

                ImGui::EndTabBar(); 
            }
        }
    }
    ImGui::End();
}

