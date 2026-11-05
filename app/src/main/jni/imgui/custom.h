#pragma once

struct sHide {
    float posX = 4.0f;
    float posY = 5.0f;
    float buttonWidth = 200;
    float buttonHeight = 30;
    float windowWidth = 800;
    float windowHeight = 490;
    bool show = true;
    bool button = true;
    bool swap;
};
sHide Hide{0};
std::string CekBool(bool variable){
    if(variable){
        return OBFUSCATE("ACTIVE");
    }else{
        return OBFUSCATE("DEACTIVE");
    }
};
static bool testMode = false;
void D5Gui::HelpMarker(const char* desc)
{
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}
//subtab
bool D5Gui::sub(const char* label, bool selected){
    ImGuiWindow* window = ImGui::GetCurrentWindow();
    if (window->SkipItems)
        return false;

    ImGuiContext& g = *GImGui;
    const ImGuiStyle& style = g.Style;
    const ImGuiID id = window->GetID(label);
    const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);
    draw = ImGui::GetWindowDrawList();

    ImVec2 pos = window->DC.CursorPos;
    ImVec2 size = ImGui::CalcItemSize(ImVec2(115, 27), label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);

    const ImRect bb(pos, pos + size);
    ImGui::ItemSize(size, style.FramePadding.y);
    if (!ImGui::ItemAdd(bb, id))
        return false;

    bool hovered, held;
    bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, NULL);



    if (hovered || held)
        ImGui::SetMouseCursor(7);

    if (selected)
    {
        draw->AddRectFilled(bb.Min, bb.Max, ImColor(30, 30, 30), 5);

    }


    ImGui::RenderText(ImVec2(bb.Min.x + 10, bb.Min.y + (size.y / 2 - label_size.y / 2)), label);


    return pressed;

}
//da?
bool D5Gui::da(const char* label, ImFont* font, bool selected)
{
    ImGuiWindow* window = ImGui::GetCurrentWindow();
    if (window->SkipItems)
        return false;

    ImGuiContext& g = *GImGui;
    const ImGuiStyle& style = g.Style;
    const ImGuiID id = window->GetID(label);
    const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);
    draw = ImGui::GetWindowDrawList();

    ImVec2 pos = window->DC.CursorPos;
    ImVec2 size = ImGui::CalcItemSize(ImVec2(35, 35), label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);

    const ImRect bb(pos, pos + size);
    ImGui::ItemSize(size, style.FramePadding.y);
    if (!ImGui::ItemAdd(bb, id))
        return false;

    bool hovered, held;
    bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, NULL);



    if (hovered || held)
        ImGui::SetMouseCursor(7);

    if (selected)
    {
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(255, 255, 255, 255));
        ImGui::PushFont(font);
        ImGui::RenderText(ImVec2(bb.Min.x + size.x / 2 - label_size.x / 2, bb.Min.y + (size.y / 2 - label_size.y / 2)), label);
        ImGui::PopFont();
        ImGui::PopStyleColor();
    }
    else
    {
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(133 / 255.f, 133 / 255.f, 133 / 255.f, 255));
        ImGui::PushFont(font);
        ImGui::RenderText(ImVec2(bb.Min.x + size.x / 2 - label_size.x / 2, bb.Min.y + (size.y / 2 - label_size.y / 2)), label);
        ImGui::PopFont();
        ImGui::PopStyleColor();
    }

    return pressed;

}
//input
bool D5Gui::InputTextSearch(const char* label, char* buf, size_t buf_size, void* user_data,ImGuiInputTextFlags flags, ImGuiInputTextCallback callback){
    IM_ASSERT(!(flags & ImGuiInputTextFlags_Multiline)); // call InputTextMultiline()
    return ImGui::InputTextEx(label, NULL, buf, (int)buf_size, ImVec2(326, 35), flags, callback, user_data);
}
//tab
bool D5Gui::tab(const char* label, const char* icon, const char* ksub, ImFont* font1, ImFont* font2, ImFont* font3, bool selected)
{
    ImGuiWindow* window = ImGui::GetCurrentWindow();
    if (window->SkipItems)
        return false;



    ImGuiContext& g = *GImGui;
    const ImGuiStyle& style = g.Style;
    const ImGuiID id = window->GetID(label);
    const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);
    const ImVec2 icon_size = ImGui::CalcTextSize(icon, NULL, true);
    const ImVec2 ksub_size = ImGui::CalcTextSize(ksub, NULL, true);

    ImVec2 pos = window->DC.CursorPos;
    ImVec2 size = ImGui::CalcItemSize(ImVec2(115, 27), label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);

    const ImRect bb(pos, pos + size);
    ImGui::ItemSize(size, style.FramePadding.y);
    if (!ImGui::ItemAdd(bb, id))
        return false;

    bool hovered, held;
    bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, NULL);

    if (hovered || held)
        ImGui::SetMouseCursor(7);

    if (selected)
    {
        draw->AddRectFilled(bb.Min, bb.Max, ImColor(30, 30, 30), 5);
        draw->AddCircleFilled(ImVec2(bb.Max.x - 14, bb.Min.y + (size.y / 2)), 7, ImColor(50, 50, 50), 360);
        ImGui::PushFont(font1);
        ImGui::RenderText(ImVec2(bb.Max.x - 13.5f - (ksub_size.x / 2), bb.Min.y + (size.y / 2) - (label_size.y / 2) + 2), ksub);
        ImGui::PopFont();
    }

    ImGui::PushFont(font2);
    ImGui::RenderText(ImVec2(bb.Min.x + 30, bb.Min.y + (size.y / 2) - (label_size.y / 2)), label);
    ImGui::PopFont();
    ImGui::PushFont(font3);
    ImGui::RenderText(ImVec2(bb.Min.x + 10, bb.Min.y + (size.y / 2) - (icon_size.y / 2)), icon);
    ImGui::PopFont();

    return pressed;
}
//tab1
bool D5Gui::tab1(const char* label, bool selected)
{
    ImGuiWindow* window = ImGui::GetCurrentWindow();
    if (window->SkipItems)
        return false;

    ImGuiContext& g = *GImGui;
    const ImGuiStyle& style = g.Style;
    const ImGuiID id = window->GetID(label);
    const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);

    ImVec2 pos = window->DC.CursorPos;
    ImVec2 size = ImGui::CalcItemSize(ImVec2(55, 55), label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);

    const ImRect bb(pos, pos + size);
    ImGui::ItemSize(size, style.FramePadding.y);
    if (!ImGui::ItemAdd(bb, id))
        return false;

    bool hovered, held;
    bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, NULL);

    window->DrawList->AddLine(bb.Max, ImVec2(bb.Min.x, bb.Max.y), ImColor(57, 62, 70), 1.5f);

    if (hovered || held)
        ImGui::SetMouseCursor(7);



    return pressed;
}

