#include <iostream>
#include<queue>

using namespace std;
#define ll long long 
#define null NULL

int main()
{
    

    // priority_queue<int>pq;// maxheap
    priority_queue<int ,vector<int>, greater<int>>pq;// minheap
    
    int n;
    cin>>n;

    for(int i=1;i<n;i++){
        int no;
        cin>>no;
        pq.push(no);  //o(logn)
    }

    while (!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }


    


    return 0;
}