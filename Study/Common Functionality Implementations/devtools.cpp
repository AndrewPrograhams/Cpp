#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <cmath>
#include "heap.cpp"
using namespace std;

//adds proper commas to a string that represents a whole number

string formatNumberCommas(string str)
{
  size_t startPos = str.length();
  for(int i=startPos-3; i>= 0; i-=3)
    str.insert(i,1,',');
  return str;
}


//Splits a string based on a delimiter
vector<string> split(string str,string delimiter){
    str.append(delimiter);
    size_t pos = 0;
    string token;
    vector<string> toReturn;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        toReturn.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    return toReturn;
}

//rounds a float to the nearest integer
int roundFloat(float dou)
{
    return round(dou);
}

void swap(int arr[], int index_one, int index_two)
{
    int temp = arr[index_one];
    arr[index_one] = arr[index_two];
    arr[index_two] = temp;
}

bool is_sorted(int arr[], int arrLength)
{
    if(arrLength == 1)
        return true;

    for(int i=0;i<arrLength-1;i++)
    {   
        if(i==arrLength-1)
            break;
        if(arr[i] > arr[i+1])
            return false;
        
    }
    if(arr[arrLength-2] > arr[arrLength-1])
        return false;

    return true;
}

void bubbleSort(int arr[], int arrLength)
{
    bool swapped = false;
    do
    {
        swapped = false;
        for(int i=1;i<=arrLength-1;i++)
        {
            if(arr[i-1] > arr[i])
            {
                swap(arr, i, i-1);
                swapped = true;
            }
        }
    }while(!swapped);
}

//return the nth number in the fibonacci sequence
int fib(int num)
{
    int x = 0, y = 1, z = 0;
    for(int i=0;i<num-2;i++)
    {
        z=x+y;
        x=y;
        y=z;
    }

    return y;
}



int main(int argc, char *argv[])
{
    cout << "argc == " << argc << '\n';
    
    // int arr[] = {1,2,3,4,5,6};
    // swap(arr,2,3);
    // bubbleSort(arr,6);

    // for(int i=0;i<6;i++)
    //     cout << arr[i] << endl;

    // cout << fib(6);

    //int arr[] = {1};
    //cout << is_sorted(arr,1) << endl;

    //string test = "10000000";
    //cout << formatNumberCommas(test) << endl;

    BHeap h;
    h.Insert(5);
    h.Insert(7);
    h.Insert(1);
    h.Insert(15);
    h.showHeap();
    
    return argc == 3 ? EXIT_SUCCESS : EXIT_FAILURE; // optional return value
}



