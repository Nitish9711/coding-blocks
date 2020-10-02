#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;

    // array of fixed size means constant space  o(1)
    int sum[64] = {0};

    int no;
    for(int i=0;i<n;i++)
    {   
        cin>>no;
        // update the sum array
        int j=0;
        while(no> 0)
        {
            int last_bit = no & 1;
            sum[j] += last_bit;
            j++;
            no = no >> 1;
        }
    }

    int p =1;
    int ans = 0;
    for(int i =0;i<64;i++)
    {
        sum[i] = sum[i] %3;
        ans += (sum[i]*p);
        p = p<<1;
    }

    cout<<ans;
    

    return 0;
}