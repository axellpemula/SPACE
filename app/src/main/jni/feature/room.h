
inline ImVec4 RGBA2ImVec4(int r, int g, int b, int a) {
    float newr = (float)r / 255.0f;
    float newg = (float)g / 255.0f;
    float newb = (float)b / 255.0f;
    float newa = (float)a / 255.0f;
    return ImVec4(newr, newg, newb, newa);
}

struct CountryInfo {
    std::string code;
    std::string name;
};

//#include <map>
bool Roomlnfo;

// Checkbox untuk toggle Auto Reconnect


// Definisikan peta untuk memetakan kode negara ke nama negara
CountryInfo countryData[] = {
    {"af", "Afghanistan" },
{"za", "South Africa" },
{"cf", "Central African Republic" },
{"ax", "Åland Islands" },
{"al", "Albania" },
{"dz", "Algeria" },
{"us", "United States" },
{"ad", "Andorra" },
{"ao", "Angola" },
{"ai", "Anguilla" },
{"aq", "Antarctica" },
{"ag", "Antigua" },
{"an", "Netherlands" },
{"sa", "Arab " },
{"ar", "Argentina" },
{"am", "Armenia" },
{"aw", "Aruba" },
{"au", "Australia" },
{"at", "Austria" },
{"az", "Azerbaijan" },
{"bs", "Bahamas" },
{"bh", "Bahrain" },
{"bd", "Bangladesh" },
{"bb", "Barbados" },
{"nl", "Netherlands" },
{"by", "Belarus" },
{"be", "Belgium" },
{"bz", "Belize" },
{"bj", "Benin" },
{"bm", "Bermuda" },
{"bt", "Bhutan" },
{"bo", "Bolivia" },
{"ba", "Bosnia" },
{"bw", "Bostwana" },
{"bv", "Bouvet Island" },
{"br", "Brazil" },
{"gb", "United Kingdom" },
{"bn", "Brunei" },
{"bg", "Bulgaria" },
{"bf", "Burkina" },
{"bi", "Burundi" },
{"ky", "Cayman" },
{"td", "Chad" },
{"cz", "Czechia" },
{"cl", "Chile" },
{"cc", "Cocos" },
{"ck", "Cook" },
{"dk", "Denmark" },
{"dj", "Djibouti" },
{"dm", "Dominica" },
{"do", "Dominican" },
{"ec", "Ecuador" },
{"sv", "El Salvador" },
{"er", "Eritrea" },
{"ee", "Estonia" },
{"sz", "Eswatini" },
{"et", "Ethiopia" },
{"fk", "Falkland " },
{"fo", "Faroe " },
{"fj", "Fiji" },
{"ph", "Philippines" },
{"fi", "Finland" },
{"ga", "Gabon" },
{"gm", "Gambia" },
{"ge", "Georgia" },
{"gs", "South Georgia" },
{"gh", "Ghana" },
{"gi", "Gibraltar" },
{"gl", "Greenland" },
{"gd", "Grenada" },
{"gp", "Guadeloupe" },
{"gu", "Guam" },
{"gt", "Guatemala" },
{"gg", "Guernsey" },
{"gn", "Guinea" },
{"gw", "Guinea-Bissau" },
{"gq", "Equatorial Guinea" },
{"gy", "Guyana" },
{"gf", "French Guiana" },
{"ht", "Haiti" },
{"hm", "Heard Island" },
{"hn", "Honduras" },
{"hk", "Hong Kong" },
{"hu", "Hungary" },
{"is", "Iceland" },
{"in", "India" },
{"id", "Indonesia" },
{"iq", "Iraq" },
{"ir", "Iran" },
{"ie", "Ireland" },
{"il", "Israel" },
{"it", "Italy" },
{"jm", "Jamaica" },
{"jp", "Japan" },
{"de", "Germany" },
{"je", "Jersey" },
{"nc", "New Caledonia" },
{"kh", "Cambodia" },
{"cm", "Cameroon" },
{"ca", "Canada" },
{"kz", "Kazakhstan" },
{"ke", "Kenya" },
{"ki", "Kiribati" },
{"kg", "Kyrgyzstan" },
{"co", "Colombia" },
{"km", "Comoros" },
{"cg", "Congo" },
{"cd", "Congo" },
{"kr", "Korea" },
{"kp", "Korea" },
{"cr", "Costa Rica" },
{"hr", "Croatia" },
{"cu", "Cuba" },
{"kw", "Kuwait" },
{"la", "Laos Vientiane" },
{"lv", "Latvia" },
{"lb", "Lebanon" },
{"ls", "Lesotho" },
{"lr", "Liberia" },
{"ly", "Libyan Arab" },
{"li", "Liechtenstein" },
{"lt", "Lithuania" },
{"lu", "Luxembourg" },
{"mo", "Macao" },
{"mk", "Macedonia" },
{"mg", "Madagascar" },
{"mw", "Malawi" },
{"my", "Malaysia" },
{"mv", "Maldives" },
{"ml", "Mali" },
{"mt", "Malta" },
{"im", "Isle of Man" },
{"mp", "Northern" },
{"ma", "Marocco" },
{"mh", "Marshall" },
{"mq", "Martinique" },
{"mr", "Mauritania" },
{"mu", "Mauritius" },
{"yt", "Mayotte" },
{"mx", "Mexico" },
{"fm", "Micronesia" },
{"md", "Moldova" },
{"eg", "Egypt" },
{"mc", "Monaco" },
{"um", "United Minor" },
{"mn", "Mongolia" },
{"me", "Montenegro" },
{"ms", "Montserrat" },
{"mz", "Mozambique" },
{"mm", "Myanmar" },
{"na", "Namibia" },
{"nr", "Nauru" },
{"cx", "Christmas Island" },
{"np", "Nepal" },
{"ni", "Nicaragua" },
{"ne", "Niger" },
{"ng", "Nigeria" },
{"nu", "Niue" },
{"nf", "Norfolk Island" },
{"no", "Norway" },
{"om", "Oman" },
{"pk", "Pakistan" },
{"pw", "Palau" },
{"ps", "Palestinian" },
{"pa", "Panama" },
{"ci", "Côte d'Ivoire" },
{"pg", "Papua" },
{"py", "Paraguay" },
{"fr", "France" },
{"tf", "Territories" },
{"pe", "Peru" },
{"pn", "Pitcairn" },
{"pl", "Poland" },
{"pf", "French Polynesia" },
{"pt", "Portugal" },
{"pr", "Puerto Rico" },
{"qa", "Qatar" },
{"re", "Réunion" },
{"ro", "Romania" },
{"ru", "Russian Federation" },
{"rw", "Rwanda" },
{"eh", "Western Sahara" },
{"bl", "Saint Barthélemy" },
{"sh", "Saint Helena" },
{"kn", "Saint Kitts and Nevis" },
{"lc", "Saint Lucia" },
{"mf", "Saint Martin " },
{"pm", "Saint-Pierre" },
{"vc", "Saint Vincent" },
{"ws", "Samoa" },
{"as", "American Samoa" },
{"io", "Indian" },
{"sm", "San Marino" },
{"st", "São Tomé" },
{"nz", "New Zealand" },
{"sn", "Senegal" },
{"rs", "Serbia" },
{"sc", "Seychelles" },
{"sl", "Sierra Leone" },
{"sg", "Singapore" },
{"cy", "Cyprus" },
{"si", "Slovenia" },
{"sk", "Slowakia" },
{"sb", "Salomon Islands" },
{"so", "Somalia" },
{"es", "Spain" },
{"lk", "Sri Lanka" },
{"sd", "Sudan" },
{"sy", "Syrian Arab" },
{"sr", "Suriname" },
{"sj", "Svalbard   " },
{"se", "Sweden" },
{"ch", "Switzerland" },
{"tw", "Taiwan" },
{"tj", "Tajikistan" },
{"cv", "Cape Verde" },
{"tz", "Tanzania" },
{"th", "Thailand" },
{"tl", "Timor Leste" },
{"cn", "China" },
{"tg", "Togo" },
{"tk", "Tokelau" },
{"to", "Tonga" },
{"tt", "Tobago" },
{"tn", "Tunisia" },
{"tr", "Turkey" },
{"tm", "Turkmenistan" },
{"tc", "Turks " },
{"tv", "Tuvalu" },
{"ug", "Uganda" },
{"ua", "Ukraine" },
{"ae", "United Arab" },
{"uy", "Uruguay" },
{"uz", "Uzbekistan" },
{"vu", "Vanuatu" },
{"va", "Vatican City" },
{"ve", "Venezuela" },
{"vn", "VietNam" },
{"vi", "Virgin Islands" },
{"vg", "British" },
{"wf", "Wallis " },
{"ye", "Yemen" },
{"jo", "Jordan" },
{"gr", "Greece" },
{"zm", "Zambia" },
{"zw", "Zimbabwe" },

    // Masukkan semua negara sesuai ISO 3166-1 alpha-2 code
    // Contoh: {"ID", "Indonesia"}, {"US", "United States"}, dll.
};

