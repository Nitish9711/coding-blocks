#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

int join_ropes(int ropes[], int n){
    priority_queue<int, vector<int>, greater<int> >pq(ropes, ropes+n); //minheap

    int cost = 0;
    while(pq.size()> 1){
        int a = pq.top();
        pq.pop();
        int b =pq.top();
        pq.pop();

        int new_rope = (a + b);
        cost += new_rope;
        pq.push(new_rope);
    }
    return cost;
}

int main()
{

    int ropes[] = {4, 3, 2, 6};
    int n = 4;

    cout<<join_ropes(ropes, n)<<endl;
    
    return 0;
}