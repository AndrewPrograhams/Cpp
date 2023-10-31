#include <iostream>
#include <exception>
#include <initializer_list>
#include <istream>
#include <algorithm>

class Vector{
    public:
        Vector(int s)
            :elem{new double[s]}, sz{s} 
            {
                if(s<0) throw bad_array_new_length();
                for(int i=0; i != s; i++) elem[s] = 0;
            };
        Vector(initializer_list<double> lst)
            :elem{new double[lst.size()]}, sz{lst.size()} 
            {
                copy(lst.begin(),lst.end(),elem); // copy elements from {}- type to elem.
            };

        
        double& operator[](int i);
        Vector& read(istream& s);
        int size() const;

    private:
        double* elem;
        int sz;
};