std::string getCountryNameByCode(const std::string& countryCode) {
    for (const CountryInfo& info : countryData) {
        if (info.code == countryCode) {
            return info.name;
        }
    }
    return countryCode;
}



// Button for Selection Enemy Or Team 
int selectedOption = 0; 



std::string strRank[] = {
        "Warrior - III * 1",
        "Warrior - III * 2",
        "Warrior - III * 3",
        "Warrior - II * 0",
        "Warrior - II * 1",
        "Warrior - II * 2",
        "Warrior - II * 3",
        "Warrior - I * 0",
        "Warrior - I * 1",
        "Warrior - I * 2",
        "Warrior - I * 3",
        "Elite - III * 0",
        "Elite - III * 1",
        "Elite - III * 2",
        "Elite - III * 3",
        "Elite - III * 4",
        "Elite - II * 0",
        "Elite - II * 1",
        "Elite - II * 2",
        "Elite - II * 3",
        "Elite - II * 4",
        "Elite - I * 0",
        "Elite - I * 1",
        "Elite - I * 2",
        "Elite - I * 3",
        "Elite - I * 4",
        "Master - IV * 0",
        "Master - IV * 1",
        "Master - IV * 2",
        "Master - IV * 3",
        "Master - IV * 4",
        "Master - III * 0",
        "Master - III * 1",
        "Master - III * 2",
        "Master - III * 3",
        "Master - III * 4",
        "Master - II * 0",
        "Master - II * 1",
        "Master - II * 2",
        "Master - II * 3",
        "Master - II * 4",
        "Master - I * 0",
        "Master - I * 1",
        "Master - I * 2",
        "Master - I * 3",
        "Master - I * 4",
        "Grandmaster - V * 0",
        "Grandmaster - V * 1",
        "Grandmaster - V * 2",
        "Grandmaster - V * 3",
        "Grandmaster - V * 4",
        "Grandmaster - V * 5",
        "Grandmaster - IV * 0",
        "Grandmaster - IV * 1",
        "Grandmaster - IV * 2",
        "Grandmaster - IV * 3",
        "Grandmaster - IV * 4",
        "Grandmaster - IV * 5",
        "Grandmaster - III * 0",
        "Grandmaster - III * 1",
        "Grandmaster - III * 2",
        "Grandmaster - III * 3",
        "Grandmaster - III * 4",
        "Grandmaster - III * 5",
        "Grandmaster - II * 0",
        "Grandmaster - II * 1",
        "Grandmaster - II * 2",
        "Grandmaster - II * 3",
        "Grandmaster - II * 4",
        "Grandmaster - II * 5",
        "Grandmaster - I * 0",
        "Grandmaster - I * 1",
        "Grandmaster - I * 2",
        "Grandmaster - I * 3",
        "Grandmaster - I * 4",
        "Grandmaster - I * 5",
        "Epic - V * 0",
        "Epic - V * 1",
        "Epic - V * 2",
        "Epic - V * 3",
        "Epic - V * 4",
        "Epic - V * 5",
        "Epic - IV * 0",
        "Epic - IV * 1",
        "Epic - IV * 2",
        "Epic - IV * 3",
        "Epic - IV * 4",
        "Epic - IV * 5",
        "Epic - III * 0",
        "Epic - III * 1",
        "Epic - III * 2",
        "Epic - III * 3",
        "Epic - III * 4",
        "Epic - III * 5",
        "Epic - II * 0",
        "Epic - II * 1",
        "Epic - II * 2",
        "Epic - II * 3",
        "Epic - II * 4",
        "Epic - II * 5",
        "Epic - I * 0",
        "Epic - I * 1",
        "Epic - I * 2",
        "Epic - I * 3",
        "Epic - I * 4",
        "Epic - I * 5",
        "Legend - V * 0",
        "Legend - V * 1",
        "Legend - V * 2",
        "Legend - V * 3",
        "Legend - V * 4",
        "Legend - V * 5",
        "Legend - IV * 0",
        "Legend - IV * 1",
        "Legend - IV * 2",
        "Legend - IV * 3",
        "Legend - IV * 4",
        "Legend - IV * 5",
        "Legend - III * 0",
        "Legend - III * 1",
        "Legend - III * 2",
        "Legend - III * 3",
        "Legend - III * 4",
        "Legend - III * 5",
        "Legend - II * 0",
        "Legend - II * 1",
        "Legend - II * 2",
        "Legend - II * 3",
        "Legend - II * 4",
        "Legend - II * 5",
        "Legend - I * 0",
        "Legend - I * 1",
        "Legend - I * 2",
        "Legend - I * 3",
        "Legend - I * 4",
        "Legend - I * 5"
};


