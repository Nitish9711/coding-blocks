#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL
#define vi vector<int>
#define vl vector<ll>
#define moi map<int, int>
#define umoi unordered_map<int, int>
#define mol map<ll, ll>
#define umol unordered_map<ll, ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define psi pair<string, int>
#define pis pair<int, string>
#define vp vector<pair<int, int>>

void ReadCP()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void selection_sort(vector<int>&ar, int n){
    for(int i=0;i<n-1;i++){
        int min_idx = i;
        for(int j =i+1;j<n;j++){
            if(ar[j] < ar[min_idx])
                min_idx = j;
        }
        swap(ar[i], ar[min_idx]);
    }

}

void insertion_sort(vector<int>&ar, int n){
    for(int i=1;i<n;i++){
        int val = ar[i];
        int j =i;
        while(j> 0 && ar[j-1] > ar[i]){
            ar[j] = ar[j-1];
            j--;
        }
        ar[j] = val;
    }
}
void bubble_sort(vector<int>&ar, int n){
    for(int i=0;i<n-1;i++){
        for(int j =0;j<n-i-1;j++){
            if(ar[j] > ar[j+1])
                swap(ar[j], ar[j+1]);
        }
    }
}

void merge(int ar[], int s, int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;
    int temp[500];
    while(i<=mid && j <=e){
        if(ar[i] < ar[j]){
            temp[k++] = ar[i++];
        }
        else{
            temp[k++] = ar[j++];
        }
    }
    while(i<=mid){
        temp[k++] = ar[i++];
    }
    while(j<=e){
        temp[k++] = ar[j++];
    }
    for(int i= s;i<=e;i++){
        ar[i] = temp[i];
    }
}
void merge_sort(int ar[], int s, int e){
    if(s>=e)
        return;
    int mid = (s+e)/2;
    merge_sort(ar, s, mid);
    merge_sort(ar, mid+1 ,e);
    merge(ar, s, e);
}

int partition(int ar[], int s, int e){
    int i = s-1;
    int j = s;

    int pivot = ar[e];
    for(;j<=e-1;){
        if(ar[j]<=pivot){
            //merge the smaller element in the region
            i= i+1;
            swap(ar[i], ar[j]);
        }
        // expanding the larger region
        j+1;
    }
    //inplace the pivot element in th corrct place//
    swap(ar[i+1], ar[e]);
    return i+1;
}
void quick_sort(int ar[], int s, int e){
    if(s >=e)
        return;
    int p = partition(ar, s, e);
    quick_sort(ar, s, p-1);
    quick_sort(ar, p+1,e);
}
// one based indexing
bool minHeap = false;
bool compare(int a, int b){
    if(minHeap)
        return a < b;
    return a > b;
}
void heapify(vector<int>&v, int idx, int size){
    int left = 2*idx;
    int right = 2*idx + 1;
    int last = size-1;
    int min_idx = idx;
    if(left <=last && compare(v[left], v[min_idx]))
        min_idx = left;
    if(right <=last && compare(v[right], v[min_idx]))
        min_idx = right;
    if(min_idx!= idx){
        swap(v[min_idx], v[idx]);
        heapify(v, min_idx, size);
    }
}

void heap_sort(vector<int>&v){
    
    int n = v.size();
    for(int i = (v.size()-1)/2;i>=1;i--){
        heapify(v, i, n);
    }
  
    while(n>1){
        swap(v[1], v[n-1]);
        n--;
        heapify(v, 1, n);
    }
}


void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i = n - 1; i > 0; i--) {
     
        swap(arr[0], arr[i]);    
        heapify(arr, i, 0);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ReadCP();
   
    
    return 0;
}