#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL

// O(n log n)
void buildHeap(vector<int> &v)
{

    for (int i = 2; i < v.size(); i++)
    {
        int idx = i;
        int parent = i / 2;

        while (idx > 1 && v[idx] > v[parent])
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }
}


//  o(N)
bool minHeap = false;
bool compare(int a, int b)
{
    if (minHeap)
        return a < b;

    return a > b;
}
void heapify(vector<int> &v, int idx)
{
    int left = 2 * idx;
    int right = 2 * idx + 1;

    int min_idx = idx;
    int last_idx = v.size() - 1;
    if (left <= last_idx && compare(v[left], v[min_idx]))
    {
        min_idx = left;
    }
    if (right <= last_idx && compare(v[right], v[min_idx]))
    {
        min_idx = right;
    }

    if (min_idx != idx)
    {
        swap(v[min_idx], v[idx]);
        heapify(v, min_idx);
    }
}

void optimizedBuildHeap(vector<int> &v)
{

    for (int i = (v.size() - 1) / 2; i >= 1; i--)
    {
        heapify(v, i);
    }
}

void print(vector<int> v)
{

    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> v{-1, 10, 20, 5, 6, 1, 8, 9, 4};
    print(v);
    buildHeap(v);
    print(v);
  // optimizedBuildHeap(v);
    // print(v);
    return 0;
}