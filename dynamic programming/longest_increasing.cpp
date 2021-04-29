#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}

// recursion bruteforce
int answer(int arr[], int n,int i, int prev){
    if(i == n){
        return 0;
    }

    int exclude = answer(arr, n, i+1, prev);
    int include = 0;
    if(arr[i] > prev){
        include = 1+ answer(arr, n, i+1, arr[i]);
    }

    return max(include,exclude);
}

// dp(o(n2))
int answer2(int arr[], int n, int i){
    int dp[n+1] = {0};

     for(int i =0;i<n;i++){
        dp[i] = 1;
        for(int j = 0;j<i;j++){
            if(arr[j]<arr[i])
                dp[i] = max(dp[i],dp[j]+1);                
        }

    }
    int ans =0;
    for(int i =0;i<n;i++){
        ans = max(ans, dp[i]);
    }
    
}
// dp3(on(2))
int LIS(int arr[], int n)
{
    // array to store subproblem solution. `L[i]` stores the length
    // of the longest increasing subsequence that ends with `arr[i]`
    int L[n] = { 0 };
 
    // the longest increasing subsequence ending with `arr[0]` has length 1
    L[0] = 1;
 
    // start from the second array element
    for (int i = 1; i < n; i++)
    {
        // do for each element in subarray `arr[0…i-1]`
        for (int j = 0; j < i; j++)
        {
            // find the longest increasing subsequence that ends with `arr[j]`
            // where `arr[j]` is less than the current element `arr[i]`
 
            if (arr[j] < arr[i] && L[j] > L[i]) {
                L[i] = L[j];
            }
        }
 
        // include `arr[i]` in LIS
        L[i]++;
    }
 
    // find the longest increasing subsequence (having maximum length)
    int lis = INT_MIN;
    for (int x: L) {
        lis = max(lis, x);
    }
 
    return lis;
}
//  / nlogn
    
// edit/
// play_arrow
// 
// brightness_4
#include <iostream> 
#include <vector> 
  
// Binary search (note boundaries in the caller) 
int CeilIndex(std::vector<int>& v, int l, int r, int key) 
{ 
    while (r - l > 1) { 
        int m = l + (r - l) / 2; 
        if (v[m] >= key) 
            r = m; 
        else
            l = m; 
    } 
  
    return r; 
} 
  
int LongestIncreasingSubsequenceLength(std::vector<int>& v) 
{ 
    if (v.size() == 0) 
        return 0; 
  
    std::vector<int> tail(v.size(), 0); 
    int length = 1; // always points empty slot in tail 
  
    tail[0] = v[0]; 
    for (size_t i = 1; i < v.size(); i++) { 
  
        // new smallest value 
        if (v[i] < tail[0]) 
            tail[0] = v[i]; 
  
        // v[i] extends largest subsequence 
        else if (v[i] > tail[length - 1]) 
            tail[length++] = v[i]; 
  
        // v[i] will become end candidate of an existing 
        // subsequence or Throw away larger elements in all 
        // LIS, to make room for upcoming grater elements 
        // than v[i] (and also, v[i] would have already 
        // appeared in one of LIS, identify the location 
        // and replace it) 
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i]; 
    } 
  
    return length; 
} 
  
  int findLISLength(int arr[], int n)
{
    // create an empty ordered set `S`. The i'th element in `S` is defined as the
    // smallest integer that ends an increasing sequence of length `i`
    set<int> S;
 
    // process every element one by one
    for (int i = 0; i < n; i++)
    {
        // ignore the current element if it is already present in the set
        if (S.find(arr[i]) != S.end()) {
            continue;
        }
 
        // insert the current element into the set
        auto ret = S.insert(arr[i]);
 
        // get an iterator to the inserted item
        set<int>::iterator it;
        if (ret.second)
            it = ret.first;
 
        // if the element is not inserted at the end, then delete the next
        // greater element from the set
        if (++it != S.end())
            S.erase(it);
    }
 
    // length of LIS is the total number of elements in the set
    return S.size();
}
 


int main()
{

    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60, 80}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    // cout<<answer3(arr, n)<<endl;

    return 0;
}