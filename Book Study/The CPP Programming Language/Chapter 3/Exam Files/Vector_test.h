#include <iostream>
#include <exception>

using namespace std;

class Vector{
    public:
        Vector(int s);
        double& operator[](int i);
        int size() const;
    private:
        double* elem;
        int sz;
};