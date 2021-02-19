// Shekhar is a bomb defusal specialist. He once encountered a bomb that can be defused only by a secret code. He is given a number N and a number K. And he is also given permutation of first N natural numbers . The defusal code is the largest permutation possible by doing atmost K swaps among a pair of the given permutation. Help him to find the final permutation.

// Input Format
// First line contains ​an integer N and an integer k. The next line contains N space separated integers denoting the given permutation.

// Constraints
// 1 <= n <= 10^5 1<= K <= 10^9

// Output Format
// // The final permutation of the numbers with every number separated by a space with other number.

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

int main()
{
    ll n,k;
    unordered_map<ll, ll>m;
    cin>>n>>k;
    // vector<ll>vec;
    ll d;
    ll *ar =new ll[n+1];

    for(ll i =1;i<=n;i++){
        cin>>ar[i];
        m[ar[i]] = i;
        // ar[i] = d;
    }
    ll i = 1;
    
    while(i<=n  && k > 0){

        if(ar[i] == n-i + 1){
            // cout<<i<<" not changed" <<endl;
            i++;
            continue;
        }
        else{
            ll idx = m[n-i+1];
            //  cout<<i<<"  changed " <<idx<<endl;
            m[n-i+1]  = i;
            m[ar[i]] = idx;
            swap(ar[i], ar[idx]);
            i++;
            k--;
        }
    }
    // for(ll i = 1;i<=n;i++){
    //     cout<<i<<" "<<m[i]<<endl;
    // }
    for(int i =1;i<=n;i++){
        cout<<ar[i]<<" ";
    }
    return 0;
}