int valuePoint[] = {
        1,
        2,
        3,
        0,
        1,
        2,
        3,
        0,
        1,
        2,
        3,
        0,
        1,
        2,
        3,
        4,
        0,
        1,
        2,
        3,
        4,
        0,
        1,
        2,
        3,
        4,
        0,
        1,
        2,
        3,
        4,
        0,
        1,
        2,
        3,
        4,
        0,
        1,
        2,
        3,
        4,
        0,
        1,
        2,
        3,
        4,
        0,
        1,
        2,
        3,
        4,
        5,
        0,
        1,
        2,
        3,
        4,
        5,
        0,
        1,
        2,
        3,
        4,
        5,
        0,
        1,
        2,
        3,
        4,
        5,
        0,
        1,
        2,
        3,
        4,
        5,
        0,
        1,
        2,
        3,
        4,
        5,
        0,
        1,
        2,
        3,
        4,
        5,
        0,
        1,
        2,
        3,
        4,
        5,
        0,
        1,
        2,
        3,
        4,
        5,
        0,
        1,
        2,
        3,
        4,
        5,
        0,
        1,
        2,
        3,
        4,
        5,
        0,
        1,
        2,
        3,
        4,
        5,
        0,
        1,
        2,
        3,
        4,
        5,
        0,
        1,
        2,
        3,
        4,
        5,
        0,
        1,
        2,
        3,
        4,
        5
};