bool D5Gui::IsMouseHovered(float x, float y, float w, float h)
{
 ImVec2 Mouse = ImGui::GetMousePos();
 if (Mouse.x > x && Mouse.x < x + w && Mouse.y > y && Mouse.y < y + h) {
     return true;
 }
 return false;
}

void D5Gui::HideMe(ImVec2 Position)
{
    ImVec2 Size(490, 40);
    ImVec2 Pos = ImVec2(Position.x - (Size.x / 2), Position.y);

    ImGuiContext & g = *GImGui;

    ImVec2 Drag = ImGui::GetMouseDragDelta(0);
    if (IsMouseHovered(Pos.x, Pos.y - (Size.y / 2) + Drag.y, Size.x, Size.y)) {
        if (Drag.y < 0) {
            if (g.IO.MouseDown[0] && g.IO.MousePos.y < Pos.y) {
                Hide.show = !Hide.show;
            }
        }
    }

    //ImGui::GetForegroundDrawList()->AddRectFilled(Pos, ImVec2(Pos.x + Size.x, Pos.y + Size.y), ImColor(0, 0, 0, 90), 15);
    //ImGui::GetForegroundDrawList()->AddRect(Pos, ImVec2(Pos.x + Size.x, Pos.y + Size.y), ImColor(225, 125, 0, 190), 15);
}

void decorations()
{
    ImDrawList *draw = ImGui::GetWindowDrawList();
    const ImVec2 pos(ImGui::GetWindowPos().x + 6, ImGui::GetWindowPos().y + 6);

    draw->AddRectFilled(pos, ImVec2(pos.x + 720, pos.y + 510), ImColor(15, 15, 15, 245), 5);
    draw->AddRectFilled(pos, ImVec2(pos.x + 145, pos.y + 510), ImColor(20, 20, 20), 5);
    draw->AddRectFilled(pos, ImVec2(pos.x + 720, pos.y + 60), ImColor(20, 20, 20), 5);
    draw->AddLine(ImVec2(pos.x + 145, pos.y), ImVec2(pos.x + 145, pos.y + 507), ImColor(35, 35, 35));
    draw->AddLine(ImVec2(pos.x, pos.y + 60), ImVec2(pos.x + 720, pos.y + 60), ImColor(35, 35, 35));

    draw->AddCircleFilled(ImVec2(pos.x + 30, pos.y + 10), 4, ImColor(250, 91, 75), 360);
    draw->AddCircleFilled(ImVec2(pos.x + 41, pos.y + 10), 4, ImColor(255, 191, 56), 360);
    draw->AddCircleFilled(ImVec2(pos.x + 52, pos.y + 10), 4, ImColor(108, 240, 83), 360);

    ImGui::PushFont(three);

    draw->AddText(ImVec2(pos.x + 30, pos.y + 33), ImColor(255, 255, 255),"D5");
    draw->AddText(ImVec2(pos.x + 50, pos.y + 33), ImColor(220, 100, 220), "Studio");

    ImGui::PopFont();

    draw->AddLine(ImVec2(pos.x + 25, pos.y + 300), ImVec2(pos.x + 120, pos.y + 300), ImColor(35, 35, 35));

    draw->AddText(ImVec2(pos.x + 25, pos.y + 415), ImColor(88, 88, 88), client.c_str());//name
    draw->AddLine(ImVec2(pos.x + 25, pos.y + 435), ImVec2(pos.x + 120, pos.y + 435), ImColor(35, 35, 35));
    draw->AddText(ImVec2(pos.x + 65, pos.y + 455), ImColor(255, 255, 255), OBFUSCATE("PERSEUS"));//Code Name
    draw->AddText(ImVec2(pos.x + 65, pos.y + 475), ImColor(255, 255, 255), expired.c_str());//expired? OBFUSCATE("3 Days")
    //draw->AddCircleFilled(ImVec2(pos.x + 25, pos.y + 470), 60, ImColor(255, 255, 255), 360);//icon
    DrawIconLogo(2, ImVec2(pos.x + 35, pos.y + 470), 1605, 100, 100, 50, 0, false);

    static char search[64] = { 0 };
    static size_t sz = sizeof(search);

    ImGui::SetCursorPos(ImVec2(175, 20));
    ImGui::InputTextEx("##UPPER", NULL, search, 64, ImVec2(326, 35), NULL);
    draw->AddLine(ImVec2(pos.x + 504, pos.y + 10), ImVec2(pos.x + 504, pos.y + 50), ImColor(35, 35, 35), 1.f);
    draw->AddRect(ImVec2(pos.x + 513, pos.y + 15), ImVec2(pos.x + 594, pos.y + 45), ImColor(35, 35, 35), 9);
    draw->AddLine(ImVec2(pos.x + 553, pos.y + 15), ImVec2(pos.x + 553, pos.y + 45), ImColor(35, 35, 35), 1.f);
    draw->AddLine(ImVec2(pos.x + 602, pos.y + 10), ImVec2(pos.x + 602, pos.y + 50), ImColor(35, 35, 35), 1.f);
    draw->AddRect(ImVec2(pos.x + 611, pos.y + 15), ImVec2(pos.x + 691, pos.y + 45), ImColor(35, 35, 35), 9);
    draw->AddLine(ImVec2(pos.x + 651, pos.y + 15), ImVec2(pos.x + 651, pos.y + 45), ImColor(35, 35, 35), 1.f);


    ImGui::SetCursorPos(ImVec2(523, 20));
    ImGui::BeginGroup();
    {
        if (D5Gui::da("IND", info, 0 == lang)){
            testMode = false;
            lang = 0;
        }
        ImGui::SameLine();
        if (D5Gui::da("ENG", info, 1 == lang)) {
            testMode = true;
            lang = 1;
        }

    }
    ImGui::EndGroup();


    ImGui::SetCursorPos(ImVec2(622, 20));
    ImGui::BeginGroup();
    {
        if (D5Gui::da("A", themefont, 0 == theme))
            theme = 0;
        ImGui::SameLine(0, 1);
        if (D5Gui::da("B", themefont, 1 == theme))
            theme = 1;
    }
    ImGui::EndGroup();
    ImGui::BeginGroup();
    {
        ImGui::SetCursorPos(ImVec2(700, 20));
        if (ImGui::Button("X")) {
            Hide.show = false;
        }
    }

}

