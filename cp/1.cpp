    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long 
    #define null NULL
     
    ll  answer(ll c0, ll c1, ll c2, ll n){
        ll ans = 0;
     
        if(c0 >= c1 and c0 >= c2){
            ll temp = c0 - n/3;
            c0 = n/3;
            c1 += temp;
            ans += temp;
     
             if(c1 == c2 )
            return ans;
            else if(c1 > c2){
                temp = c1 - n/3;
                c1 = n/3;
                c2 += temp;
                ans += temp;
                return ans;
            }
            else if(c2 > c1){
                temp = c2 - n/3;
                c2 = n/3;
                ans += 2*temp;
                return ans;
            }
     
     
        }
        else if(c1 >= c0 and c1 >= c2){
            ll temp = c1 - n/3;
            c1 = n/3;
            c2 += temp;
            ans += temp;
     
             if(c0 == c2 )
            return ans;
            else if(c2 > c0){
                temp = c2 -n/3;
                c2 = n/3;
                c0 += temp;
                ans += temp;
                return ans;
            }
            else if(c0 > c2){
                temp = c0 - n/3;
                c0 = n/3;
                ans += 2*temp;
                return ans;
            }
     
     
        }
        else{
            ll temp = c2 - n/3;
            c0 += temp;
            c2 = n/3;
            ans += temp;
            // cout<<" a "<<temp<<" "<<ans<<endl;
     
            if(c0 == c1 )
            return ans;
            else if(c0 > c1){
                temp = c0 - n/3;
                c0 = n/3;
                c1 += temp;
                ans += temp;
                // cout<<" b "<<temp<<" "<<ans<<endl;
     
                return ans;
            }
            else if(c1 > c0){
                temp = c1 - n/3;
                c1 = n/3;
                ans += 2*temp;
                // cout<<" c "<<temp<<" "<<ans<<endl;
     
                return ans;
            }
     
     
        }
        return ans;
     
    }
     
    int main()
    {
        int t;
        cin >> t;
        while (t--)
        {
           ll n;
           cin>>n;
           ll *ar = new ll[n];
           ll c0 = 0, c1 = 0, c2 = 0; 
           for(ll i =0;i<n;i++){
               cin>>ar[i];
               if(ar[i]%3 == 0){
                   c0++;
               }
               else if(ar[i]%3 == 1)
                    c1++;
                else 
                    c2++;
           }
           if(c1 == c2 && c2 == c0){
               cout<<"0"<<endl;
           }
           else{
            //    cout<<c0<<" "<<c1<<" "<<c2<<endl;
               cout<<answer(c0, c1, c2, n)<<endl;
     
           }
     
     
        }
        return 0;
    }