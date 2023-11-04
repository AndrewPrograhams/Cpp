#include "container.h"
#include "Vector.h"

using namespace std;

class Vector_container : public Container{
    private:
        Vector v;
    public:
        Vector_container(int s) : v(s) { }
        Vector_container(initializer_list<double> lst)
            :v(lst) {}
        ~Vector_container(){}

        double& operator[](int i) override { return v[i]; }
        int size() const { return v.size(); }
};