void tabs_()
{
    ImGui::PushFont(info);

    ImGui::SetCursorPos(ImVec2(22, 80));

    ImGui::BeginGroup();

    if (D5Gui::tab("INFO", "A", "1", info_little, info, iconfont, 0 == tabs))
        tabs = 0;
    if (D5Gui::tab("VISUAL", "C", "1", info_little, info, iconfont,1 == tabs))
        tabs = 1;
    if (D5Gui::tab("HELPER", "B", "1", info_little, info, iconfont, 2 == tabs))
        tabs = 2;
    if (D5Gui::tab("COMBO", "D", "1", info_little, info, iconfont, 3 == tabs))
        tabs = 3;
    if (D5Gui::tab("ULIMATE", "E", "1", info_little, info, iconfont, 4 == tabs))
        tabs = 4;
    if (D5Gui::tab("ROOMINFO", "F", "1", info_little, info, iconfont, 5 == tabs))
        tabs = 5;
    if (D5Gui::tab("SETTING'S", "G", "1", info_little, info, iconfont, 6 == tabs))
        tabs = 6;

    ImGui::EndGroup();

    ImGui::PopFont();

}

void subtabs_()
{
    if (tabs == 1)
    {
        ImGui::SetCursorPos(ImVec2(22, 310));
        ImGui::BeginGroup();
        {
            if (D5Gui::sub(OBFUSCATE("Main Menu"), 0 == subtabs))
                subtabs = 0;
            if (D5Gui::sub(OBFUSCATE("Extra Menu"), 1 == subtabs))
                subtabs = 1;
        }
        ImGui::EndGroup();
    }

    if (tabs == 3)
    {
        ImGui::SetCursorPos(ImVec2(22, 310));
        ImGui::BeginGroup();
        {
            if (D5Gui::sub(OBFUSCATE("Skill"), 0 == subtabs))
                subtabs = 0;
            if (D5Gui::sub(OBFUSCATE("Auto"), 1 == subtabs))
                subtabs = 1;
            if (D5Gui::sub(OBFUSCATE("Manual"), 2 == subtabs))
                subtabs = 2;
        }
        ImGui::EndGroup();
    }

    if (tabs == 5)
    {
        ImGui::SetCursorPos(ImVec2(22, 310));
        ImGui::BeginGroup();
        {
            if (D5Gui::sub(OBFUSCATE("Table"), 0 == subtabs))
                subtabs = 0;
            if (D5Gui::sub(OBFUSCATE("Screen"), 1 == subtabs))
                subtabs = 1;
        }
        ImGui::EndGroup();
    }
}

