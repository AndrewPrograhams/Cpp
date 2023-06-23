#include <thread>
#include <vector>
#include <algorithm>
#include "../Libraries/DevTools/devtools.cpp"

using namespace std;

void doubleVectorValues(const vector<int>& vec, vector<int>& out_vec)
{
    vector<int> local_copy(vec);
    for_each(local_copy.begin(), local_copy.end(), [&](int& elem) {
        elem *= 2;
        out_vec.push_back(elem);
    });
}

void tripleVectorValues(const vector<int>& vec, vector<int>& out_vec)
{
    vector<int> local_copy(vec);
    for_each(local_copy.begin(), local_copy.end(), [&](int& elem) {
        elem *= 3;
        out_vec.push_back(elem);
    });
}

int main()
{    
    vector<int> v = {1, 2, 3, 4, 5};
    
    vector<int> out_one;
    vector<int> out_two;

    thread t1(doubleVectorValues, cref(v), ref(out_one)); 
    thread t2(tripleVectorValues, cref(v), ref(out_two));

    t1.join();
    t2.join();

    printListCSV(out_one);
    printListCSV(out_two);

    return 0;
}