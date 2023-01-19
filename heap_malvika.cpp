/*heap is a special ds in which tree is a complete binary tree  ( all levels completely filled and
                                                last levels have nodes as left as possible)
max heap
Min heap
Applications:  heapsort sorting     graph algos   prims algo   dijkstras
                priority queue

parent node  A[ (i-1)/2 ] returns parent node
 A[ 2*i+1]  returns left child node
 A[ 2*i+2]  returns right child node

  Operations
  getMini()     getMax()      extractMin()         insert()      delete()        heapify()
  o(1)            o(1)          o(logn)              o(logn)       o(logn)
  */
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
class MinHeap
{
public:
  int *hp;       // pointer to array
  int capacity;  // maximum possible size of minheap
  int heap_size; // current number of elements

  MinHeap(int cap)
  {
    heap_size = 0;
    capacity = cap;
    hp = new int[cap];
  }
  void insert(int k)
  {
    if (heap_size == capacity)
      cout << "Overflow\n";
    heap_size++;
    int i = heap_size - 1;
    hp[i] = k;
    while (i != 0 && hp[parent(i)] > hp[i])
    {
      swap(hp[parent(i)], hp[i]);
      i = parent(i);
    }
  }
  int parent(int i)
  {
    return (i - 1) / 2;
  }
  int linearSearch(int val)
  {
    for (int i = 0; i < heap_size; i++)
    {
      if (hp[i] == val)
      {
        cout << "Value found\n";
        return i;
      }
    }
    cout << "Value not found\n";
  }
  int extractMin() // removes minimum element from heap
  {
    if (heap_size <= 0)
      return INT_MAX;

    if (heap_size == 1)
    {
      heap_size--;
      return hp[0];
    }

    int root = hp[0];
    hp[0] = hp[heap_size - 1];
    heap_size--;
    MinHeapify(0);
    return root;
  }
  void MinHeapify(int i) // rearranges the tree
  {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && hp[l] < hp[i])
      smallest = l;
    if (r < heap_size && hp[r] < hp[smallest])
      smallest = r;
    if (smallest != i)
    {
      swap(hp[i], hp[smallest]);
      MinHeapify(smallest);
    }
  }
  int left(int i)
  {
    return 2 * i + 1;
  }
  int right(int i)
  {
    return 2 * i + 2;
  }
  void deleteNode(int val)
  {
    int x = linearSearch(val);
    decreasekey(x, INT_MIN);
    extractMin();
  }
  void decreasekey(int i, int new_val)
  {
    hp[i] = new_val;
    while (i != 0 && hp[parent(i)] > hp[i])
    {
      swap(hp[parent(i)], hp[i]);
      i = parent(i);
    }
  }
  int height()
  {
    return ceil(log2(heap_size + 1)) - 1;
  }
  void printArray()
  {
    for (int i = 0; i < heap_size; i++)
      cout << hp[i] << " ";
    cout << endl;
  }
};
int main()
{

  int s;
  cout << "Enter the size of min heap ";
  cin >> s;
  MinHeap obj(s);
  cout << "Min heap created" << endl;
  int op, val, x;
  do
  {
    cout << "Enter your choice\n";

    cout << "1 to insert\n";
    cout << "2 to search\n";
    cout << "3 to delete\n";
    cout << "4 to extract min\n";
    cout << "5 to height of heap\n";
    cout << "6 to print heap\n";
    cout << "0 exit\n";
    cin >> op;
    switch (op)
    {
    case 0:
      break;
    case 1:
      cout << "Enter the value to insert ";
      cin >> val;
      obj.insert(val);
      cout << endl;
      break;
    case 2:
      cout << "Enter the value to search ";
      cin >> val;
      cout << obj.linearSearch(val);
      cout << endl;
      break;
    case 3:
      cout << "Enter the value to delete ";
      cin >> val;
      obj.deleteNode(val);

      break;
    case 4:
      x = obj.extractMin();
      if (x == INT_MAX)
        cout << "No value to extractheap empty\n";
      else
        cout << x << endl;
      break;
    case 5:
      cout << obj.height() << endl;
      break;
    case 6:
      obj.printArray();
      break;
    default:
      cout << "wrong choice\n";
      break;
    }

  } while (op != 0);
  return 0;
}