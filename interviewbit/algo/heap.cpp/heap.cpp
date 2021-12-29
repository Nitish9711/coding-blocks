#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define null NULL

class Heap
{
    vector<int> v;
    bool minHeap;

    bool compare(int a, int b)
    {

        if (minHeap)
            return a < b;

        return a > b;
    }

    void heapify(int idx)
    {
        int leftChild = 2*idx;
        int rightChild = 2*idx + 1;

        int min_idx  = idx;
        int last_idx = v.size()-1;
        
        if(leftChild<= last_idx && compare(v[leftChild], v[min_idx])){
            min_idx = leftChild;

        }
        if(rightChild <=last_idx && compare(v[rightChild] , v[min_idx])){
            min_idx = rightChild;
        }

        if(min_idx != idx){
            swap(v[min_idx], v[idx]);
            heapify(min_idx);
        }

    }

public:
    Heap(int default_size = 10, bool type = true)
    {
        v.reserve(default_size);
        minHeap = type;
        v.push_back(-1);
    }

    void push(int d)
    {
        v.push_back(d);
        int idx = v.size() - 1;
        int parent = idx / 2;
        while (idx > 1 && compare(v[idx], v[parent]))
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }
    void pop()
    {
        int last = v.size() - 1;
        swap(v[last], v[1]);
        v.pop_back();
        heapify(1);
    }
    int top()
    {
        return v[1];
    }

    bool empty()
    {
        return v.size() == 1;
    }
};

int main()
{

      Heap h(10);
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int no;
        cin>>no;
        h.push(no);
    }

    while (!h.empty())
    {
        cout<<h.top()<<" ";
        h.pop();
    }
    

    return 0;
}