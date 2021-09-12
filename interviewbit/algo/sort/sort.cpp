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


// Algorithm	               Best	             Average	               Worst
// Quick Sort           	Ω(n log(n))	       Θ(n log(n))	              O(n^2)
// Bubble Sort	            Ω(n)	           Θ(n^2)	                  O(n^2)
// Merge Sort              Ω(n log(n))	       Θ(n log(n))	              O(n log(n))
// Insertion Sort	        Ω(n)	           Θ(n^2)	                  O(n^2)
// Selection Sort       	Ω(n^2)	           Θ(n^2)	                  O(n^2)
// Heap Sort	            Ω(n log(n))	       Θ(n log(n))                O(n log(n))
// Radix Sort	            Ω(nk)	           Θ(nk)	                  O(nk)
// Bucket Sort          	Ω(n+k)	           Θ(n+k)	                  O(n^2)

//selection sort
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


//insertion sort
// best case - when array is is_sorted
// worst case - when array is reverse sorted
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

//bubble sort
// best case - when array is is_sorted
void bubble_sort(vector<int>&ar, int n){
    for(int i=0;i<n-1;i++){
        for(int j =0;j<n-i-1;j++){
            if(ar[j] > ar[j+1])
                swap(ar[j], ar[j+1]);
        }
    }
}