void function_()
{
    static bool da = false;
    static int sliderint = 4;
    static int combo = 0;
    if (tabs == 0)
    {
        ImGui::SetCursorPos(ImVec2(175, 85));
        ImGui::BeginGroup();
        ImGui::BeginGroupPanel(OBFUSCATE("INFORMATION"), ImVec2(0.0f, 0.0f));
        ImGui::BeginChild("Information", ImVec2(525, 390));// 1 window = 525
        {
            ImGui::SetCursorPos(ImVec2(5, 0));
            ImGui::BeginGroup();
            ImGui::TableNextColumn();
            ImGui::BeginGroupPanel(GetBit().c_str(), ImVec2(0.0f, 0.0f));
            ImGui::Text(OBFUSCATE("Device : "));
            ImGui::SameLine();
            ImGui::Text(GetModel().c_str());
            ImGui::EndGroupPanel();
            ImGui::Spacing();
            ImGui::TableNextColumn();
            ImGui::BeginGroupPanel(OBFUSCATE("*"), ImVec2(0.0f, 0.0f));
            ImGui::Text(OBFUSCATE("Ip Address : "));
            ImGui::SameLine();
            ImGui::Text(GetIp().c_str());
            ImGui::EndGroupPanel();
            ImGui::Spacing();
            ImGui::TableNextColumn();
            ImGui::BeginGroupPanel(OBFUSCATE("*"), ImVec2(0.0f, 0.0f));
            ImGui::Text(OBFUSCATE("Serial : "));
            ImGui::SameLine();
            ImGui::Text(GetDeviceSerial().c_str());
            ImGui::EndGroupPanel();
            ImGui::Spacing();
            ImGui::EndGroup();
        }
        ImGui::EndChild();
        ImGui::EndGroupPanel();
        ImGui::EndGroup();
    }

    if (tabs == 1)
    {
        if (subtabs == 0)
        {
            ImGui::SetCursorPos(ImVec2(175, 85));
            ImGui::BeginGroup();
            //start
            ImGui::BeginGroupPanel(OBFUSCATE("VISUAL"), ImVec2(0.0f, 0.0f));
            ImGui::BeginChild("Visual", ImVec2(525, 390));// 1 window = 525
            {
                ImGui::SetCursorPos(ImVec2(5, 0));
                ImGui::BeginGroup();
                ImGui::CollapsingHeader("Player ESP");
                {
                    ImGui::BeginTable(OBFUSCATE("#PESP"), 2);
                    {
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Player Box"),&Config.ESP.Player.Box);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Player Line"),&Config.ESP.Player.Line);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Player Name"),&Config.ESP.Player.Name);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Player Hero"),&Config.ESP.Player.Hero);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Player Icon"),&Config.ESP.Player.IconHero);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Player Health"),&Config.ESP.Player.Health);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Player Status"),&Config.ESP.Player.Status);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Player Distance"),&Config.ESP.Player.Distance);
                        ImGui::EndTable();
                        ImGui::Separator();
                    }
                }
                ImGui::CollapsingHeader("Monster ESP");
                {
                    ImGui::BeginTable(OBFUSCATE("#MESP"), 2);
                    {
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Monster Box"),&Config.ESP.Monster.Box);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Monster Health"),&Config.ESP.Monster.Health);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Monster Name"),&Config.ESP.Monster.Name);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Monster Alert"),&Config.ESP.Monster.Alert);
                        ImGui::EndTable();
                        ImGui::Separator();
                    }
                }
                ImGui::CollapsingHeader("360 ESP");
                {
                    ImGui::BeginTable(OBFUSCATE("#360ESP"), 3);
                    {
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Icon Alert"),&Config.ESP.Player.Alert.Icon);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Health Alert"),&Config.ESP.Player.Alert.health);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Distance Alert"),&Config.ESP.Player.Alert.Distance);
                        ImGui::EndTable();
                        ImGui::Separator();
                    }
                }
                ImGui::CollapsingHeader("Camera");
                {
                    ImGui::BeginTable(OBFUSCATE("#cam"), 2);
                    {
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("ESP Minimap"),&Config.Map.active);
                        ImGui::SameLine();
                        D5Gui::HelpMarker(OBFUSCATE("this is a Experimental feature!!!"));
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Health"),&Config.Visual.HealthBar);
                        ImGui::SameLine();
                        D5Gui::HelpMarker(OBFUSCATE("this feature is risk!!"));
                        ImGui::EndTable();
                        ImGui::Separator();
                    }
                }
                ImGui::EndGroup();
            }
            ImGui::EndChild();
            ImGui::EndGroupPanel();
            //end
            ImGui::EndGroup();
        }
        if (subtabs == 1){
            ImGui::SetCursorPos(ImVec2(175, 85));
            ImGui::BeginGroup();
            ImGui::BeginGroupPanel(OBFUSCATE("VISUAL"), ImVec2(0.0f, 0.0f));
            ImGui::BeginChild("EXTRA MENU", ImVec2(525, 390));
            {
                ImGui::CollapsingHeader("Minimap Settings");
                {
                    if (ImGui::BeginTable(OBFUSCATE("#minimap"), 1)) {
                        ImGui::TableNextColumn();
                        ImGui::SliderFloat("Minimap X Position",&Config.Map.minimapPosX,0.0f,static_cast<float>(screenWidth));
                        ImGui::TableNextColumn();
                        ImGui::SliderFloat("Minimap Y Position",&Config.Map.minimapPosY,0.0f,static_cast<float>(screenHeight));
                        ImGui::TableNextColumn();
                        ImGui::SliderFloat("Minimap Width", &Config.Map.Size.minimapWidth,0.0f,static_cast<float>(screenWidth));
                        ImGui::TableNextColumn();
                        ImGui::SliderFloat("Minimap Height", &Config.Map.Size.minimapHeight,0.0f,static_cast<float>(screenHeight));
                        ImGui::EndTable();
                        ImGui::Separator();
                    }
                }
                ImGui::CollapsingHeader("Settings");
                {
                    if (ImGui::BeginTable(OBFUSCATE("#cam"), 2)) {
                        ImGui::TableNextColumn();
                        ImGui::SliderFloat(OBFUSCATE("Drone"), &SetFieldOfView,0,12, "%.2f");
                        ImGui::TableNextColumn();
                        ImGui::SliderFloat(OBFUSCATE("Round"),&Config.ESP.Player.Round, 0, 20,"%.2f");
                        ImGui::EndTable();
                        ImGui::Separator();
                    }
                }
                if (ImGui::CollapsingHeader("Risk Feature")) {
                    if (ImGui::BeginTable(OBFUSCATE("#Risk"), 3)) {
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Unlock Skin"), &Config.Visual.UnlockSkin);
                        ImGui::SameLine();
                        D5Gui::HelpMarker(OBFUSCATE("this feature Maybe risk!!"));
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Minimap"),&Config.Visual.MaphackIcon);
                        ImGui::SameLine();
                        D5Gui::HelpMarker(OBFUSCATE("this feature Maybe risk!!"));
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("CoolDown"),&Config.ESP.Player.CoolDown);
                        ImGui::SameLine();
                        D5Gui::HelpMarker(OBFUSCATE("this feature Maybe risk!!"));
                        ImGui::EndTable();
                        ImGui::Separator();
                    }
                }
            }
            ImGui::EndChild();
            ImGui::EndGroup();
            ImGui::EndGroupPanel();
        }
    }
    if (tabs == 2)
    {
        ImGui::SetCursorPos(ImVec2(175, 85));
        ImGui::BeginGroup();
        //start
        ImGui::BeginGroupPanel(OBFUSCATE("HELPER MENU"), ImVec2(0.0f, 0.0f));
        ImGui::BeginChild("Helper", ImVec2(525, 390));// 1 window = 525
        {
            ImGui::SetCursorPos(ImVec2(5, 0));
            ImGui::BeginGroup();
            ImGui::CollapsingHeader("Auto Aim Skill");
            {
                ImGui::BeginTable(OBFUSCATE("#Skill"), 5);
                {
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("Basic"),&Aim.Helper.Skills.Basic);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("Skill 1"),&Aim.Helper.Skills.Skill1);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("Skill 2"),&Aim.Helper.Skills.Skill2);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("Skill 3"),&Aim.Helper.Skills.Skill3);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("Skill 4"),&Aim.Helper.Skills.Skill4);
                    ImGui::EndTable();
                    ImGui::Separator();
                }
            }
            ImGui::CollapsingHeader("Auto Spell");
            {
                ImGui::BeginTable(OBFUSCATE("#Spell"), 5);
                {
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("Executed"), &Aim.Helper.AutoSpell.Executed);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("FlameShoot"), &Aim.Helper.AutoSpell.FlameShoot);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("Vengeance"), &Aim.Helper.AutoSpell.Vengeance);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("Flicker"), &Aim.Helper.AutoSpell.Flicker);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("Aegis"), &Aim.Helper.AutoSpell.Aegis);
                    ImGui::EndTable();
                    ImGui::Separator();
                }
            }
            ImGui::CollapsingHeader("Ling Manu");
            {
                ImGui::BeginTable(OBFUSCATE("#ling"), 3);
                {
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("Manual Ling"),&Aim.Helper.Priority.ManualTakeSword);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("Auto Ling"),&Aim.Helper.Priority.AutoTakeSword);
                    ImGui::TableNextColumn();
                    ImGui::SliderInt(OBFUSCATE("Speed"),&Aim.Helper.Priority.SpeedControl, 15,45,"%.2fM/s");
                    ImGui::EndTable();
                    ImGui::Separator();
                }
            }
            ImGui::CollapsingHeader("Auto Retribution");
            {
                ImGui::BeginTable(OBFUSCATE("#Retribution"), 3);
                {
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("Buff"),&Aim.Helper.AutoRetribution.Buff);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("Turtle"),&Aim.Helper.AutoRetribution.Turtle);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("Lord"),&Aim.Helper.AutoRetribution.Lord);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("Crab"),&Aim.Helper.AutoRetribution.Crab);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("Litho"),&Aim.Helper.AutoRetribution.Litho);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("Crammer"),&Aim.Helper.AutoRetribution.Crammer);
                    ImGui::EndTable();
                    ImGui::Separator();
                }
            }
            ImGui::CollapsingHeader("Priority");
            {
                ImGui::BeginTable(OBFUSCATE("#ling"), 4);
                {
                    ImGui::TableNextColumn();
                    ImGui::RadioButton(OBFUSCATE("Distance"),&Aim.Helper.Priority.Target, 0);
                    ImGui::TableNextColumn();
                    ImGui::RadioButton(OBFUSCATE("Lowest HP"),&Aim.Helper.Priority.Target, 1);
                    ImGui::TableNextColumn();
                    ImGui::RadioButton(OBFUSCATE("Percentage"),&Aim.Helper.Priority.Target, 2);
                    ImGui::TableNextColumn();
                    ImGui::SliderFloat(OBFUSCATE("RangeFOV"), &RangeFOV, 0,150,"%.2fM");
                    ImGui::EndTable();
                    ImGui::Separator();
                }
            }
            ImGui::EndGroup();
        }
        ImGui::EndChild();
        ImGui::EndGroupPanel();
        //end
        ImGui::EndGroup();
    }
    if (tabs == 3)
    {
        ImGui::SetCursorPos(ImVec2(175, 85));
        if(subtabs == 0){
            ImGui::BeginGroup();
            ImGui::BeginGroupPanel(OBFUSCATE("SKILL 1"), ImVec2(0.0f, 0.0f));
            ImGui::BeginChild("AR MENU", ImVec2(520/2, 370/2));
            {
                ImGui::SetCursorPos(ImVec2(5, 0));
                ImGui::Checkbox(OBFUSCATE("Combo Brody - (S1)"),&Aim.Helper.Combo.Brody);
                ImGui::Checkbox(OBFUSCATE("Combo Franco - (S1)"),&Aim.Helper.Combo.Franco);
                ImGui::Checkbox(OBFUSCATE("Combo Xavier - (S1)"),&Aim.Helper.Combo.Xavier);
                ImGui::Checkbox(OBFUSCATE("Combo Selena - (S1)"),&Aim.Helper.Combo.Selena);
            }
            ImGui::EndChild();
            ImGui::EndGroupPanel();
            ImGui::SameLine(0, 10);
            ImGui::BeginGroupPanel(OBFUSCATE("SKILL 2"), ImVec2(0.0f, 0.0f));
            ImGui::BeginChild("SMG MENU", ImVec2(520/2, 370/2));
            {
                ImGui::SetCursorPos(ImVec2(5, 0));
                ImGui::Checkbox(OBFUSCATE("Combo X-Borg - (S2)"),&Aim.Helper.Combo.Xborg);
                ImGui::Checkbox(OBFUSCATE("Combo Badang - (S2)"),&Aim.Helper.Combo.Badang);
                ImGui::Checkbox(OBFUSCATE("Combo Saber - (S2)"),&Aim.Helper.Combo.Saber);
                ImGui::Checkbox(OBFUSCATE("Combo Gord - (S2)"),&Aim.Helper.Combo.Gord);
            }
            ImGui::EndChild();
            ImGui::EndGroupPanel();
            ImGui::BeginGroupPanel(OBFUSCATE("SKILL 3"), ImVec2(0.0f, 0.0f));
            ImGui::BeginChild("HEALTH MENU", ImVec2(510/2, 370/2));
            {
                ImGui::SetCursorPos(ImVec2(5, 0));
                ImGui::TableNextColumn();
                ImGui::Checkbox(OBFUSCATE("Combo Pharsa - (S3)"),&Aim.Helper.Combo.Pharsa);
                ImGui::Checkbox(OBFUSCATE("Combo Eudora - (S3)"),&Aim.Helper.Combo.Eudora);
                ImGui::Checkbox(OBFUSCATE("Combo Jawhead - (S3)"),&Aim.Helper.Combo.Jawhead);
                ImGui::Checkbox(OBFUSCATE("Combo Martis - (S3)"),&Aim.Helper.Combo.Martis);
            }
            ImGui::EndChild();
            ImGui::EndGroupPanel();
            ImGui::SameLine(0, 10);
            ImGui::BeginGroupPanel(OBFUSCATE("ULTIFLIC"), ImVec2(0.0f, 0.0f));
            ImGui::BeginChild("ACHIVEMENT MENU", ImVec2(510/2, 370/2));
            {
                ImGui::SetCursorPos(ImVec2(5, 0));
                ImGui::Checkbox(OBFUSCATE("Combo Chou - (UF)"),&Aim.Helper.Combo.Chou);
                ImGui::Checkbox(OBFUSCATE("Combo Atlas - (FU)"),&Aim.Helper.Combo.Atlas);
                ImGui::Checkbox(OBFUSCATE("Combo Franco - (FU)"),&Aim.Helper.Combo.Franco1);
                ImGui::Checkbox(OBFUSCATE("Combo Lolita - (FU)"),&Aim.Helper.Combo.Lolita);
            }
            ImGui::EndChild();
            ImGui::EndGroupPanel();
            ImGui::EndGroup();
            ImGui::EndGroupPanel();
        }
        if(subtabs == 1){
            ImGui::BeginGroup();
            ImGui::BeginGroupPanel(OBFUSCATE("MANUAL v1"), ImVec2(0.0f, 0.0f));
            ImGui::BeginChild("AIM MENU1", ImVec2(525, 370/2));
            {
                ImGui::SetCursorPos(ImVec2(5, 0));
                ImGui::BeginGroup();
                ImGui::Checkbox(OBFUSCATE("Manual Combo Gusion"),&Aim.Helper.ManualCombo.Gusion);
                ImGui::Checkbox(OBFUSCATE("Manual Combo Paquito"),&Aim.Helper.ManualCombo.Paquito);
                ImGui::Checkbox(OBFUSCATE("Manual Combo Lunox Light"),&Aim.Helper.ManualCombo.LunoxLight);
                ImGui::Checkbox(OBFUSCATE("Manual Combo Lunox Dark"),&Aim.Helper.ManualCombo.LunoxDark);
                ImGui::Checkbox(OBFUSCATE("Manual Combo Kimmy"),&Aim.Helper.ManualCombo.Kimmy);
                ImGui::Checkbox(OBFUSCATE("Manual Combo Pharsa"),&Aim.Helper.ManualCombo.Pharsa);
                ImGui::EndGroup();
            }
            ImGui::EndChild();
            ImGui::EndGroupPanel();
            ImGui::BeginGroupPanel(OBFUSCATE("MANUAL v2"), ImVec2(0.0f, 0.0f));
            ImGui::BeginChild("AIM SETTING1", ImVec2(525, 370/2));
            {
                ImGui::SetCursorPos(ImVec2(5, 0));
                ImGui::BeginGroup();
                ImGui::Checkbox(OBFUSCATE("Manual Combo Kagura"),&Aim.Helper.ManualCombo.Kagura);
                ImGui::Checkbox(OBFUSCATE("Manual Combo Eudora"),&Aim.Helper.ManualCombo.Eudora);
                ImGui::Checkbox(OBFUSCATE("Manual Combo Vale"),&Aim.Helper.ManualCombo.Vale);
                ImGui::Checkbox(OBFUSCATE("Manual Combo Edith"),&Aim.Helper.ManualCombo.Edith);
                ImGui::Checkbox(OBFUSCATE("Manual Combo Hayabusa"),&Aim.Helper.ManualCombo.Hayabusa);
                ImGui::Checkbox(OBFUSCATE("Manual Combo Ruby"),&Aim.Helper.ManualCombo.Ruby);
                ImGui::EndGroup();
            }
            ImGui::EndChild();
            ImGui::EndGroupPanel();
            ImGui::EndGroup();
        }
        if(subtabs == 2){
            ImGui::BeginGroup();
            ImGui::BeginGroupPanel(OBFUSCATE("AUTOMATIC v1"), ImVec2(0.0f, 0.0f));
            ImGui::BeginChild("AIM MENU", ImVec2(525, 370/2));
            {
                ImGui::SetCursorPos(ImVec2(5, 0));
                ImGui::BeginGroup();
                ImGui::Checkbox(OBFUSCATE("Auto Combo Gusion"),&Aim.Helper.AutoCombo.Gusion);
                ImGui::Checkbox(OBFUSCATE("Auto Combo Paquito"),&Aim.Helper.AutoCombo.Paquito);
                ImGui::Checkbox(OBFUSCATE("Auto Combo Lunox Light"),&Aim.Helper.AutoCombo.LunoxLight);
                ImGui::Checkbox(OBFUSCATE("Auto Combo Lunox Dark"),&Aim.Helper.AutoCombo.LunoxDark);
                ImGui::Checkbox(OBFUSCATE("Auto Combo Kimmy"),&Aim.Helper.AutoCombo.Kimmy);
                ImGui::Checkbox(OBFUSCATE("Auto Combo Pharsa"),&Aim.Helper.AutoCombo.Pharsa);
                ImGui::EndGroup();
            }
            ImGui::EndChild();
            ImGui::EndGroupPanel();
            ImGui::BeginGroupPanel(OBFUSCATE("AUTOMATIC v2"), ImVec2(0.0f, 0.0f));
            ImGui::BeginChild("AIM SETTING", ImVec2(525, 370/2));
            {
                ImGui::SetCursorPos(ImVec2(5, 0));
                ImGui::BeginGroup();
                ImGui::Checkbox(OBFUSCATE("Auto Combo Kagura"),&Aim.Helper.AutoCombo.Kagura);
                ImGui::Checkbox(OBFUSCATE("Auto Combo Eudora"),&Aim.Helper.AutoCombo.Eudora);
                ImGui::Checkbox(OBFUSCATE("Auto Combo Vale"),&Aim.Helper.AutoCombo.Vale);
                ImGui::Checkbox(OBFUSCATE("Auto Combo Edith"),&Aim.Helper.AutoCombo.Edith);
                ImGui::Checkbox(OBFUSCATE("Auto Combo Hayabusa"),&Aim.Helper.AutoCombo.Hayabusa);
                ImGui::Checkbox(OBFUSCATE("Auto Combo Ruby"),&Aim.Helper.AutoCombo.Ruby);
                ImGui::EndGroup();
            }
            ImGui::EndChild();
            ImGui::EndGroupPanel();
            ImGui::EndGroup();
        }
    }
    if (tabs == 4)
    {
        ImGui::SetCursorPos(ImVec2(175, 85));
        ImGui::BeginGroup();
        ImGui::BeginGroupPanel(OBFUSCATE("ULTIMATE"), ImVec2(0.0f, 0.0f));
        ImGui::BeginChild("MEMORY MENU : ", ImVec2(525, 405));
        {
            ImGui::SetCursorPos(ImVec2(5, 0));
            ImGui::BeginChild("Auto menu", ImVec2(525, 300/2));
            {
                ImGui::SetCursorPos(ImVec2(5, 0));
                ImGui::CollapsingHeader("AUTO ULTIMATE");
                {
                    ImGui::BeginTable(OBFUSCATE("#ulti"), 2);
                    {
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Auto Ultimate Beatrix"), &Aim.Helper.AutoUltimate.Beatrix);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Auto Ultimate Xavier"), &Aim.Helper.AutoUltimate.Xavier);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Auto Ultimate Balmond"), &Aim.Helper.AutoUltimate.Balmond);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Auto Ultimate Layla"), &Aim.Helper.AutoUltimate.Layla);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Auto Ultimate Moskov"), &Aim.Helper.AutoUltimate.Moskov);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Auto Ultimate Nana"), &Aim.Helper.AutoUltimate.Nana);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Auto Ultimate Gord"), &Aim.Helper.AutoUltimate.Gord);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Auto Ultimate Hilda"), &Aim.Helper.AutoUltimate.Hilda);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Auto Ultimate Martis"), &Aim.Helper.AutoUltimate.Martis);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Auto Ultimate Thamuz"), &Aim.Helper.AutoUltimate.Thamuz);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Auto Ultimate Argus"), &Aim.Helper.AutoUltimate.Argus);
                        ImGui::EndTable();
                        ImGui::Separator();
                    }
                }
            }
            ImGui::EndChild();

            ImGui::BeginChild("Auto steal", ImVec2(525, 300/2));
            {
                ImGui::SetCursorPos(ImVec2(5, 0));
                ImGui::CollapsingHeader("AUTO STEAL");
                {
                    ImGui::BeginTable(OBFUSCATE("#steal"), 2);
                    {
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Steal Using Ultimate Moskov"), &Aim.Helper.AutoSteal.Moskov);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Steal Using Ultimate Xavier"), &Aim.Helper.AutoSteal.Xavier);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Steal Using Ultimate Layla"), &Aim.Helper.AutoSteal.Layla);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Steal Using Ultimate Beatrix [ SNIPER ]"), &Aim.Helper.AutoSteal.Beatrix);
                        ImGui::EndTable();
                        ImGui::Separator();
                    }
                }
            }
            ImGui::EndChild();

            ImGui::BeginChild("Steal SETTING2", ImVec2(525, 50));
            {
                ImGui::SetCursorPos(ImVec2(5, 0));
                ImGui::CollapsingHeader("TARGET STEAL");
                {
                    ImGui::BeginTable(OBFUSCATE("#stealset"), 2);
                    {
                        ImGui::TableNextColumn();
                        ImGui::RadioButton(OBFUSCATE("Turtle"), &Aim.Helper.Settings.Target, 0);
                        ImGui::TableNextColumn();
                        ImGui::RadioButton(OBFUSCATE("Lord"), &Aim.Helper.Settings.Target, 1);
                        ImGui::EndTable();
                        ImGui::Separator();
                    }
                }
            }
            ImGui::EndChild();
        }
        ImGui::EndChild();
        ImGui::EndGroupPanel();
        ImGui::EndGroup();
    }
    if(tabs == 5){
        if(subtabs == 0){
            ImGui::SetCursorPos(ImVec2(175, 85));
            ImGui::BeginGroup();
            //start
            ImGui::BeginGroupPanel(OBFUSCATE("ROOM INFO TABLE"), ImVec2(0.0f, 0.0f));
            ImGui::BeginChild("roominfo", ImVec2(525, 390));// 1 window = 525
            {
                ImGui::SetCursorPos(ImVec2(5, 0));
                ImGui::BeginGroup();
                RoomInfoList();
                ImGui::TextColored(ImVec4(0.0f, 0.8f, 1.0f, 1.0f), "Team");
                if (ImGui::BeginTable("##Team", 7, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersInner)) {
                    ImGui::TableSetupColumn("Name");
					ImGui::TableSetupColumn("ID");
                    ImGui::TableSetupColumn("Verified");
                    ImGui::TableSetupColumn("Rank");
                    ImGui::TableSetupColumn("Star");
					ImGui::TableSetupColumn("Hero");
					ImGui::TableSetupColumn("Spell");
                    ImGui::TableHeadersRow();
                    for (int row = 0; row < 5; row++) {
                        ImGui::TableNextRow();
                        for (int column = 0; column < 7; column++) {
                            ImGui::TableSetColumnIndex(column);
                            char buf[32];
                            if (column == 0) {
                                sprintf(buf, "%s", RoomInfo.PlayerB[row].Name.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 1) {
                                sprintf(buf, "%s", RoomInfo.PlayerB[row].UserID.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 2) {
                                sprintf(buf, "%s", RoomInfo.PlayerB[row].Verified.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 3) {
                                sprintf(buf, "%s", RoomInfo.PlayerB[row].Rank.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 4) {
                                sprintf(buf, "%s", RoomInfo.PlayerB[row].Star.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 5) {
                                RoomHero(RoomInfo.PlayerB[row].HeroID);
                            } else if (column == 6) {
                                RoomSpell(RoomInfo.PlayerB[row].Spell);
                            }
                        }
                    }
                    ImGui::EndTable();
                }
                ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "Enemy");
                if (ImGui::BeginTable("##Enemy", 7, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersInner)) {
                    ImGui::TableSetupColumn("Name");
					ImGui::TableSetupColumn("ID");
                    ImGui::TableSetupColumn("Verified");
                    ImGui::TableSetupColumn("Rank");
                    ImGui::TableSetupColumn("Star");
					ImGui::TableSetupColumn("Hero");
					ImGui::TableSetupColumn("Spell");
                    ImGui::TableHeadersRow();
                    for (int row = 0; row < 5; row++) {
                        ImGui::TableNextRow();
                        for (int column = 0; column < 7; column++) {
                            ImGui::TableSetColumnIndex(column);
                            char buf[32];
                            if (column == 0) {
                                sprintf(buf, "%s", RoomInfo.PlayerR[row].Name.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 1) {
                                sprintf(buf, "%s", RoomInfo.PlayerR[row].UserID.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 2) {
                                sprintf(buf, "%s", RoomInfo.PlayerR[row].Verified.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 3) {
                                sprintf(buf, "%s", RoomInfo.PlayerR[row].Rank.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 4) {
                                sprintf(buf, "%s", RoomInfo.PlayerR[row].Star.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 5) {
                                RoomHero(RoomInfo.PlayerR[row].HeroID);
                            } else if (column == 6) {
                                RoomSpell(RoomInfo.PlayerR[row].Spell);
                            }
                        }
                    }
                    ImGui::EndTable();
                }
                ImGui::EndGroup();
            }
            ImGui::EndChild();
            ImGui::EndGroupPanel();
            //end
            ImGui::EndGroup();
        }
        if(subtabs == 1){
            ImGui::SetCursorPos(ImVec2(175, 85));
            ImGui::BeginGroup();
            ImGui::BeginGroupPanel(OBFUSCATE("ROOM INFO SCREEN"), ImVec2(0.0f, 0.0f));
            ImGui::BeginChild("--a-", ImVec2(525, 390));
            {
                ImGui::CollapsingHeader("Click");
                {
                    if (ImGui::BeginTable(OBFUSCATE("#roomscreen"), 1)) {
                        ImGui::TableNextColumn();
                        if (ImGui::Button(CekBool(Esp.RoomInfo.Screen).c_str(), ImVec2(ImGui::GetContentRegionAvailWidth(), 0))) {
                            Esp.RoomInfo.Screen = !Esp.RoomInfo.Screen;
                        }
                        ImGui::EndTable();
                        ImGui::Separator();
                    }
                }
                ImGui::CollapsingHeader("Settings");
                {
                    if (ImGui::BeginTable(OBFUSCATE("#room setting"), 5)) {
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Name"), &Esp.RoomInfo.Name);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Rank"), &Esp.RoomInfo.Rank);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Hero"),&Esp.RoomInfo.Hero);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Team"),&Esp.RoomInfo.Team);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(OBFUSCATE("Spell"),&Esp.RoomInfo.Spell);
                        ImGui::EndTable();
                        ImGui::Separator();
                    }
                }
            }
            ImGui::EndChild();
            ImGui::EndGroup();
            ImGui::EndGroupPanel();
        }
    }
    if(tabs == 6){
        ImGui::SetCursorPos(ImVec2(175, 85));
        ImGui::BeginGroup();
        ImGui::BeginGroupPanel(OBFUSCATE("HIDE MODE"), ImVec2(0.0f, 0.0f));
        ImGui::BeginChild("--a-", ImVec2(525, 390));
        {
            ImGui::CollapsingHeader("Hide Mode Button");
            {
                if (ImGui::BeginTable(OBFUSCATE("#HideMode"), 1)) {
                    ImGui::TableNextColumn();
                    if (ImGui::Button(CekBool(Hide.button).c_str(), ImVec2(ImGui::GetContentRegionAvailWidth(), 0))) {
                        Hide.button = !Hide.button;
                        if(Hide.button){
                            Hide.swap = !Hide.swap;
                        }
                    }
                    ImGui::EndTable();
                    ImGui::Separator();
                }
            }
            ImGui::CollapsingHeader("Hide Mode Gesture");
            {
                if (ImGui::BeginTable(OBFUSCATE("#HideMode"), 1)) {
                    ImGui::TableNextColumn();
                    if (ImGui::Button(CekBool(Hide.swap).c_str(), ImVec2(ImGui::GetContentRegionAvailWidth(), 0))) {
                        Hide.swap = !Hide.swap;
                        if(Hide.swap){
                            Hide.button = !Hide.button;
                        }
                    }
                    ImGui::EndTable();
                    ImGui::Separator();
                }
            }
        }
        ImGui::EndChild();
        ImGui::EndGroup();
        ImGui::EndGroupPanel();
    }
}
