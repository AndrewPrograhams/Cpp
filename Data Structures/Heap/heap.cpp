/*
Interview::::

Tuesday/Wednesday/Thursday
C++ and Java Data Structure implementations with templates/generics
ArrayList, LinkedList, Heap, Priority Queue, HashMap, Graph, Grid

Java Algorithms
A*
Bracket Combinations
Permutations/Combinations
am-pm minutes algorithm


*/


#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
using namespace std;
class BHeap {
   private:
   vector <int> heap;
   int l(int parent);
   int r(int parent);
   int par(int child);
   void heapifyup(int index);
   void heapifydown(int index);
   public:
      BHeap() {}
      void Insert(int element);
      void DeleteMin();
      int ExtractMin();
      void showHeap();
      int Size();
};
// int main() {
//    BHeap h;
//     h.Insert(5);
//     h.Insert(7);
//     h.Insert(1);
//     h.Insert(15);
//     h.showHeap();
//    return 0;
// }
int BHeap::Size() {
   return heap.size();
}
void BHeap::Insert(int ele) {
   heap.push_back(ele);
   heapifyup(heap.size() -1);
}
void BHeap::DeleteMin() {
   if (heap.size() == 0) {
      cout<<"Heap is Empty"<<endl;
      return;
   }
   heap[0] = heap.at(heap.size() - 1);
   heap.pop_back();
   heapifydown(0);
   cout<<"Element Deleted"<<endl;
}
int BHeap::ExtractMin() {
   if (heap.size() == 0) {
      return -1;
   }
   else
   return heap.front();
}
/**
 * Prints the heap.
*/
void BHeap::showHeap() {
   vector <int>::iterator pos = heap.begin();
   cout<<"Heap --> ";
   while (pos != heap.end()) {
      cout<<*pos<<" ";
      pos++;
   }
   cout<<endl;
}
/**
 * Returns the left child's index of a given parent.
*/
int BHeap::l(int parent) {
   int l = 2 * parent + 1;
   if (l < heap.size())
      return l;
   else
      return -1;
}
/**
 * Gets the right child of the parent node. 
*/
int BHeap::r(int parent) {
   int r = 2 * parent + 2;
   if (r < heap.size())
      return r;
   else
      return -1;
}

/**
 * The parent function returns the parent of a child node.
*/

int BHeap::par(int child) {
   int p = (child - 1)/2; 
   if (child == 0)
      return -1;
   else
      return p;
}

/*
Two operations for priority queues and heaps that are required to maintain the heap property
are bubble up and bubble down (heapifyup/heapifydown). The access the element at the given index
inside the underlying array structure using the parent method. By heapifying up and down, we can
ensure that the max or min element is always at the top, and that left children are less than the
parent and the right children are greater than the parent. This is all to ensure constant time retrieval
of the min or max element and log(n) times for adding to the heap. 
*/

void BHeap::heapifyup(int in) {

   // if the index and the partition of the index are valid
   // and the element at the partitioned index is greater than the element in the index
   if (in >= 0 && par(in) >= 0 && heap[par(in)] > heap[in]) 
    {
      //do a swap between heap[in] and heap[par(in)]
      int temp = heap[in];
      heap[in] = heap[par(in)];
      heap[par(in)] = temp;
      heapifyup(par(in));
   }
}

void BHeap::heapifydown(int in) {
   int child = l(in);
   int child1 = r(in);
   //if the left child is greater than the right child, bubble down the right child
   if (child >= 0 && child1 >= 0 && heap[child] > heap[child1]) {
      child = child1;
   }
   //if the item at the index is greater than what we want to bubble down
   if (child > 0 && heap[in] > heap[child]) {
      //swap the parent with the child
      int t = heap[in];
      heap[in] = heap[child];
      heap[child] = t;
      heapifydown(child);
   }
}

int main(int argc, char* argv[])
{
    BHeap a;
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

    //a.Show();
    return 0;
}