// merge sort
// with recursion top down
void merge(int ar[], int s, int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;
    // int temp[500];
    int temp[e-s+1];
    k =0;
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
        ar[i] = temp[i-s];
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
//bottom up merge sort
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 
// #define N 10
 
// // Utility function to find a minimum of two numbers
// int min(int x, int y) {
//     return (x < y) ? x : y;
// }
 
// // Merge two sorted subarrays `A[from…mid]` and `A[mid+1…to]`
// void merge(int A[], int temp[], int from, int mid, int to)
// {
//     int k = from, i = from, j = mid + 1;
 
//     // loop till no elements are left in the left and right runs
//     while (i <= mid && j <= to)
//     {
//         if (A[i] < A[j]) {
//             temp[k++] = A[i++];
//         }
//         else {
//             temp[k++] = A[j++];
//         }
//     }
 
//     // copy remaining elements
//     while (i < N && i <= mid) {
//         temp[k++] = A[i++];
//     }
 
//     /* no need to copy the second half (since the remaining items
//        are already in their correct position in the temporary array) */
 
//     // copy back to the original array to reflect sorted order
//     for (int i = from; i <= to; i++) {
//         A[i] = temp[i];
//     }
// }
 
// // Iteratively sort subarray `A[low…high]` using a temporary array
// void mergesort(int A[], int temp[], int low, int high)
// {
//     // divide the array into blocks of size `m`
//     // m = [1, 2, 4, 8, 16…]
//     for (int m = 1; m <= high - low; m = 2*m)
//     {
//         // for m = 1, i = 0, 2, 4, 6, 8…
//         // for m = 2, i = 0, 4, 8…
//         // for m = 4, i = 0, 8…
//         // …
//         for (int i = low; i < high; i += 2*m)
//         {
//             int from = i;
//             int mid = i + m - 1;
//             int to = min(i + 2*m - 1, high);
 
//             merge(A, temp, from, mid, to);
//         }
//     }
// }
 
// // Utility function to print a given array
// int printArray(int A[])
// {
//     for (int i = 0; i < N; i++) {
//         printf("%d ", A[i]);
//     }
 
//     printf("\n");
// }
 
// Iterative implementation of merge sort
int main()
{
    // int A[N], temp[N];
    // srand(time(NULL));
 
    // // generate random input of integers
    // for (int i = 0; i < N; i++) {
    //     temp[i] = A[i] = (rand() % 50);
    // }
 
    // printf("Original array: ");
    // printArray(A);
 
    // // sort array `A[0…N-1]` using a temporary array temp
    // mergesort(A, temp, 0, N - 1);
 
    // printf("Modified array: ");
    // printArray(A);
 
    return 0;
}




//quick sort
//  The worst-case time complexity of Quicksort is o(n2). The worst case happens when the pivot happens 
// to be the smallest or 
//  largest element in the list or when all the array elements are equal. This will result in the most 
//  unbalanced partition as the pivot divides the array into two subarrays of sizes 0 and n-1
// . If this repeatedly happens in every partition (say, we have sorted array), 
// then each recursive call processes a list of size one less than the previous list, resulting in 


//auxillary space for call stack O(n)
// The space complexity is calculated based on the space used in the recursion stack. 
// The worst case space used will be O(n) . The average case space used will be of the order O(log n). 
// The worst case space complexity becomes O(n), when the algorithm encounters its worst 
// case where for getting a sorted list, we need to make n recursive calls.

// Partition using the Lomuto partition scheme
// Quick sort is an inplace algorithm which means the numbers are all sorted within the original array itself.

// Why Quick Sort is better than Merge Sort?

// Auxiliary Space : Quick sort is an in-place sorting algorithm whereas Merge sort uses extra space. 
// In-place sorting means no additional storage space is used to perform sorting (except recursion stack).
//  Merge sort requires a new temporary array to merge the sorted arrays thereby making Quick sort the better
//   option.
// Worst Cases : The worst case runtime of quick sort is O(n2) can be avoided by using randomized
//  quicksort as explained in the previous point. Obtaining average case behavior by choosing random pivot element improves the performance and becomes as efficient as merge sort.
// Cache Friendly: Quick Sort is also a cache friendly sorting algorithm as it has good locality of
//  reference when used for arrays.


int partition(int a[], int start, int end)
{
    // Pick the rightmost element as a pivot from the array
    int pivot = a[end];
    // elements less than the pivot will be pushed to the left of `pIndex`
    // elements more than the pivot will be pushed to the right of `pIndex`
    // equal elements can go either way
    int pIndex = start;
    // each time we find an element less than or equal to the pivot, `pIndex`
    // is incremented, and that element would be placed before the pivot.
    for (int i = start; i < end; i++)
    {
        if (a[i] <= pivot)
        {   swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    // swap `pIndex` with pivot
    swap (a[pIndex], a[end]);
    // return `pIndex` (index of the pivot element)
    return pIndex;
}
// Quicksort routine
void quicksort(int a[], int start, int end)
{
    // base condition
    if (start >= end) {
        return;
    }
    // rearrange elements across pivot
    int pivot = partition(a, start, end);
    // recur on subarray containing elements that are less than the pivot
    quicksort(a, start, pivot - 1);
    // recur on subarray containing elements that are more than the pivot
    quicksort(a, pivot + 1, end);
}





//heap sort
//zero based

bool minHeap = false;
bool compare(int a, int b){
    if(!minHeap)
        return a < b;
    return a > b;
}

void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n &&  compare(arr[l] , arr[largest]))
     
		largest = l;

	// If right child is larger than largest so far
	if (r < n &&  compare(arr[r] , arr[largest]))
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


//counting sort
// The time complexity of counting sort algorithm is O(n+k) 
// where n is the number of elements in the array and k is the range of the elements.
// In Counting sort, the frequencies of distinct elements of the array to be sorted 
// is counted and stored in an auxiliary array, 
// by mapping its value as an index of the auxiliary array
// maximum value in array  is less than the maximum size of the array 


void counting_sort(int A[], int Aux[], int sortedA[], int N =10) {

    // First, find the maximum value in A[]
    int K = 0;
    for(int i=0; i<N; i++) {
        K = max(K, A[i]);
    }

    // Initialize the elements of Aux[] with 0
    for(int i=0 ; i<=K; i++) {
        Aux[i] = 0;
    }

    // Store the frequencies of each distinct element of A[],
    // by mapping its value as the index of Aux[] array
    for(int i=0; i<N; i++) {
        Aux[A[i]]++;
    }

    int j = 0;
    for(int i=0; i<=K; i++) {
        int tmp = Aux[i];
        // Aux stores which element occurs how many times,
        // Add i in sortedA[] according to the number of times i occured in A[]
        while(tmp--) {
            //cout << Aux[i] << endl;
            sortedA[j] = i;
            j++;
        }
    }
}

//radix sort
// 1. Since Radix Sort depends on digits or letters, Radix Sort is much less flexible
//  than other sorts. Hence , for every different type of data it needs to be rewritten.
// 2. The constant for Radix sort is greater compared to other sorting algorithms.
// 3. It takes more space compared to Quicksort which is inplace sorting.
//  The time complexity of counting sort algorithm is O(n+k) 
// where n is the number of elements in the array and k is the range of the elements.

// CountSort algorithm to get a better time complexity when k goes O(n2)
// We can’t use counting sort because counting sort will take O(n2) which is worse than 
// comparison-based sorting algorithms. Can we sort such an array in linear time? 

void countsort(ll arr[],ll n,ll place)
{
    //range for integers is 10 as digits range from 0-9
        int range = 10;
        int i,freq[range]={0};         //range for integers is 10 as digits range from 0-9
        int output[n];
        for(i=0;i<n;i++)
                freq[(arr[i]/place)%range]++;
        for(i=1;i<range;i++)
                freq[i]+=freq[i-1];
        for(i=n-1;i>=0;i--)
        {
                output[freq[(arr[i]/place)%range]-1]=arr[i];
                freq[(arr[i]/place)%range]--;
        }
        for(i=0;i<n;i++)
                arr[i]=output[i];
}
void radixsort(ll arr[],int n)            //maxx is the maximum element in the array
{
        //maxx is the maximum element in the array
        ll maxx = INT_MIN;
        for(ll i=0;i<n;i++)
            maxx = max(arr[i], maxx);
        int place=1;
        while(maxx)
        {
                countsort(arr,n,place);
                place*=10;
                maxx/=10;
        }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ReadCP();
   
    
    return 0;
}