#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <cmath>
#include <list>
using namespace std;

//prints a comma separated value string representing the contents of a list of generic objects
template <typename T> void printListCSV(list<T> list)
{   
    typename list<T>::iterator iter;
    for (iter = list.begin(); iter!=list.end(); iter++)
    {
        if(iter != prev(list.end()))
            cout << *iter << ",";
        else
            cout << *iter;
    }
}

template <typename T> void printListCSV(vector<T> v)
{
    typename vector<T>::iterator stl = prev(v.end());

    for(auto Iter=v.begin();Iter!=v.end();++Iter){
        if(Iter!=stl)
            cout << *Iter << ",";
        else
            cout << *Iter << endl;
    }
}

template <typename T> void printListCSV(T a[])
{
    if(a.length() == 0)
    {
        cout << "Array is empty." << endl;
        return;
    }
    else if(a.length() == 1)
    {
        cout << a[0] << endl;
        return;
    }
    for(int i=0;i<a.length();i++)
    {
        if(i==a.length()-1)
            cout << a[i];
        else
            cout << a[i] << ",";
    }
}

template <typename T> void print_t(T val)
{
    cout << val;
}

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

template<typename Type> void swap(Type arr[], int index_one, int index_two)
{
    Type one = arr[index_one];
    arr[index_one] = arr[index_two];
    arr[index_two] = one;
}

template<typename Type> void swap(vector<Type> v, int index_one, int index_two)
{
    Type one = v[index_one];
    v[index_one] = v[index_two];
    v[index_two] = one;
}

template<typename Type> void swap(list<Type> l, int index_one, int index_two)
{
    Type one = l[index_one];
    l[index_one] = l[index_two];
    l[index_two] = one;
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