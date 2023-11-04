#include <iostream>
#include <exception>
#include <initializer_list>
#include <istream>
#include <algorithm>
#include <new>
#include <cstddef> // For size_t 

using namespace std;

class Vector{
    public:
        Vector(int s)
            :elem{new double[s]}, sz{static_cast<size_t>(s)} 
            {
                if(s<0) throw std::bad_array_new_length();
                for(int i=0; i != s; i++) elem[i] = 0;
            }
        Vector(initializer_list<double> lst)
            :elem{new double[lst.size()]}, sz{lst.size()} 
            {
                std::copy(lst.begin(),lst.end(),elem); // copy elements from {}- type to elem.
            }

        
        double& operator[](int i) 
            {    if(i<0 || i > size()) throw out_of_range {"Vector operator[] out of bounds."};
                return elem[i]; }
        int size() const {return sz;}
        ~Vector() {delete elem;}

    private:
        double* elem;
        std::size_t sz;
};