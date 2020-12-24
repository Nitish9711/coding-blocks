#include <iostream>
#include<stack>
using namespace std;



void solve(int *ar, int n){
    stack<int>s;
    int res[n], i =0;
    for(int i=0;i<n;i++){
        res[i] = -1;
    }

    while (i<2 *n)
    {

        while (!s.empty() && ar[i%n] >= ar[s.top()])
        {
            res[s.top()]  = i%n;
            s.pop();
        }
        
        s.push(i%n);
        i++;
    }

    for(int i=0;i<n;i++){
        cout<<ar[res[i]]<<" ";
    }
    


}

int main()
{
    int n ;
    cin>>n;
    int * ar = new int[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }


    solve(ar, n);
    return 0;
}