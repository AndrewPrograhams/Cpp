#include <map>
#include <set>
#include <unordered_set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <assert.h>

/**
 * Checks to see if a string is all unique characters
 * @param str:- The string to check
 * @return:- if the string has all unique characters
 * @runtime:- O(n)
 * @space_complexity:- O(n) 
*/

int unique_check(std::string str)
{
    int unique_arr[95] = {0};

    for(int i=0;i<str.size();i++)
    {
        char a = str[i];
        int index = int(a);
        index -= 32;
        std::cout << "Index is: " << index << std::endl;
        if(unique_arr[index])
        {
            std::cout << "element at index is: " << unique_arr[index] << std::endl;
            return 0;
        }
        else
            unique_arr[index]++;
    }
    return 1;
}


bool unique_check_set(const char* str) {
    std::unordered_set<char> charSet;
    int length = strlen(str);  // Determine the length of the C-style string

    for (int i = 0; i < length; ++i) {
        char c = str[i];
        if (charSet.find(c) != charSet.end()) {
            return false;  // Duplicate character found
        }
        charSet.insert(c);
    }
    
    return true;  // All characters are unique
}



bool unique_check_bitset(const char* str) {
    int length = strlen(str);
    
    if (length > 128) {
        return false;  // More characters than possible ASCII values
    }

    std::bitset<128> charSeen;

    for (int i = 0; i < length; ++i) {
        char c = str[i];
        if (charSeen[c]) {
            return false;  // We've seen this character before
        }
        charSeen[c] = 1;  // Mark this character as seen
    }
    
    return true;  // All characters are unique
}





int main()
{
    std::string b = "hello world";
    std::string a = "helo wrd";
    std::cout << "Should be False " << std::endl << unique_check(b) << std::endl;
    std::cout << "Should be True " << std::endl  << unique_check(a) << std::endl;

}