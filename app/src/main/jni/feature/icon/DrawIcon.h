/** xhasbi **/
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "IconList.h"
#include "base64.hpp"
//
char pathPkgMlbb[100];

void writeToFile(std::string dir, std::string buf) {
    std::ofstream os(dir.c_str(), std::ios::trunc);
    os.write(buf.c_str(), buf.length());
    os.close();
}

std::string MonsterAlertIcon(int Id) {
    std::string strICMonsterAlert;
    switch(Id) {
	default:
	strICMonsterAlert += MonsterAlertList[Id];
	}
	return strICMonsterAlert;
}

std::string MonsterAssets(int Id) {
    std::string strICMonsterIcon;
    switch(Id) {
	default:
	strICMonsterIcon += MonsterList[Id];
	}
	return strICMonsterIcon;
}



std::string IconAssets(int Id) {
    std::string strICHero;
    switch(Id) {
	default:
	strICHero += iconHeroList[Id];
	}
	return strICHero;
}

std::string SpellAssets(int Id) {
    std::string strICHero;
    switch(Id) {
	default:
	strICHero += iconSpellList[Id];
	}
	return strICHero;
}

std::string CountryIDtoList(int Id) {
std::string strICCountry;    
switch(Id) {
    default:
    strICCountry +=  CountryList[Id];   
 }
return strICCountry;}

std::string RankAssets(const int uiRankLevel) {
    std::string strICHero;
    strICHero += iconRankList[uiRankLevel];
    return strICHero;
}

bool LoadTextureFromFile(const char* filename, Icon* Image) {
    int image_width = 0;
    int image_height = 0;
    int n;
    unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
    if (image_data == NULL)
        return false;

    GLuint image_texture;
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);

    Image->texture = image_texture;
    Image->width = image_width;
    Image->height = image_height;

    return true;
}

bool CekFolder(const char *packageName){
    std::ifstream input_file("/data/data/" + std::string(packageName) + "/.bak");
    return input_file.is_open();
}



bool AttachCountryDone;
void AttachCountry() {
    int Ctry = sizeof(CountryList) / sizeof(CountryList[0]);
    for (int a = 0;a < Ctry;a++) {
		//for (int i = 0;i < Ctry;i++) {
        Icon Test;
        std::string packageName = "com.mobile.legends";
        string Path = "/data/data/" + packageName + "/files/";
        Path += to_string(a);
        writeToFile(Path, base64::from_base64(CountryIDtoList(a)));
	    //Path += to_string(i);
	    //writeToFile(Path, base64::from_base64(CountryIDtoList(i)));
        Test.IsValid = LoadTextureFromFile(Path.c_str(), &Test);
        std::remove(Path.c_str());
        CountryIcon.push_back(Test);
    }
}

bool AttachMonsterDone;
void AttachMonster() {
    int Ctry = sizeof(MonsterList) / sizeof(MonsterList[0]);
    for (int a = 0; a < Ctry; a++) {
        Icon Test;
        std::string packageName = "com.mobile.legends";
        if(!CekFolder("com.mobile.legends")) packageName = "com.mobilelegends.hwag";
        string Path = "/data/data/" + packageName + "/files/";
        Path += to_string(a);
        writeToFile(Path, base64::from_base64(MonsterAssets(a)));
        Test.IsValid = LoadTextureFromFile(Path.c_str(), &Test);
        std::remove(Path.c_str());
        MonsterIcon.push_back(Test);
    }
}

/*
bool AttachMonsterDone;
void AttachMonster() {


std::string packageName = "com.vng.mlbbvn";
	std::ifstream input_file("/data/data/" + packageName + "/.bak");
	if (!input_file.is_open())
	    packageName = "com.mobile.legends";
int Ctry = sizeof(MonsterList) / sizeof(MonsterList[0]);
for (int a = 0;a < Ctry;a++) {
Icon Test;        
string Path = "/data/data/" + packageName + "/files/";   
Path += to_string(a);        
        writeToFile(Path, base64::from_base64(MonsterAssets(a)));
        Test.IsValid = LoadTextureFromFile(Path.c_str(), &Test);
        std::remove(Path.c_str());
        MonsterIcon.push_back(Test);
    }
}

*/
/*

bool AttachMonsterAlertDone;
void AttachMonsterAlert() {
    std::string packageName = "com.vng.mlbbvn";
	std::ifstream input_file("/data/data/" + packageName + "/.bak");
	if (!input_file.is_open())
	    packageName = "com.mobile.legends";
int Ctry = sizeof(MonsterAlertList) / sizeof(MonsterAlertList[0]);
for (int a = 0;a < Ctry;a++) {
Icon Test;        
string Path = "/data/data/" + packageName + "/files/";   
Path += to_string(a);        
        writeToFile(Path, base64::from_base64(MonsterAlertIcon(a)));
        Test.IsValid = LoadTextureFromFile(Path.c_str(), &Test);
        std::remove(Path.c_str());
        MonsterAlert.push_back(Test);
    }
}
*/



