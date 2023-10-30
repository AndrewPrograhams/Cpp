#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/**
 * Reflection:
 * 
 * 1. When debugging I had to change the access indexes on the r expression 'memo' from 'i','j' to 'i-1','j-1'. This is the part
 *    of the algorithm that allows the sub-problem resolutions to accumumlate and influence the generation of the final largest
 *    subsequence.
 * 2. I also was somewhat unsure of what the loop control variables should be. I started with zero for 'i' and 'j', but then
 *    remembered to change it to 1 for both. Then I was torn between using <= or just < for the loop conditionals. In the end
 *    I landed on <=, which makes sense because we are working with an array that has an extra row and column (common in memoization).
*/

int largest_subsequence(string one, string two)
{
    int m = one.length();
    int n = two.length();

    // create a memo to track sub problem results
    vector<vector<int>> memo(m + 1, vector<int>(n+1,0));

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){

            if(one[i-1]==two[j-1])
                memo[i][j] = memo[i-1][j-1] + 1;
            else
            {
                memo[i][j] = max(memo[i-1][j],memo[i][j-1]);
            }
        }
    }

    return memo[m][n];
}

int main()
{
    string one = "ABCBDAB"; 
    string two = "BDCAB";

    string three = "ABC";
    string four = "ACB";
    cout << largest_subsequence(one,two) << endl;

//    cout << naive_lcs(three,four,3,3);
}