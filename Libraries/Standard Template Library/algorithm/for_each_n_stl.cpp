// alg_for_each.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <iostream>
#include "../../DevTools/devtools.cpp"

using namespace std;
// The function object multiplies an element by a Factor
template <class Type>
class MultValue
{
private:
    Type Factor;   // The value to multiply by
public:
    // Constructor initializes the value to multiply by
    MultValue ( const Type& value ) : Factor ( value ) {
    }

    // The function call for the element to be multiplied
    void operator( ) ( Type& elem ) const
    {
        elem *= Factor;
    }
};

// The function object to determine the average
class Average
{
private:
    long num;      // The number of elements
    long sum;      // The sum of the elements
public:
    // Constructor initializes the value to multiply by
    Average( ) : num ( 0 ) , sum ( 0 )
    {
    }

    // The function call to process the next elment
    void operator( ) ( int elem )
    {
        num++;      // Increment the element count
        sum += elem;   // Add the value to the partial sum
    }

    // return Average
    operator double( )
    {
        return static_cast<double> (sum) /
            static_cast<double> (num);
    }
};

int main()
{
    using namespace std;
    // MultValue<int> a(-2); //A MultValue factor that multiplies another element by -2
    // int c = 5;
    // int &d = c;
    // a.operator()(d);
    
    vector<int> a = {1,2,3,4,5};
    for_each_n(a.begin(),3,MultValue<int>(-3));

    printListCSV(a);
    
    

}