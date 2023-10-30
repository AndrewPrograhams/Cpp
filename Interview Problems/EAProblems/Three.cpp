#include <map>
#include <set>
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

using namespace std;



/*
 * Complete the function below.
 */
int LettersNeededForChurchSign(const char* sentence, const char* lettersAvailable )
{
    //use a hashmap to store letters that we have available, map each character to an integer value
    //iterate through the needed letters, if we run into a letter we don't have, add one to the needed characters list
    //not having means it doesn't exist in the hashmap or the value in the hashmap is 0

    string str_available(lettersAvailable); // Used to get the length of lettersAvailable
    string str_sentence(sentence); //Used to get the length of the sentence

    unordered_map<char,int> letters_in_pile;

    for(int i=0; i<str_available.size();i++)
    {
        //if the letter doesn't exist in the map
        if(letters_in_pile.find(lettersAvailable[i]) == letters_in_pile.end())
            letters_in_pile[lettersAvailable[i]] = 1; // Assign that value to one
        
        else //otherwise we already have that letter and need to update the map to reflect that we have an additional one of those letters in our pile
            letters_in_pile[lettersAvailable[i]] += 1;
    }

    //value to keep track of the number of letters needed to finish the church sign
    int letters_needed = 0;

    for(int i=0; i<str_sentence.size();i++){
        
        //store the active letter for later use
        char active_letter = sentence[i];

        //we can ignore spaces because they are not a limited resource in our church sign
        if(active_letter == ' ')
            continue;

        //if we found the letter in the sentence in our pile
        if(letters_in_pile.find(active_letter) != letters_in_pile.end()) 
        {
            

            if(letters_in_pile[sentence[i]] > 0)
                letters_in_pile[sentence[i]] -= 1;
            
            else //if we had that letter in the pile, but we ran out of it.
                letters_needed++;
        } 
        else //if the letter wasn't in the pile then we need to mark down that we need it
            letters_needed++;
        
    }

    return letters_needed;
}

int main() {
    cout << LettersNeededForChurchSign("Hello World", "lHeorWl!d"); // Output should be two
}