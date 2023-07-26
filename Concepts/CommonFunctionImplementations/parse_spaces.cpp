#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> parse_string(std::string str)
{
    //track start and end position, start at zero
    size_t startPos = 0;
    size_t endPos = 0;

    std::vector<std::string> v;

    while(endPos != std::string::npos)
    {
        endPos = str.find(' ', startPos);
        std::string a = str.substr(startPos, endPos-startPos);
        v.push_back(a);
        startPos = endPos + 1;
    }

    return v;
}

int main()
{
    std::string str = "aa aa odg dog god";
    std::vector<std::string> v = parse_string(str);
}

