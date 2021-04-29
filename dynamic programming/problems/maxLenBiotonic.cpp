// You are provided n numbers of array. You need to find the maximum length of biotonic subsequence. A subsequence is biotonic if it is first increasing and then decreasing or entirely increasing or decreasing. Please Note: the heights of the building in the elements should be strictly increasing and then strictly decreasing.


This problem is a variation of standard Longest Increasing Subsequence (LIS) problem. Let the input array be arr[] of length n. We need to construct two arrays lis[] and lds[] using Dynamic Programming solution of LIS problem. lis[i] stores the length of the Longest Increasing subsequence ending with arr[i]. lds[i] stores the length of the longest Decreasing subsequence starting from arr[i]. Finally, we need to return the max value of lis[i] + lds[i] – 1 where i is from 0 to n-1.


// C++ Code
#include <iostream>
using namespace std;

int longestBiotonicSub(int *arr, int n) {
    int *lis = new int[n];
    int *lds = new int[n];
    for(int i=0;i<n;i++) {
        lis[i] = 1;
    }
    for(int i=0;i<n;i++) {
        lds[i] = 1;
    }
    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(arr[i]>arr[j] and lis[i]<lis[j]+1) lis[i] = lis[j]+1;
        }
    }
    for(int i=n-2;i>=0;i--) {
        for(int j=n-1;j>i;j--) {
            if(arr[i]>arr[j] and lds[i]<lds[j]+1) lds[i] = lds[j]+1;
        }
    }
    int max = lis[0] + lds[0] - 1;

    for(int i=1;i<n;i++) {
        if(max<lis[i]+lds[i]-1) {
            max = lis[i]+lds[i]-1;
        }
    }
    return max;
}

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--) {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<longestBiotonicSub(arr, n)<<endl;
    }
    return 0;
}


 
// Java Code
public static int longestBiotonicSub(int[] arr) {
        int n = arr.length;
        int[] lis = new int[n];
        int[] lds = new int[n];
        for (int i = 0; i < n; i++) {
            lis[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            lds[i] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                    lis[i] = lis[j] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (arr[i] > arr[j] && lds[i] < lds[j] + 1)
                    lds[i] = lds[j] + 1;
            }
        }
        int max = lis[0] + lds[0] - 1;
        for (int i = 1; i < n; i++) {
            if (max < lis[i] + lds[i] - 1) {
                max = lis[i] + lds[i] - 1;
            }
        }
        return max;
    }