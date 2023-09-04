#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <utility>

std::vector<std::vector<int>> ParseData(std::string args[], int arrLength)
{
    
    int rowLength = arrLength;
    int colLength = args[0].length();
    std::vector<std::vector<int>> Matrix(rowLength, std::vector<int>(arrLength,0));

    for(int r=0;r<rowLength;r++)
    {
        for(int c=0;c<colLength;c++)
        {
            int value = args[r][c] - '0';
            Matrix[r][c] = value;
        }
    }

    return Matrix;
}

bool isInRange(int rows, int cols, int x, int y)
{
    return x < rows && y < cols && x > -1 && y > -1;
}


//Checks to see if the entries that fall within the bounds of two coordinates is a rectangle
//Runtime: O(n^2)
bool is_rectangle(std::vector<std::vector<int>> Matrix, int xS, int yS, int xE, int yE, int* size)
{
    if(xS == xE && yS == yE)
        return 0;

    //std::cout << "Size is currently: " << *size << std::endl;
    for(int i=xS;i<=xE;i++)
        for(int j=yS;j<=yE;j++)
        {
            if(Matrix[i][j] == 1)
            {
                (*size)++;
                continue;
            }
            else
            {
                *size = 0;
                return false;
            }
        }

    return true;
}

int LargestRectangularSubmatrix(std::string args[], int arrLength)
{
    std::vector<std::vector<int>> Matrix = ParseData(args, arrLength);
    int rowLength = arrLength;
    int colLength = args[0].length();

    int largest = 0;
    std::vector<std::pair<int, int>> coordinates;

    //Runtime: O(n^2)
    for(int i=0;i<rowLength;i++)
    {
        for(int j=0;j<colLength;j++)
        {
            coordinates.push_back(std::pair<int,int>(i,j));
            //std::cout << Matrix[i][j];      
        }
        //std::cout << std::endl;
    }
    
    //Runtime: O(n^4 + 2(n^2))
    for(std::pair<int,int> p : coordinates)
    {
        for(int i=0;i<rowLength;i++)
            for(int j=0;j<colLength;j++)
            {
                int size = 0;
                if(is_rectangle(Matrix, i,j,p.first,p.second,&size))
                {
                    if(size > largest)
                        largest = size;
                }
            }
    }

    std::cout << largest << std::endl;

    return largest;
}

int main()
{
    std::string strs[] = {
        "1111",
        "1110",
        "1100",
        "1111",
        "1100"
    };

    int arrLength = sizeof(strs) / sizeof(strs[0]);  // Calculate the array length

    int solution = LargestRectangularSubmatrix(strs, arrLength);
}