bool AttachIconDone;
void AttachIcon() {
	std::string packageName = "com.vng.mlbbvn";
	std::ifstream input_file("/data/data/" + packageName + "/.bak");
	if (!input_file.is_open())
	    packageName = "com.mobile.legends";
	int size = sizeof(iconHeroList) / sizeof(iconHeroList[0]);
	for (int i = 0;i < size;i++) {
        Icon Test;
        string Path = "/data/data/" + packageName + "/files/";
        Path += to_string(i);
        writeToFile(Path, base64::from_base64(IconAssets(i)));
        Test.IsValid = LoadTextureFromFile(Path.c_str(), &Test);
        std::remove(Path.c_str());
        HeroIcon.push_back(Test);
    }
}

bool AttachSpellDone;
void AttachSpell() {
	std::string packageName = "com.vng.mlbbvn";
	std::ifstream input_file("/data/data/" + packageName + "/.bak");
	if (!input_file.is_open())
	    packageName = "com.mobile.legends";
	int size = sizeof(iconSpellList) / sizeof(iconSpellList[0]);
	for (int i = 0;i < size;i++) {
        Icon Test;
        string Path = "/data/data/" + packageName + "/files/";
        Path += to_string(i);
        writeToFile(Path, base64::from_base64(SpellAssets(i)));
        Test.IsValid = LoadTextureFromFile(Path.c_str(), &Test);
        std::remove(Path.c_str());
        SpellIcon.push_back(Test);
    }
}

bool AttachRankDone;
void AttachRank() {
    std::string packageName = "com.mobile.legends";      
    int size = sizeof(iconRankList) / sizeof(iconRankList[0]);
    for (int i = 0;i < size;i++) {
        Icon Test;
        string Path = "/storage/emulated/0/Android/data/" + packageName + "/files/";
        Path += to_string(i) + ".png";
        writeToFile(Path, base64::from_base64(RankAssets(i)));
        Test.IsValid = LoadTextureFromFile(Path.c_str(), &Test);
        RankIcon.push_back(Test);
    }
}


/*
bool AttachMonsterDone;
void AttachMonster() {
	std::string packageName = "com.mobile.legends";
	int size = sizeof(MonsterList) / sizeof(MonsterList[0]);
	for (int i = 0;i < size;i++) {
        Icon Test;
        string Path = "/data/data/" + packageName + "/files/";
        Path += to_string(i);
        writeToFile(Path, base64::from_base64(MonsterIcon(i)));
        Test.IsValid = LoadTextureFromFile(Path.c_str(), &Test);
        std::remove(Path.c_str());
        MonsterIcon.push_back(Test);
    }
}

*/



bool AttachMonsterAlertDone;
void AttachMonsterAlert() {
 int Ctry = sizeof(MonsterAlertList) / sizeof(MonsterAlertList[0]);    
for (int a = 0;a < Ctry;a++) {
Icon Test;
string Path = "/data/data/com.mobile.legends/files/";     
Path += to_string(a);        
writeToFile(Path, base64::from_base64(MonsterAlertIcon(a)));        
Test.IsValid = LoadTextureFromFile(Path.c_str(), &Test);        std::remove(Path.c_str());        
MonsterAlert.push_back(Test);   
 }
}

static float ColorHealth[3] = {0.9f, 0.2f, 0.5f};
float IconAlpha = 1.0f;

namespace ICON {
    int ICSize = 32;
	int ICHealthThin = 3;
}
using namespace ICON;

