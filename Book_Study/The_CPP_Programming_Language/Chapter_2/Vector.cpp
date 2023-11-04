#include "Vector.h";

using namespace std;

Vector::Vector(int s)
{
    if(s<0) throw bad_array_new_length{};
    elem = new double[s];
}

double& Vector::operator[](int i)
{
    if(i<0 || i > size()) throw out_of_range {"Vector operator[] out of bounds."};
    return elem[i];
}

int Vector::size()
{
    return sz;
}

int main()
{
    try{
        Vector v(-27);
    }
    catch(bad_array_new_length)
    {
        cout << "Bad length supplied to vector.";
        exit(1);
    }
}