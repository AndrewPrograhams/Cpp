#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    vector<string> l = {"foo", "FOO", "blarg", "bleff", "wOrLd"};

    cout << *find_if(l.begin(),l.end(),[](string str){
        /*
        int upper, lower = 0; Does not assign value 0 to upper. Define line by line.
        */
        
        int upper = 0; 
        int lower = 0;
        for(auto c: str)
        {
            if(isupper(c))
                upper++;
            else
                lower++;
        }
        return upper >= lower;
    });
}