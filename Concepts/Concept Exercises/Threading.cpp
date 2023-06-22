#include <thread>
#include <algorithm>
#include <vector>
#include <list>
#include <random>
#include "../../Libraries\DevTools\devtools.cpp"

using namespace std;

static bool v_Go = true;
static bool l_Go = false;

/*
    Goal: Write a threading program that concurrently sorts a list of integers and a vector of integers.
          After each sort operation, print the contents of each container.
*/

void workList(list<int> l)
{
    sort(l.begin(),l.end(),[=](int one, int two){
        
        v_Go = false;

        printListCSV(l);

        //wait until vectorWork has finished.
        while(!l_Go)
            this_thread::sleep_for(1000ms);

        v_Go = true;
        
        return one < two;
    });
}

void workVector(vector<int> v)
{
    sort(v.begin(),v.end(),[=](int one, int two){
        //print the current list
        printListCSV(v);
        l_Go = false;

        //wait for other thread to allow this thread to continue.
        while(!v_Go)
            this_thread::sleep_for(1000ms);

        l_Go = true;
        
        return one < two;
    });
}

int main()
{
    
    vector<int> v;
    list<int> l;

    for(int i=0;i<25;i++)
        v.push_back(i);
    
    auto rd = random_device{};
    mt19937 g(rd());

    shuffle(v.begin(),v.end(),g);
    
    for(int i=0;i<25;i++)
        l.push_back(i);
        
    shuffle(l.begin(),l.end(),g);

    thread vThread(workVector,v);

    thread lThread(workList,l);
    

    lThread.join();
    vThread.join();

    
}