#include <algorithm>
#include <list>
#include "../Common_Functionality_Implementations/devtools.cpp"
#include <string>

using namespace std;

int main()
{
    list<string> L;

    L.push_back("FOO");
    L.push_back("FRIEND");
    L.push_back("SANTA");
    L.push_back("DOO");


    //hasAny is true if the string has any lowercase letters.
    bool hasAnyLower = any_of(L.begin(), L.end(), 
    [](basic_string<char> elem){ 
        return (elem.c_str()[0]) > 96;
        } 
        );

    if(hasAnyLower)
        cout << "One of the strings in L contains a lowercase letter." << endl;
    else
        cout << "None of the strings in L contains a lowercase letter." << endl;



}