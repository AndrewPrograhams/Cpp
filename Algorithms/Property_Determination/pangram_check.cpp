#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <cctype>

using namespace std;

/**
 * Checks to see if a string is a pangarm
 * 
 * @Param str- the string to check
 * @Return - whether or not the string is a pangram
 * @run_time : O(n)
*/
bool pangram_check(const std::string &str) {
    set<char> letters;

    for (char c : str) {
        if (isalpha(c)) {  // Check if the character is a letter (either uppercase or lowercase)
            letters.insert(tolower(c));  // Convert to lowercase and insert
        }
    }

    return letters.size() == 26;  // A pangram should have all 26 letters
}

int main()
{
    //Output should be 1, then 0
    cout << pangram_check("abcdefghijklmnopqrstuvwxyz") << endl;
    cout << pangram_check("absekdjfsabndajbnsjhdfna") << endl;
}