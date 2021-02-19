#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long 
#define null NULL

int main()
{
    int t;
    cin >> t;
    // ll ar[10001];
    // for(int i =0;i<=10000;i++){
    //     ar[i]  = i*i*i;
    // }
    while (t--)
    {
        ll x;
        cin>>x;
        ll n = ceil( cbrt(x));
        bool flag = false;
        for(int i = 1;i<n;i++){
            for(int j = 1;j<n;j++){
                if(x %(i +j) == 0){
                    if(x %(i*i + j*j - i*j)==0){
                        flag = true;
                        break;
                    }
                }
            }
            if(flag == true){
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
       
    }
    return 0;
}