std::string MonsterToString(int m_id) {
    switch(m_id) {
        case 2002: return "Lord";
        case 2003: return "Turtle";
        case 2004: return "Fiend";
        case 2005: return "Serpent";
        case 2006: return "Scaled Lizard";
        case 2008: return "Crammer 1";
        case 2009: return "Rockursa";
        case 2011: return "Crab";
        case 2012: return "Serpent kids";
        case 2013: return "Crab";
        case 2056: return "Lithowanderer 1";
        case 2059: return "Crammer 2";
        case 2072: return "Lithowanderer 2";
        default: return ""; // or to_string(m_id) if you want the ID as a fallback
    }
}

int ListMonsterId[] = {
    2002, 2003, 2004, 2005, 2006, 
    2008, 2009, 2011, 2012, 2013, 
    2056, 2059, 2072
};

bool bMonster(int iValue) {
    return std::find(std::begin(ListMonsterId), std::end(ListMonsterId), iValue) != std::end(ListMonsterId);
}
