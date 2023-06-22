#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    vector<string> l = {"foo", "FoO", "capitalized", "LOWERCASE", "MoReCaPS"};

    cout << *find_if_not(l.begin(),l.end(),[](string str){
        int lower = 0;
        int upper = 0;
        for(auto c: str)
        {
            if(isupper(c))
                upper++;
            else
                lower++;
        }
        return upper <= lower;
    });

    

}