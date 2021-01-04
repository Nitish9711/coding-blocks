#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL


bool minHeap = false;
 bool compare(int a, int b){
        if(minHeap)
            return a < b;

        return b > a;
    }

void heapify(vector<int>&v, int idx, int size){
    int left = 2*idx;
    int right = 2*idx + 1;

    int last = size - 1;
    int min_idx = idx;
    if(left <= last && compare(v[left], v[min_idx])){
        min_idx = left;
    }
    if(right <= last && compare(v[right], v[min_idx])){
        min_idx = right;
    }

    if (min_idx != idx)
    {
        swap(v[min_idx], v[idx]);
        heapify(v, min_idx , size);
    }

}
void buildHeap(vector<int>&v){

    int n = v.size();
    for(int i = (v.size() - 1)/2 ; i>=1;i--){
        heapify(v, i , n); 
    }


}


void heapsort(vector<int>&v){
    buildHeap(v);

    int n = v.size();
    while (n >1)
    {
        swap(v[1], v[n-1]);
        n--;
        heapify(v, 1,n);
    }
    
}

void print(vector<int>v){
    for(int x:v){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> v{ -1 , 10, 20, 50, 6, 1, 8, 9, 4};
    print(v);
    
    heapsort(v);
    print(v);


    return 0;
}