std::string SetButtonText(std::string text, bool separator){
    if(separator){
        return text +  " [ ON ]";
    }
    return text +  " [ OFF ]";
}



const char ascii_hex_4bit[23] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0, 0, 10, 11, 12, 13, 14, 15};

static inline char to_upper(char c)
{
    if ((c >= 'a') && (c <= 'z')) return c ^ 0x20;
    return c;
}

char * urldecode(const char * str)
{
    size_t i, j, len = strlen(str);
    char c, d, url_hex;
    char * decoded = (char*)malloc(len + 1);
    if (decoded == NULL) return NULL;
    i = 0;
    j = 0;
    do {
        c = str[i];
        d = 0;
        if (c == '%') {
            url_hex = to_upper(str[++i]);
            if (((url_hex >= '0') && (url_hex <= '9')) || ((url_hex >= 'A') && (url_hex <= 'F'))) {
                d = ascii_hex_4bit[url_hex - 48] << 4;

                url_hex = to_upper(str[++i]);
                if (((url_hex >= '0') && (url_hex <= '9')) || ((url_hex >= 'A') && (url_hex <= 'F'))) {
                    d |= ascii_hex_4bit[url_hex - 48];
                } else {
                    d = 0;
                }
            }
        }
        else if (c == '+') {
            d = ' ';
        }
        else if ((c == '*') || (c == '-') || (c == '.') || ((c >= '0') && (c <= '9')) || ((c >= 'A') && (c <= 'Z')) || (c == '_')  || ((c >= 'a') && (c <= 'z'))) {
            d = c;
        }
        decoded[j++] = d;
        ++i;
    } while ((i < len) && (d != 0));

    decoded[j] = 0;
    return decoded;
}

