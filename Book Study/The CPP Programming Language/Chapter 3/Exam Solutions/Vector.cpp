#include "Vector.h";

using namespace std;

double& Vector::operator[](int i)
{
    if(i<0 || i > size()) throw out_of_range {"Vector operator[] out of bounds."};
    return elem[i];
}

// Vector& Vector::read(istream& is)
// {
//     for(double d; is>>d;)
//        push_back(d);

//    return *this;
// }

int Vector::size() const
{
    return sz;
}