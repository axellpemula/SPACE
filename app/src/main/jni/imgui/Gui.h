#pragma once
ImFont* iconfont = nullptr;
ImFont* themefont = nullptr;
ImFont* info = nullptr;

ImFont* info_little = nullptr;
ImFont* two = nullptr;
ImFont* three = nullptr;
ImFont* tabsf = nullptr;
ImFont* ee = nullptr;
ImVec2 pos;
ImDrawList* draw;

static int tabs = 0;
static int subtabs = 0;
static int lang = 0;
static int theme = 0;
float dpi_scale = 1.f;

static bool show;
static bool Feu;

class D5Gui{
public:
    //subtab
    static bool sub(const char* label, bool selected);

    //InputText
    static bool InputTextSearch(const char* label, char* buf, size_t buf_size, void* user_data, ImGuiInputTextFlags flags, ImGuiInputTextCallback callback);

    //da
    static bool da(const char* label, ImFont* font, bool selected);

    //tab
    static bool tab(const char* label, const char* icon, const char* ksub, ImFont* font1, ImFont* font2, ImFont* font3, bool selected);

    //tab1
    static bool tab1(const char* label, bool selected);

    //help
    static void HelpMarker(const char* desc);

    //cek hovered
    static bool IsMouseHovered(float x, float y, float w, float h);

    //functon Hide
    static void HideMe(ImVec2 Position);
};
