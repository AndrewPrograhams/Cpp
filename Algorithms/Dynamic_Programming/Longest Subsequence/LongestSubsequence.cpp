#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int naive_lcs(const string &x, const string &y, int m, int n)
{
    if(n==0 || m==0)
        return 0;
    if(x[n-1] == y[m-1])
        return 1 + naive_lcs(x,y,n-1,m-1);
    else
        return max (naive_lcs(x,y,n-1,m),naive_lcs(x,y,n,m-1));
}


int dynamic_longest_subsequence(const string &X, const string &Y)
{
    int m = X.size();
    int n = Y.size();

    vector<vector<int>> table(m+1, vector<int>(n+1,0));

    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(X[i-1]==Y[j-1])
                table[i][j] = table[i-1][j-1] + 1;

            else
                table[i][j] = max(table[i-1][j],table[i][j-1]);
         
        }
    }
    return table[m][n];
}



int largest_subsequence(std::string string_one, std::string string_two)
{
    //use a 2D table where each entry represents the length of the longest common subsequence.

    int n = string_one.size();
    int m = string_two.size();

    std::vector<std::vector<int>> sequence_table(n+1,std::vector<int>(m+1,0));

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(string_one[i-1] == string_two[j-1])            
                sequence_table[i][j] = sequence_table[i-1][j-1] + 1;
            else
            {
                int cand_one = sequence_table[i-1][j];
                int cand_two = sequence_table[i][j-1];

                if(cand_one > cand_two)
                    sequence_table[i][j] = cand_one;
                else
                    sequence_table[i][j] = cand_two;
            }
        }
    }

    std::vector<char> chars;

    int i = n;
    int j = m;

    while(i > 0 && j > 0)
    {
        if(string_one[i-1] == string_two[j-1])
        {
            chars.push_back(string_one[i-1]);
            j--;
            i--;
        }
        else{
            if(sequence_table[i-1][j] > sequence_table[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    
    std::reverse(chars.begin(),chars.end());
    
    for(char c: chars)
        std::cout << c;
    
    std::cout << std::endl;
    
    return sequence_table[n][m];
}

int main()
{
    string one = "ABCBDAB";
    string two = "BDCAB";

    string three = "ABC";
    string four = "ACB";
    //cout << largest_subsequence(one,two) << endl;

    cout << naive_lcs(three,four,3,3);
}