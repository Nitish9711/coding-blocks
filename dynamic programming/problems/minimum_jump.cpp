// You are provided an array of integers where each element represents the max number of steps you can take to move ahead. You need to check that how many minimum steps required to reach at the end of the array.

// Hint - If N==0 you can never move forward, your return INT_MAX (Infinity).
Problem Name : Minimum Jumps Required
Topic : DP
Difficulty : Hard
EXPLANATION
A naive approach is to start from the first element and recursively call for all the elements reachable from first element. The minimum number of jumps to reach end from first can be calculated using minimum number of jumps needed to reach end from the elements reachable from first. minJumps(start, end) = Min ( minJumps(k, end) ) for all k reachable from start

int minJumps(int arr[], int n) 
{ 

    // Base case: when source and 
    // destination are same 
    if (n == 1) 
        return 0; 

    // Traverse through all the points 
    // reachable from arr[l] 
    // Recursivel, get the minimum number 
    // of jumps needed to reach arr[h] from 
    // these reachable points 
    int res = INT_MAX; 
    for (int i = n - 2; i >= 0; i--) { 
        if (i + arr[i] >= n - 1) { 
            int sub_res = minJumps(arr, i + 1); 
            if (sub_res != INT_MAX) 
                res = min(res, sub_res + 1); 
        } 
    } 

    return res; 
}  
If we trace the execution of this method, we can see that there will be overlapping subproblems. For example, minJumps(3, 9) will be called two times as arr[3] is reachable from arr[1] and arr[2]. So this problem has both properties (optimal substructure and overlapping subproblems) of Dynamic Programming.

Method 2 (Dynamic Programming) In this method, we build a jumps[] array from left to right such that jumps[i] indicates the minimum number of jumps needed to reach arr[i] from arr[0]. Finally, we return jumps[n-1].

int minJumps(int arr[], int n) 
{ 
    // jumps[n-1] will hold the result 
    int* jumps = new int[n]; 
    int i, j; 

    if (n == 0 || arr[0] == 0) 
        return INT_MAX; 

    jumps[0] = 0; 

    // Find the minimum number of jumps to reach arr[i] 
    // from arr[0], and assign this value to jumps[i] 
    for (i = 1; i < n; i++) { 
        jumps[i] = INT_MAX; 
        for (j = 0; j < i; j++) { 
            if (i <= j + arr[j] && jumps[j] != INT_MAX) { 
                jumps[i] = min(jumps[i], jumps[j] + 1); 
                break; 
            } 
        } 
    } 
    return jumps[n - 1]; 
} 
Time Complexity: O(n^2)

Now moving to optimised approach,basically idea is to take jump only when its needed. The variable maxReach stores at all time the maximal reachable position in the array. jump stores the amount of jumps necessary to reach that position. step stores the amount of steps we can still take (and is initialized with the amount of steps at the first array position)

During the iteration, the above values are updated as follows:

First we test whether we have reached the end of the array, in which case we just need to return the jump variable.

Next we update the maximal reachable position. This is equal to the maximum of maxReach and i+A[i] (the number of steps we can take from the current position).

We used up a step to get to the current index, so steps has to be decreased.

If no more steps are remaining (i.e. steps=0, then we must have used a jump. Therefore increase jump. Since we know that it is possible somehow to reach maxReach, we initialize the steps to the amount of steps to reach maxReach from position i.

Time Complexity : O(NN).
#include<bits/stdc++.h>
using namespace std;
#define int long long 

int MinJumpReq(vector<int> &a){
    int n=a.size();
    if(a[0]==0)return INT_MAX;
    int minJump=1;
    int maxReach=a[0],step=a[0];
    for(int i=1;i<n-1;i++){
        step--;
        maxReach=max(maxReach,i+a[i]);
        if(step==0){
            minJump++;
            if(maxReach<=i)return INT_MAX;
            step=maxReach-i;
        }
    }
    return minJump;
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<MinJumpReq(a)<<"\n";
    }
}