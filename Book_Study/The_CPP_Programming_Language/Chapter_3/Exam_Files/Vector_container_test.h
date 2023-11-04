#include "Vector_test.h"
#include "container_test.h"

class Vector_container: public Container{
    private:
        Vector v;
    public:
        Vector_container(int s): v(s) {};
        ~Vector_container();

        Vector_container& operator=(const Vector_container& copy)
        {
            if(this!=&copy)
                v = copy.v;
            
            return *this;
        }

        Vector& operator=(Vector&& moved)
        {

        }

        double& operator[](int index){ return v[index]; }
        std::size_t size() const {return v.size();}
};