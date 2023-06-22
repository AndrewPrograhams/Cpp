#include <iostream>

using namespace std;

//function that takes two int references, adds them, and then stores them in a.
//Throws an exception if the values of the references are less than zero.
void combinePositiveIntegersRef(int &a, int &b)
{
    if(a < 0 || b < 0)
        throw invalid_argument("AddPositiveIntegers arguments must be positive");

    a+=b;
}

//function that takes two int values and adds them.
//throws an exception if the values are less than 0.
void combinePositiveIntegers(int a, int b)
{
    if(a < 0 || b < 0)
        throw invalid_argument("AddPositiveIntegers arguments must be positive");

    a+=b;
}

int main()
{
    int valOne = 5;
    int valTwo = 10;
    
    int &a = valOne;
    int &b = valTwo;

    try
    {
            
        combinePositiveIntegers(a,b);
        cout << a << endl;

        combinePositiveIntegersRef(a,b);
        cout << a << endl;

        combinePositiveIntegers(a,-5);
        cout << a << endl;
    
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }

    
}