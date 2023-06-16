#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
using namespace std;

//template <class T>
class CppHeap{
    private:
        void heapifyup(int index);
        void heapifydown(int index);
        int l(int parent);
        int r(int parent);
        int par(int child);
        int hsize;
        vector<int> heap;

    public:
        CppHeap() {};
        int ExtractMin();
        void DeleteMin();
        int Get(int index);
        int Size();
        void Insert(int ele);
        void Show();
};

/**
 * Private
*/

void CppHeap::heapifyup(int in)
{
    if(in >= 0 && par(in) >= 0 && heap[par(in)] > heap[in])
    {
        int temp = heap[in];
        heap[in] = heap[par(in)];
        heap[par(in)] = temp;
        heapifyup(par(in));
    }
}

void CppHeap::heapifydown(int index)
{
    int childl = l(index);
    int childr = r(index);

    if(childl >= 0 && childr >= 0 && heap[childl] > heap[childr])
        childl = childr;
    
    if(childl >=0 && heap[index] > heap[childl])
    {
        int temp = heap[index];
        heap[index] = heap[childl];
        heap[childl] = temp;
        heapifydown(childl);
    }
}

int CppHeap::l(int parent)
{
    int l = 2*parent+1;
    if(l < heap.size())
        return l;
    else
        return -1;
}
int CppHeap::r(int parent)
{
    int r = 2*parent+2;
    if(r < heap.size())
        return 1;
    else
        return -1;
}
int CppHeap::par(int child)
{
    int p = (child-1)/2;
    if(child==0)
        return -1;
    else
        return p;
}

/**
 * Public
*/
// CppHeap::CppHeap()
// {
//     hsize = 0;
//     heap.push_back(0);
// }

int CppHeap::ExtractMin()
{
    if(heap.size()==0)
        return -1;
    else
        return heap.front();
}

void CppHeap::DeleteMin()
{
    if(heap.size()==0)
    {
        cout << "Heap is empty" << endl;
        return;
    }
    heap[0] = heap.at(heap.size()-1); // replace the min with the its left child
    heap.pop_back(); //remove the last element in the underlying data structure
    heapifydown(0); //send
    cout << "element deleted" << endl;
}

int CppHeap::Size()
{
    return heap.size();
}

void CppHeap::Insert(int ele)
{
    heap.push_back(ele);
    heapifyup(heap.size()-1);
}

void CppHeap::Show()
{
   vector <int>::iterator pos = heap.begin();
   cout<<"Heap --> ";
   while (pos != heap.end()) {
      cout<<*pos<<" ";
      pos++;
   }
   cout<<endl;
}

/**
 * Main function
*/

int main(int argc, char* argv[])
{
    CppHeap a;
        a.Insert(4);
        a.Insert(1);
        a.Insert(2);
        a.Insert(12);
        a.Insert(4);
        a.Insert(19);
        a.Insert(6);
    int g = a.ExtractMin();
    cout << g << endl;
    a.DeleteMin();
    g = a.ExtractMin();
    cout << g << endl;

    a.Show();
    return 0;
}
