#include "Vector.h"

using namespace std;

double& Vector::operator[](int i)
{
    if(i<0 || i > size()) throw out_of_range {"Vector operator[] out of bounds."};
    return elem[i];
}

int Vector::size() const
{
    return sz;
}

// int main()
// {
//     Vector v ={1.0,2.0,3.0,4.0,5.0};
//     cout << v[2];
// }