std::string GetNickName(std::string UserId, std::string ZoneId)
{
}
std::string RankToString(int uiRankLevel, int iMythPoint) {
    if (uiRankLevel > 135) {
        int rankStar = iMythPoint - 100;
        int displayMythPoint = rankStar / 10;
        if (rankStar >= 1000) {
            return "Imo *" + to_string(displayMythPoint);
        } else if (rankStar >= 500) {
            return "Glory * " + to_string(displayMythPoint);
        } else if (rankStar >= 250) {
            return "Honor * " + to_string(displayMythPoint);
        } else {
            return "Mythic * " + to_string(displayMythPoint);
        }
    } else {
        return strRank[uiRankLevel];
    }
}

std::string SplitGrade(const int uiRankLevel){
    if (uiRankLevel <= 136) {
        std::string rankWithStars = strRank[uiRankLevel];
        std::size_t starPos = rankWithStars.find('-');
        if (starPos != std::string::npos) {
            std::string Row = rankWithStars.substr(starPos + 2);
            std::size_t awd = Row.find('*');
            std::string row1;
            std::string row2;
            if(awd != std::string::npos){
                row1 = Row.substr(0, awd - 1);
                row2 = Row.substr(awd + 2);
            }
            return row1;
        }
    }
    if(uiRankLevel > 136){
        int Star = uiRankLevel - 136;
        if ((int)Star <= 24)  return "Mythic";
        if ((int)Star > 24)  return "Honor";
        if ((int)Star > 49)  return "Glory";
        if ((int)Star > 99)  return "Immortal";
    }
}

std::tuple<std::string, std::string> SplitRankAndStars(const int uiRankLevel, const int iMythPoint) {
    if (uiRankLevel <= 136) {
        std::string rankWithStars = strRank[uiRankLevel];
        std::size_t starPos = rankWithStars.find('*');
        if (starPos != std::string::npos) {
            std::string rankName = rankWithStars.substr(0, starPos - 1);
            std::string starCount = rankWithStars.substr(starPos + 2);
            return std::make_tuple(rankName, starCount);
        }
    }
    std::string nameMythic = "Mythic";
    if(uiRankLevel > 136){
        float starMythic = (float)iMythPoint * (50.0 / 600.0);
        int Star = uiRankLevel - 136;
        if ((int)Star > 24)  nameMythic = "Mythical Honor";
        if ((int)Star > 49)  nameMythic = "Mythical Glory";
        if ((int)Star > 99)  nameMythic = "Mythical Immortal";
        return std::make_tuple(nameMythic, std::to_string(Star));
    }
}

std::string VerifiedToString(int iCertify) {
    std::string str = std::string(OBFUSCATE("-"));
    if (iCertify == 0) {
        str = std::string(OBFUSCATE("No"));
    } else {
        str = std::string(OBFUSCATE("Yes"));
    }
    return str;
}



static bool Rune;
static bool isTeam;
static bool isEnemy;
static bool InitializeNick = false;

struct PlayerData {
    std::string Name;
    std::string UserID;
    std::string Verified;
    std::string Rank;
    std::string Star;
    std::string grade;
    std::string region;
    std::string Country;
//    std::string Version;

        std::string Squad;
    int ulRoomID;
    int uiRank;
    int uiStar;
    int HeroID;
    int Spell;
    int Country2;
    int TotalMatches;
	int TotalWins;
	int iRealRoad;
	float WinRate;
};





struct  {
    PlayerData PlayerB[10];
    PlayerData PlayerR[10];
    
    
} RoomInfo;







const char * TextFormat(const char * Str, ...)
{
    char buf[1000] = { 0 };
    va_list arg;
    va_start(arg, Str);
    vsprintf(buf, Str, arg);
    va_end(arg);
    return buf;
}

std::string Nick[10];
std::string Region[10];

void * DoThreadGetNickName(void*)
{
    List<uintptr_t> *m_RoomPlayerInfo = GetBattlePlayerInfo();
    if (!m_RoomPlayerInfo) nullptr;
    for (int i = 0; i < m_RoomPlayerInfo->getSize(); i++) {
        auto roomData = m_RoomPlayerInfo->getItems()[i];
        if (roomData != NULL) {
            auto lUid = *(int *) ((uintptr_t)roomData + RoomData_lUid);
            auto uiZoneId = *(int *) ((uintptr_t)roomData + RoomData_uiZoneId);
            Nick[i] = GetNickName(TextFormat("%d", lUid), TextFormat("%d", uiZoneId));
        }
    }
    pthread_exit(nullptr);
    return nullptr;
}





