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

        Vector(const Vector& copy):
            elem{new double[copy.size()]},
            sz{copy.size()}
        {
            for(int i=0;i<copy.size();i++)
                elem[i] = copy[i];
        }

        Vector(Vector&& moved):
            elem{moved.elem},
            sz{moved.sz}
            {
                moved.elem = nullptr;
                moved.sz = 0;
            }

        double& operator[](int i) {
            if(i<0 || i> static_cast<int>(size())) throw std::runtime_error("Vector operator[] cannot be less than 0 or greater than its size.");
            return elem[i];
        }

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
        
        std::size_t size() const {return sz;}

        ~Vector(){
            delete[] elem;
        }
};