void DrawIconHero(ImVec2 position, int HeroID, int Hp, int HpMax) {
    auto IconI = ICTexture(HeroID);
    float a_max = ((3.14159265359f * 2));
    float XDX = (ICSize / 2 + 0.121f), XDR = ICSize / 2;
    if (IconI.IsValid) {
        ImGui::GetBackgroundDrawList()->AddImageRounded((void*)(uintptr_t)IconI.texture, ImVec2(position.x - ICSize + XDX, position.y - ICSize + XDX), ImVec2(position.x + ICSize - XDX, position.y + ICSize - XDX), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255,255,255, IconAlpha * 255), 25.0f);
        ImGui::GetBackgroundDrawList()->PathArcTo(position, XDR, (-(a_max / 4.0f)) + (a_max / HpMax) * (HpMax - Hp), a_max - (a_max / 4.0f));
        ImGui::GetBackgroundDrawList()->PathStroke(IM_COL32(ColorHealth[0] * 255, ColorHealth[1] * 255, ColorHealth[2] * 255, IconAlpha * 255), ImDrawFlags_None, ICHealthThin);
    }
}


void DrawMonsters(ImVec2 position, int HeroID, int Size = 64) {
    auto IconI = MonsterTexture(HeroID);
    float a_max = ((3.14159265359f * 2));
    float XDX = (Size / 2 + 0.121f), XDR = Size / 2;
    if (IconI.IsValid) {
        ImGui::GetBackgroundDrawList()->AddImageRounded((void*)(uintptr_t)IconI.texture, ImVec2(position.x - Size + XDX, position.y - Size + XDX), ImVec2(position.x + Size - XDX, position.y + Size - XDX), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255,255,255, IconAlpha * 255), 25.0f);
    }
}

void DrawAlert(int HeroID, float Size, ImVec2 position) {
    auto IconI = MonsterAlertTexture(HeroID);
    if (IconI.IsValid) {
        ImVec2 screenCenter((float)(screenWidth / 2), (float)(screenHeight / 8.7f));
        float XDX = 0.0f; // Kamu perlu mendefinisikan XDX
        float IconAlpha = 1.0f; // Kamu perlu mendefinisikan IconAlpha
        ImGui::GetBackgroundDrawList()->AddImageRounded((void*)(uintptr_t)IconI.texture, ImVec2(position.x - Size + XDX, position.y - Size + XDX), ImVec2(position.x + Size - XDX, position.y + Size - XDX), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255,255,255, IconAlpha * 255), 25.0f);
    }
}

void DrawIconLogo(int type, ImVec2 position, int HeroID, int Hp, int HpMax, int ICSize = 60, int ICHealthThin = 3, bool health = true) {
    auto IconI = ICTexture(HeroID);
    float a_max = ((3.14159265359f * 2));
    float XDX = (ICSize / 2 + 0.121f), XDR = ICSize / 2;
    if (IconI.IsValid) {
        if(type == 1){
            ImGui::GetBackgroundDrawList()->AddImageRounded((void*)(uintptr_t)IconI.texture, ImVec2(position.x - ICSize + XDX, position.y - ICSize + XDX), ImVec2(position.x + ICSize - XDX, position.y + ICSize - XDX), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255,255,255, IconAlpha * 255), 25.0f);
            if(health){
                ImGui::GetBackgroundDrawList()->PathArcTo(position, XDR, (-(a_max / 4.0f)) + (a_max / HpMax) * (HpMax - Hp), a_max - (a_max / 4.0f));
                ImGui::GetBackgroundDrawList()->PathStroke(IM_COL32(ColorHealth[0] * 255, ColorHealth[1] * 255, ColorHealth[2] * 255, IconAlpha * 255), ImDrawFlags_None, ICHealthThin);
            }
        }
        if(type == 2){
            ImGui::GetWindowDrawList()->AddImageRounded((void*)(uintptr_t)IconI.texture, ImVec2(position.x - ICSize + XDX, position.y - ICSize + XDX), ImVec2(position.x + ICSize - XDX, position.y + ICSize - XDX), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255,255,255, IconAlpha * 255), 25.0f);
            if(health){
                ImGui::GetWindowDrawList()->PathArcTo(position, XDR, (-(a_max / 4.0f)) + (a_max / HpMax) * (HpMax - Hp), a_max - (a_max / 4.0f));
                ImGui::GetWindowDrawList()->PathStroke(IM_COL32(ColorHealth[0] * 255, ColorHealth[1] * 255, ColorHealth[2] * 255, IconAlpha * 255), ImDrawFlags_None, ICHealthThin);
            }
        }
        if(type == 3){
            ImGui::GetForegroundDrawList()->AddImageRounded((void*)(uintptr_t)IconI.texture, ImVec2(position.x - ICSize + XDX, position.y - ICSize + XDX), ImVec2(position.x + ICSize - XDX, position.y + ICSize - XDX), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255,255,255, IconAlpha * 255), 25.0f);
            if(health){
                ImGui::GetForegroundDrawList()->PathArcTo(position, XDR, (-(a_max / 4.0f)) + (a_max / HpMax) * (HpMax - Hp), a_max - (a_max / 4.0f));
                ImGui::GetForegroundDrawList()->PathStroke(IM_COL32(ColorHealth[0] * 255, ColorHealth[1] * 255, ColorHealth[2] * 255, IconAlpha * 255), ImDrawFlags_None, ICHealthThin);
            }
        }
        if(type == 4){
            ImGui::Image((void*)(uintptr_t)IconI.texture, ImVec2(38, 38));
        }

    }
}