//void RoomInfoList() {
void RoomInfoList() {




    auto iBattleState = GetBattleState();
    if (iBattleState == 2 || iBattleState == 3) 
    {
            if (InitializeNick == false) {
                pthread_t thread;
                pthread_create(&thread, NULL, DoThreadGetNickName, NULL);
                InitializeNick = true;
            }
            

                
            
            List<uintptr_t>* m_RoomPlayerInfo = GetBattlePlayerInfo();
        if (!m_RoomPlayerInfo) return;

        int PlayerB = 0, PlayerR = 0, iSelfCamp = -1;
        int m_uiID = *(int*)(SystemData_m_uiID);



        // Tentukan self camp
        for (int i = 0; i < m_RoomPlayerInfo->getSize(); i++) {
            auto roomData = m_RoomPlayerInfo->getItems()[i];
            if (!roomData) continue;
            auto iCamp = *(int*)((uintptr_t)roomData + RoomData_iCamp);
            auto lUid = *(int*)((uintptr_t)roomData + RoomData_lUid);
            if (lUid != m_uiID) continue;
            iSelfCamp = iCamp;
            break;
        }
        

        // Iterasi semua pemain
        for (int i = 0; i < m_RoomPlayerInfo->getSize(); i++) {
            auto roomData = m_RoomPlayerInfo->getItems()[i];
            if (!roomData) continue;
            auto _steamName = *(String **) ((uintptr_t)roomData + RoomData_steamName);
            auto iCamp = *(int*)((uintptr_t)roomData + RoomData_iCamp);
            auto lUid = *(int*)((uintptr_t)roomData + RoomData_lUid);
            auto uiZoneId = *(int*)((uintptr_t)roomData + RoomData_uiZoneId);
            auto heroid = *(int*)((uintptr_t)roomData + RoomData_heroid);
            auto uiHeroIDChoose = *(int*)((uintptr_t)roomData + RoomData_uiHeroIDChoose);
            auto summonSkillId = *(int*)((uintptr_t)roomData + RoomData_summonSkillId);
            auto* _sName = *(String**)((uintptr_t)roomData + RoomData_sName);
            auto iCertify = *(int*)((uintptr_t)roomData + RoomData_iCertify);
            auto uiRankLevel = *(int*)((uintptr_t)roomData + RoomData_uiRankLevel);
            auto iMythPoint = *(int*)((uintptr_t)roomData + RoomData_iMythPoint);
            auto *sThisLoginCountry = *(String **) ((uintptr_t)roomData + RoomData_sThisLoginCountry);
        //    auto *sClientVersion = *(String **) ((uintptr_t)roomData + RoomData_sClientVersion);
            
            auto Country2 = *(int*)((uintptr_t)roomData + RoomData_Flag);
          auto splitRank = SplitRankAndStars(uiRankLevel, iMythPoint);
          std::string rankName = std::get<0>(splitRank);
          std::string starCount = std::get<1>(splitRank);
 //               auto Grade = SplitGrade(uiRankLevel);
                
// Pemanggilan fungsi SplitRankAndStars

                
            int iTotalNum = 0;
            int iWinNum = 0;
            
			float winRate = 0.0f;
            List<void **> *vCurSeasonRealRoadInfo = *(List<void **> **) ((uintptr_t)roomData + RoomData_vCurSeasonRealRoadInfo);
            if (vCurSeasonRealRoadInfo) {
                for (int j = 0; j < vCurSeasonRealRoadInfo->getSize(); j++) {
                    auto battle = vCurSeasonRealRoadInfo->getItems()[j];
                    if (!battle) continue;
                    
                    auto iRealRoad = *(int*)((uintptr_t)battle + PlayerRealRoadInfo_ulUid);
                    iTotalNum = *(int*)((uintptr_t)battle + PlayerRealRoadInfo_iTotalNum);
                    iWinNum = *(int*)((uintptr_t)battle + PlayerRealRoadInfo_iWinNum);
                    if (iTotalNum > 0) {
                        winRate = (float)iWinNum / (float)iTotalNum * 100.0f;
                    } 
                }
            }
            
//if (Roomlnfo) {
    //    RoomInfo.Reset();

//Reset.RoomInfo();
//RoomInfo.Reset();
 

                if (iCamp == iSelfCamp) {

                    RoomInfo.PlayerB[PlayerB].UserID = to_string(lUid) + " (" + to_string(uiZoneId) + ")";
                    RoomInfo.PlayerB[PlayerB].Name = Nick[i].c_str();
                                    if (_steamName) {
                    RoomInfo.PlayerB[PlayerB].Squad = _steamName->toString();
                }
                    RoomInfo.PlayerB[PlayerB].Rank = rankName;
                    RoomInfo.PlayerB[PlayerB].Star = starCount;
                    RoomInfo.PlayerB[PlayerB].Verified = VerifiedToString(iCertify);
                    
                    RoomInfo.PlayerB[PlayerB].HeroID = (uiHeroIDChoose) ? uiHeroIDChoose : heroid;
                    RoomInfo.PlayerB[PlayerB].Spell = summonSkillId;
                    RoomInfo.PlayerB[PlayerB].uiRank = uiRankLevel;
                    RoomInfo.PlayerB[PlayerB].uiStar = iMythPoint;


if (sThisLoginCountry) RoomInfo.PlayerB[PlayerB].Country = getCountryNameByCode(sThisLoginCountry->toString());

                    //	if (sThisLoginCountry) RoomInfo.PlayerB[PlayerB].Country = sThisLoginCountry->toString();
                    //   if (sClientVersion) RoomInfo.PlayerB[PlayerB].Version = sClientVersion->toString();            		
                    
	
				    RoomInfo.PlayerB[PlayerB].Country2 = Country2;
				    RoomInfo.PlayerB[PlayerB].WinRate = winRate;
                    RoomInfo.PlayerB[PlayerB].TotalMatches = iTotalNum;
                    RoomInfo.PlayerB[PlayerB].TotalWins = iWinNum;


                    PlayerB++;
                    

                
                } else {
                 
                
        
                    RoomInfo.PlayerR[PlayerR].UserID = to_string(lUid) + " (" + to_string(uiZoneId) + ")";
                    RoomInfo.PlayerR[PlayerR].Name = Nick[i].c_str();
                                    if (_steamName) {
                    RoomInfo.PlayerR[PlayerR].Squad = _steamName->toString();
                }

                    RoomInfo.PlayerR[PlayerR].Rank = rankName;
                    RoomInfo.PlayerR[PlayerR].Star = starCount;
                    RoomInfo.PlayerR[PlayerR].Verified = VerifiedToString(iCertify);
                    
                    RoomInfo.PlayerR[PlayerR].HeroID = (uiHeroIDChoose) ? uiHeroIDChoose : heroid;
                    RoomInfo.PlayerR[PlayerR].Spell = summonSkillId;
                    RoomInfo.PlayerR[PlayerR].uiRank = uiRankLevel;
                    RoomInfo.PlayerR[PlayerR].uiStar = iMythPoint;

                                    if (sThisLoginCountry) RoomInfo.PlayerR[PlayerR].Country = getCountryNameByCode(sThisLoginCountry->toString());
                    
                  //  	if (sThisLoginCountry) RoomInfo.PlayerR[PlayerR].Country = sThisLoginCountry->toString();
                       //  if (sClientVersion) RoomInfo.PlayerR[PlayerR].Version = sClientVersion->toString();
			    	RoomInfo.PlayerR[PlayerR].Country2 = Country2;
			         
			    	RoomInfo.PlayerR[PlayerR].WinRate = winRate;
                    RoomInfo.PlayerR[PlayerR].TotalMatches = iTotalNum;
                    RoomInfo.PlayerR[PlayerR].TotalWins = iWinNum;

                PlayerR++;             
            }

        }
    } else{
            InitializeNick = false;
            for (int i = 0; i < 10; i++) Nick[i] = "connecting.."; //clear nick
        }
      if (iBattleState == 0 || iBattleState == 7 || iBattleState == 8) {
            for (int i = 0; i < 10; i++) Nick[i] = "-";
        }

}

void ShowResetShowRoomPlayerInfo() {
    // Panggil RoomInfoList di sini
    RoomInfoList();
    // Kode lainnya
}

