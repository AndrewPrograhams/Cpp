#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int edit_distance(std::string one, std::string two)
{
    int n = one.size();
    int m = two.size();

    //create a vector of size n+1, and fill it with m+1 zeros
    std::vector<std::vector<int>> dist_table(n+1,std::vector<int>(m+1,0));

    //initalize row with numbers 0-n
    for(int i=0;i<=n;i++)
        dist_table[i][0] = i;
    
    //initialize col with number 0-m
    for(int j=0;j<=m;j++)
        dist_table[0][j] = j;
    

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(one[i-1]!=two[j-1])
            {
                dist_table[i][j] = 1 + std::min({dist_table[i-1][j],dist_table[i][j-1],dist_table[i-1][j-1]});
            }
            else
            {
                dist_table[i][j] = dist_table[i-1][j-1];
            }
        }
    }

    return dist_table[n][m];
}

int main()
{
    std::cout << edit_distance("kitten","sitting") << std::endl;
}