void DrawIconLogo2(int type, ImVec2 position, int m_ID, int Hp, int HpMax, int ICSize = 45, int ICHealthThin = 3, bool health = true) {
    auto IconI = ICTexture(m_ID);
    float a_max = ((3.14159265359f * 2));
    float XDX = (ICSize / 2 + 0.121f), XDR = ICSize / 2;
    if (IconI.IsValid) {
        if(type == 1){
            ImGui::GetBackgroundDrawList()->AddImageRounded((void*)(uintptr_t)IconI.texture, ImVec2(position.x - ICSize + XDX, position.y - ICSize + XDX), ImVec2(position.x + ICSize - XDX, position.y + ICSize - XDX), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255,255,255, IconAlpha * 255), 25.0f);
            if(health){
                ImGui::GetBackgroundDrawList()->PathArcTo(position, XDR, (-(a_max / 4.0f)) + (a_max / HpMax) * (HpMax - Hp), a_max - (a_max / 4.0f));
                ImGui::GetBackgroundDrawList()->PathStroke(IM_COL32(ColorHealth[0] * 255, ColorHealth[1] * 255, ColorHealth[2] * 255, IconAlpha * 255), ImDrawFlags_None, ICHealthThin);
            }
        }
        if(type == 2){
            ImGui::GetWindowDrawList()->AddImageRounded((void*)(uintptr_t)IconI.texture, ImVec2(position.x - ICSize + XDX, position.y - ICSize + XDX), ImVec2(position.x + ICSize - XDX, position.y + ICSize - XDX), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255,255,255, IconAlpha * 255), 25.0f);
            if(health){
                ImGui::GetWindowDrawList()->PathArcTo(position, XDR, (-(a_max / 4.0f)) + (a_max / HpMax) * (HpMax - Hp), a_max - (a_max / 4.0f));
                ImGui::GetWindowDrawList()->PathStroke(IM_COL32(ColorHealth[0] * 255, ColorHealth[1] * 255, ColorHealth[2] * 255, IconAlpha * 255), ImDrawFlags_None, ICHealthThin);
            }
        }
        if(type == 3){
            ImGui::GetForegroundDrawList()->AddImageRounded((void*)(uintptr_t)IconI.texture, ImVec2(position.x - ICSize + XDX, position.y - ICSize + XDX), ImVec2(position.x + ICSize - XDX, position.y + ICSize - XDX), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255,255,255, IconAlpha * 255), 25.0f);
            if(health){
                ImGui::GetForegroundDrawList()->PathArcTo(position, XDR, (-(a_max / 4.0f)) + (a_max / HpMax) * (HpMax - Hp), a_max - (a_max / 4.0f));
                ImGui::GetForegroundDrawList()->PathStroke(IM_COL32(ColorHealth[0] * 255, ColorHealth[1] * 255, ColorHealth[2] * 255, IconAlpha * 255), ImDrawFlags_None, ICHealthThin);
            }
        }

    }
}


void DrawHero(ImVec2 position, int HeroID, int Hp, int HpMax, int Size = 64, int HealthThin = 3) {
    auto IconI = ICTexture(HeroID);
	float a_max = ((3.14159265359f * 2));
    float XDX = (Size / 2 + 0.121f), XDR = Size / 2;
    if (IconI.IsValid) {
        ImGui::GetBackgroundDrawList()->AddImageRounded((void*)(uintptr_t)IconI.texture, ImVec2(position.x - Size + XDX, position.y - Size + XDX), ImVec2(position.x + Size - XDX, position.y + Size - XDX), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255,255,255, IconAlpha * 255), 25.0f);
		ImGui::GetBackgroundDrawList()->PathArcTo(position, XDR, (-(a_max / 4.0f)) + (a_max / HpMax) * (HpMax - Hp), a_max - (a_max / 4.0f));
        ImGui::GetBackgroundDrawList()->PathStroke(IM_COL32(ColorHealth[0] * 255, ColorHealth[1] * 255, ColorHealth[2] * 255, IconAlpha * 255), ImDrawFlags_None, HealthThin);
    }
}

