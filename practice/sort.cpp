#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>&ar, int n){
    for(int i=0;i<n-1;i++){
        int min_idx = i;
        for(int j = i+1;j<n;j++){
            if(ar[j] < ar[min_idx]){
                min_idx = j;
            }
        }
        swap(ar[i], ar[min_idx]);
    }
}
void insertionSort(vector<int>&ar, int n){
    for(int i=1;i<n;i++){
        int val = ar[i];
        int j = i;
        while(j>0 && ar[j-1] > ar[i]){
            ar[j] = ar[j-1];
            j--;
        }
        ar[j] = val;
    }
}
void bubble_sort(vector<int>ar, int n){
    for(int i=0;i<n-1;i++){
        for(int j = 0;j<n-i-1;j++){
            if(ar[j] > ar[j+1])
                swap(ar[j], ar[j+1]);
        }
    }
}

void merge(int ar[], int s, int e){
    int mid = (s+e)/2;
    int i  =s;
    int j = mid+1;
    int k = s;
    int temp[e-s+1];
    while(i<=mid && j<=e){
        if(ar[i] < ar[j]){
            temp[k++] = ar[i++];
        }
        else {
            temp[k++] = ar[j++];
        }
    }
    while(i<=mid){
        temp[k++]  = ar[i++];
    }
    while(j<= e){
        temp[k++] = ar[j++];
    }
    for(int i=s;i<=e;i++){
        ar[i] = temp[i-s];
    }
}
void merge_sort(int ar[], int s, int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    merge_sort(ar, s, mid);
    merge_sort(ar, mid+1, e);
    merge(ar, s, e);
}

int parition(int a[], int start, int end){
    int pivot = a[end];
    int pIndex = start;
    for(int i = start;i<end;i++){
        if(a[i] <= pivot){
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    swap(a[pIndex], a[end]);
    return pIndex;
}
void quick_sort(int a[], int s, int e){
    if(s >=e){
        return;
    }
    int pivot = partition(a, s, e);
    quick_sort(a, start, pivot-1);
    quick_sort(a, pivot +1, e);
}

bool minHeap = false;

void heapify(int ar[], int n, int i){

}
void heapSort(int ar[], int n){
    for(int i =n/2-1;i>=0;i--){
        heapify(ar, n, i);
    }
    for(int i= n-1;i>0;i--){
        swap(ar[0], ar[i]);
        heapify(ar, i, 0);
    }
}
int main(){



    return 0;
}