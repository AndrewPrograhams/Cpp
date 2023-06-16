#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

template<class T>
class Bheap
{
    private:
        vector<T> arr;
        T l(int parent);
        T r(int parent);
        T par(int child);
        void heapifyup(int index);
        void heapifydown(int index);
        int size;


    public:
        Bheap() {
            size=0;
            arr.push_back(0);
        };
        void Insert(T &x);
        T Delete(T &x);
        T remove();
        T extractMax();
        int Size();
        T peek();
        bool isEmpty(){
            return size==0;
        }
};

template<class T>
T Bheap<T>::peek()
{
    return arr[0];
}

template<class T>
T Bheap<T>::extractMax()
{
    T tmp = arr[1];
    arr[1] = arr[size--];
    return tmp;
}

template<class T>
int Bheap<T>::Size()
{
    return arr.size;
}

template<class T>
void Bheap<T>::heapifydown(int index)
{
    
}

template<class T>
void Bheap<T>::heapifyup(int index)
{
    while(index > 0 && arr[par(index)] > arr[index])
    {
        swap(arr[par(index)],arr[index]);
        index=par(index);
    }
}

template<class T>
T Bheap<T>::l(int index)
{
    int l = 2*index+1;
    if(l<arr.size())
        return l;
    else
        return -1;
}

template<class T>
T Bheap<T>::r(int index)
{
    int r = 2*index+2;
    if(r<arr.size())
        return 1;
    else
        return -1;
}
template<class T>
T Bheap<T>::par(int index)
{
    return (index-1)/2;
}

int main(int argc, char* argv[])
{
    Bheap<int> a;
    return 0;
}