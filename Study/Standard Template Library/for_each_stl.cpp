#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

// A second set of parentheses indicates an override of the function with values defined in the first parenthesis.
// see : https://cplusplus.com/forum/beginner/45281/ 

template <class Type>
class MultValue
{
    private:
        Type Factor;
    public:
    MultValue(const Type& value) : Factor ( value ){
    }

    //The function call for the elment to be multiplied
    void operator() (Type& elem) const
    {
        elem*=Factor;
    }
};