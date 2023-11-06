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

                const double& operator[](int i) const {
            if(i<0 || i> static_cast<int>(size())) throw std::runtime_error("Vector operator[] cannot be less than 0 or greater than its size.");
            return elem[i];
        }

        // copy assignment operator
        Vector& operator=(const Vector& assigner){
            if(this!=&assigner)
            {
                double* p = new double[assigner.size()];
                for(std::size_t i=0; i<assigner.size();i++)
                    p[i] = assigner[i];
                delete[] elem;
                elem = p;
                sz = assigner.size();
            }
            return *this;
        }
        
        Vector& operator=(Vector&& moved) noexcept
        {
            if(this!=&moved)
            {
                delete[] elem;

                elem = moved.elem;
                sz = moved.size();
                
                moved.elem = nullptr;
                moved.sz = 0;
            }

            return *this;
        }

        // Copy constructor
        Vector(const Vector& copy):
            elem{new double[copy.size()]},
            sz{copy.size()}
        {
            for(int i=0;i<copy.size();i++)
                elem[i] = copy[i];
        }
        // Move constructor
        Vector(Vector&& moved):
            elem{moved.elem},
            sz{moved.sz}
            {
                moved.elem = nullptr;
                moved.sz = 0;
            }

    private:
        double* elem;
        std::size_t sz;
};