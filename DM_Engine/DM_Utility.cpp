#include "DM_Utility.h"
#include <sstream>





std::vector<std::string> DM::Utility::Split_String_With_WhiteSpace(const std::string& source)
{
    std::istringstream iss(source);
    std::string str;

    std::vector<std::string> strVector = {};
    while (getline(iss, str, ' ')) strVector.push_back(str);
    return strVector;
}