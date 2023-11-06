#include <exception>
#include <stdexcept>
#include "container_test.h"

class Vector: public Container{
    private:
        double* elem;
        std::size_t sz;
    public:
        Vector(int s):
            elem{new double[sz]}, sz{s}{
                if(s<0) throw std::bad_array_new_length();
            }

        double& operator[](int i) {
            if(i<0 || i> static_cast<int>(size())) throw std::runtime_error("Vector operator[] cannot be less than 0 or greater than its size.");
            return elem[i];
        }

        //const access operator
        const double& operator[](int i) const
        {
            if(i < 0 || i > size()) throw std::out_of_range("Vector [] operation out of bounds.");
            return elem[i];
        }

        Vector(Vector&& moved):
            elem{moved.elem},
            sz{moved.size()}
        {
                moved.elem = nullptr;
                moved.sz = 0;
        }
        
        Vector& operator=(Vector&& moved)
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
        
        // copy constructor
        Vector(const Vector& copy):
            elem{new double[copy.size()]},
            sz{copy.size()}
        {
            for(int i=0;i<copy.size();i++)
                elem[i] = copy[i];
            
        }

        // copy assignment
        Vector& operator=(const Vector& copy)
        {
            if(this!=&copy)
            {
                double* p = new double[copy.size()];
                for(int i=0; i<copy.size(); i++)
                    p[i] = copy[i];
                
                delete[] elem;
                elem = p;
                sz = copy.size();
            }
            return *this;
        }
        

        std::size_t size() const {return sz;}

        ~Vector(){
            delete[] elem;
        }
};