#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL
#define MAX_SIZE 10000000000000;

void ReadCP(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}



ll answer(ll n, ll e, ll h, ll a, ll b, ll c){

    if(n<= 0)
        return 0;
    ll k;
    ll ans = 1e15;
    if(n <= e && n<=h)
        ans = min(ans, n*c);
    if(2*n <= e)
        ans = min(ans , n*a);
    
    if(3*n <= h)
        ans = min(ans, n*b);

    // cakes and shakes
    if((h-n)/2 >=1 and (h-n)/2 >= (n-e)){
        // cout<<"a"<<endl;
        if(b < c){
             k = min(n-1, (h-n)/2);
            ans = min(ans, (b-c)*k + n*c);
        }
        else{
            k= max(1LL, n-e);
            ans = min(ans, (b-c)*k + n*c);
        }

        
    }

    // cakes and omellets
    // if((e-n)>=1 and (e-n) >=h){
    if((e-n)>=1 and (e+h) >=2*n){
        // cout<<"b"<<endl;
        if(a-c<0){
            k = min(n-1, (e-n));
            ans = min(ans, (a-c)*k + n*c);
        }
        else{
            k = max(1LL, n-h);
            ans =min(ans, (a-c)*k  + n*c);

        }
    }


    //shakes and omelletes

    if(e/2 >=1 and e/2 >= (3*n -h +2 )/3){
        // cout<<"c"<<endl;
        if(a <b){
            k = min(n-1, e/2);
            ans = min(ans, (a-b)*k + n*b);

        }
        else{
            k =max(1LL, (3*n-h+2)/3);
            ans = min(ans, (a-b)*k + n*b);
        }

    }

    // all 3;

    if(e>=3 and h>=4 and n>=3){
        // cout<<"d"<<endl;
        ans = min(ans, a+b+c+answer(n-3, e-3, h-4, a, b, c));
        
    }



    return ans;

}
int main()
{
    ReadCP();
    int t;
    cin >> t;
    while (t--)
    {
        ll n,e, h, a, b, c;
        cin>>n>>e>>h>>a>>b>>c;
        ll y = answer(n, e, h, a, b ,c);
        if(y >= 1e15)
            cout<<"-1"<<endl;
        else{
            cout<<y<<endl;
        }
        

       
    }
    return 0;
}