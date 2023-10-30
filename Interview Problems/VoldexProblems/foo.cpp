#include <vector>
#include <iostream>
#include <tuple>
#include <optional>

using namespace std;

optional<pair<int,int>> largest(std::vector<int> array)
{
    if(array.size() <= 1)
    {
        cout << "Array has less than 1 element." << endl;
        return nullopt;
    }
    int largest = array[0];
    int secondLargest = array[0];
    int prev = array[0];

    for(int i = 0; i < array.size(); i++){

        cout << "Array at index " << i << " has value " << array[i] << endl;

        if(array[i]>largest){
            largest = array[i]; 
            if(prev > secondLargest)
                secondLargest = prev;
        }   

        if(array[i] > secondLargest && array[i] < largest){
            secondLargest = array[i];
            cout << secondLargest << endl;
        }        

        prev = array[i];
           
   } 
    return pair<int,int>(largest,secondLargest);
}

int main()
{
    std::vector<int> test;

    for(int i=0;i<5;i++)
        test.push_back(i);

    optional<pair<int,int>> result = largest(test);

    if(result)
        cout << get<0>(*result) << " , " << get<1>(*result) << endl;
    
    else
        cout << "Largest function returned invalid input." << endl;
}