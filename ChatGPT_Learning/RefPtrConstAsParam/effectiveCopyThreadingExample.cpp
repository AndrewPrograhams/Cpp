#include <thread>
#include <vector>
#include <algorithm>

using namespace std;

void doubleVectorValues(vector<int> vec, vector<int>& out_vec)
{
    for_each(vec.begin(),vec.end(),[&](int elem){
        elem *= 2;
        out_vec.push_back(elem);
    });
}

void tripleVectorValues(vector<int> vec, vector<int>& out_vec)
{
    for_each(vec.begin(),vec.end(),[](int elem){
        elem*=3;
    });
}

int main()
{    
    vector<int> v = {1,2,3,4,5};
    
    vector<int> out_one;
    vector<int> out_two;

    /* In the following two threads we pass v as a copy instead of a reference to ensure thread safety. We don't want one thread to modify the contents of v while the other is using it. */
    /* Note that because we have two separate output vectors for out_one and two
    thread t1(doubleVectorValues(v)); 

    thread t2(tripleVectorValues(v)); */
    

}