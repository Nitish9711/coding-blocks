#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL


int solve(vector<int>nums){
    int n = nums.size();
    
    int ans = INT_MAX;
    for(int i =1;i<n;i++){
        nums[i] = max(nums[i], nums[i] + nums[i-1]);
        ans = max(ans, nums[i]);
    }

    return ans;
}
int main()
{
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};

    cout<<solve(nums)<<endl;
    return 0;
}