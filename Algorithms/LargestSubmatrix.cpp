#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;


int** parseInput(string arr[], int arrLength)
{
  int** matrix = 0;
  int rowLength = arr[0].length();
  matrix = new int*[arrLength];
  for(int l=0; l<arrLength; l++)
  {
    matrix[l] = new int[rowLength];
    for(int w=0;w<rowLength;w++)
    {
      int value = arr[l][w]-'0';
      matrix[l][w] = value;
    }
  }

  return matrix;
}

bool isWithinBounds(int** matrix, int arrLength, int i, int j, int rowLength)
{
  bool withinBounds = i >= 0 && i<arrLength && j >= 0 && j < rowLength;
  
  if(withinBounds)
  {
    withinBounds = matrix[i][j] == 1;
  }
  return withinBounds; 
}




bool ul_square(int** matrix, int i, int j, int length, int arrLength, int rowLength)
{
  
  for(int k=i-length; k<=i;k++)
    for(int l=j-length;l<=j;l++)
    {
      if(isWithinBounds(matrix,arrLength,k,l, rowLength))
        continue;
      else
        return false;
    }

  return true;
}

bool ur_square(int** matrix, int i, int j, int length, int arrLength, int rowLength)
{
  
  for(int k=i+length;k>=i;k--)
    for(int l=j-length;l<=j;l++)
    {
      if(isWithinBounds(matrix,arrLength,k,l, rowLength))
        continue;
      else
        return false;
    }

  return true;
}

bool ll_square(int** matrix, int i, int j, int length, int arrLength, int rowLength)
{
  
  for(int k=i-length; k<=i;k++)
    for(int l=j+length;l>=j;l--)
    {
      if(isWithinBounds(matrix,arrLength,k,l, rowLength))
        continue;
      else
        return false;
    }

  return true;
}

bool lr_square(int** matrix, int i, int j, int length, int arrLength, int rowLength)
{
  
  for(int k=i+length; k>=i;k--)
    for(int l=j+length;l>=j;l--)
    {
      if(isWithinBounds(matrix,arrLength,k,l,rowLength))
        continue;
      else
        return false;
    }

  return true;
}


string MaximalSquare(string strArr[], int arrLength) {
  
  // code goes here  
  int** matrix = parseInput(strArr,arrLength);

  int largestLength = 1;

  int currentLength = 1;

  int rowLength = strArr[0].length();

  for(int i=0;i<arrLength;i++)
  {
    for(int j=0;j<rowLength;j++)
    {
      if(matrix[i][j]==0)
        continue;
      else
      {
        while(lr_square(matrix,i,j,currentLength,arrLength,rowLength))
          {
            currentLength++;
            if(currentLength>largestLength)
              largestLength = currentLength;
          }
          currentLength = 1;
        while(ll_square(matrix,i,j,currentLength,arrLength, rowLength))
        {
          currentLength++;
          if(currentLength>largestLength)
            largestLength = currentLength;
        }
          currentLength = 1;
        while(ur_square(matrix,i,j,currentLength,arrLength, rowLength))
        {
          currentLength++;
          if(currentLength>largestLength)
            largestLength = currentLength;
        }
        currentLength = 1;
        while(ul_square(matrix,i,j,currentLength,arrLength,rowLength))
        {
          currentLength++;
          if(currentLength>largestLength)
            largestLength = currentLength;
        }
      }
    }
  }
  
  return to_string((largestLength*largestLength));

}