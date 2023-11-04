#include "Vector_container.h"

using namespace std;

void use(Container& c)
{
    const int sz = c.size();

    for(int i=0;i != sz; i++)
        cout << c[i] << endl;
}

int main()
{
    Vector_container vc = {1,2,3,4,5,6};
    use(vc);
}