#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <mutex>
#include "../Libraries/DevTools/devtools.cpp"

using namespace std;

void doubleVectorValues(const vector<int>& vec, vector<int>& out_vec, mutex& mtx)
{
    vector<int> local_copy(vec.begin(), vec.end());  // Create a local copy of vec

    for_each(local_copy.begin(), local_copy.end(), [&](int elem) {
        elem *= 2;

        lock_guard<mutex> lock(mtx);  // Lock the mutex for modifying out_vec
        out_vec.push_back(elem);
    });
}

void tripleVectorValues(const vector<int>& vec, vector<int>& out_vec, mutex& mtx)
{
    vector<int> local_copy(vec.begin(), vec.end());  // Create a local copy of vec

    for_each(local_copy.begin(), local_copy.end(), [&](int elem) {
        elem *= 3;

        lock_guard<mutex> lock(mtx);  // Lock the mutex for modifying out_vec
        out_vec.push_back(elem);
    });
}

int main()
{    
    vector<int> v = {1, 2, 3, 4, 5};
    
    vector<int> out_one;
    vector<int> out_two;

    mutex out_vec_mutex;

    thread t1(doubleVectorValues, v, ref(out_one), ref(out_vec_mutex));
    thread t2(tripleVectorValues, v, ref(out_two), ref(out_vec_mutex));

    t1.join();
    t2.join();

    printListCSV(out_one);
    printListCSV(out_two);

    return 0;
}