#include <iostream>
#include<stack>
using namespace std;

void solve(int ar[], int n){
    stack<int>s;
    s.push(0);
    int span[n];  
    span[0] = 1;
    for(int i = 1;i<n;i++){
        // cout<<i<<endl;    
        while (!s.empty() && ar[s.top()] <= ar[i])
        {
            s.pop();
        }
        // span[i] = (s.empty()) ? (i + 1) : (i - st.top());

        span[i] = (s.empty()) ? (i+1) : (i - s.top());

        // cout<<i<<endl;    
        s.push(i);
        
    }

    for(int i=0;i<n;i++){
        cout<<span[i]<<" ";
    }
    cout<<"END";

}

int main()
{
    int n;
    cin>>n;
    int *ar = new int[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }


    solve(ar, n);
    return 0;
}