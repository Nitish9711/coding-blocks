// this method fails in certain cases;

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL

int make_change(vector<int> &coins, int amount)
{
     int ans  = 0;
        sort(coins.begin(), coins.end());
        int n = coins.size();
        for(int i = n-1;i>= 0;i--){
            while(amount >= coins[i]){
                amount = amount - coins[i];
                ans++;
            }
        }
        cout<<amount<<endl;
        if(amount != 0){
            return -1;
        }
        
        
        return ans;

    
}
int main()
{
    
    vector<int> coins{1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int amount;
    cin >> amount;

    cout << make_change(coins, amount) << endl;
    return 0;
}