void DrawSpellHeadField(ImVec2 position, int HeroID, int Hp, int HpMax, int sizeiconHero) {
    auto IconI = SpellTexture(HeroID);
    float a_max = ((3.14159265359f * 2));
    float XDX = (sizeiconHero / 2 + 0.121f), XDR = sizeiconHero / 2;
    if (IconI.IsValid) {
        ImGui::GetBackgroundDrawList()->AddImageRounded((void*)(uintptr_t)IconI.texture, ImVec2(position.x - sizeiconHero + XDX, position.y - sizeiconHero + XDX), ImVec2(position.x + sizeiconHero - XDX, position.y + sizeiconHero - XDX), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255,255,255, IconAlpha * 255), 25.0f);
    }
}
/*

void DrawSpellCDIcon(ImVec2 position, int HeroID, float cooldown, int iconSize, float IconAlpha = 1.0f) {
    auto icon = SpellTexture(HeroID);
    float halfSize = iconSize / 2.0f;
    float offset = 0.121f;

    if (icon.IsValid) {
        // Gambar ikon
        ImGui::GetBackgroundDrawList()->AddImageRounded(
            (void*)(uintptr_t)icon.texture,
            ImVec2(position.x - halfSize + offset, position.y - halfSize + offset),
            ImVec2(position.x + halfSize - offset, position.y + halfSize - offset),
            ImVec2(0, 0), ImVec2(1, 1),
            IM_COL32(255, 255, 255, IconAlpha * 255),
            25.0f
        );

        // Jika cooldown ada, tampilkan angkanya
        if (cooldown > 0.0f) {
            std::string cdText = std::to_string((int)cooldown);
            ImVec2 textSize = ImGui::CalcTextSize(cdText.c_str());

            ImVec2 textPos = ImVec2(
                position.x - textSize.x / 2,
                position.y - textSize.y / 2
            );

            ImGui::GetBackgroundDrawList()->AddText(
                nullptr, 16,
                textPos,
                IM_COL32(255, 100, 100, 255),
                cdText.c_str()
            );
        }
    }
}
*/

void DrawMonster2(ImVec2 position, int HeroID, int Hp, int HpMax, int Size = 64, int HealthThin = 6) {
    auto IconI = MonsterTexture(HeroID);
	float a_max = ((3.14159265359f * 2));
    float XDX = (Size / 2 + 0.121f), XDR = Size / 2;
    if (IconI.IsValid) {
        ImGui::GetBackgroundDrawList()->AddImageRounded((void*)(uintptr_t)IconI.texture, ImVec2(position.x - Size + XDX, position.y - Size + XDX), ImVec2(position.x + Size - XDX, position.y + Size - XDX), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255,255,255, IconAlpha * 255), 25.0f);
		ImGui::GetBackgroundDrawList()->PathArcTo(position, XDR, (-(a_max / 4.0f)) + (a_max / HpMax) * (HpMax - Hp), a_max - (a_max / 4.0f));
        ImGui::GetBackgroundDrawList()->PathStroke(IM_COL32(ColorHealth[0] * 255, ColorHealth[1] * 255, ColorHealth[2] * 255, IconAlpha * 255), ImDrawFlags_None, HealthThin);
    }
}


void RoomInfoCountry2(int id, float Size=38) {
auto IconI = CountryIcon[id];    
 if (IconI.IsValid) {
        ImGui::Image((void*)(uintptr_t)IconI.texture, ImVec2(Size, Size));
		}
	}

void RoomInfoHero(int HeroID, float Size = 38) {
    auto IconI = ICTexture(HeroID);
    if (IconI.IsValid) {
		ImGui::Image((void*)(uintptr_t)IconI.texture, ImVec2(Size, Size));
	}
}

void RoomInfoRank(const int uiRankLevel, float Size = 40) {
    auto IconI = RankTexture(uiRankLevel);
    if (IconI.IsValid) {
        ImGui::Image((void*)(uintptr_t)IconI.texture, ImVec2(Size, Size));
    }
}

void RoomInfoSpell(int HeroID, float Size = 38) {
    auto IconI = SpellTexture(HeroID);
    if (IconI.IsValid) {
		ImGui::Image((void*)(uintptr_t)IconI.texture, ImVec2(Size, Size));
	}
}

