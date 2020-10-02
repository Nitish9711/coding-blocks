#include<iostream>
#include<cmath>

using namespace std;
#define ll long int

int main(){
    int t;
    cin>>t;

    while(t--){
        ll n;
        ll k;
        cin>>n>>k;
        ll rem = 0;
        ll ans = k;
        bool flag = false;
        ll *ar = new ll[n];
        for(int i=0;i<n;i++){
            cin>>ar[i];
            rem += ar[i];
            if(rem < k && flag == false){
                flag = true;
                ans = i+1;
            }
            else
            {
                rem = rem-k;
            }            
        }
        
        if(flag == false)
            ans = n + ceil((rem+1)/(double)k);

                
        cout<<ans<<endl;
    }
    return 0;
}