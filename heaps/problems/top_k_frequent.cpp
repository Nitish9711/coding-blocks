#include<bits/stdc++.h>
using namespace std;

class abc{
    public:
    int freq,num;
    abc(int freq,int num)
    {
        this->freq=freq;
        this->num=num;
    }
};
class functor{
    public:
    bool operator()(abc x1,abc x2)
    {
        if(x1.freq==x2.freq)
        return x1.num>x2.num;//When frequency of 2 elements is same, the smaller of the 2 elements will be at the top of the heap.
        else 
        return x1.freq<x2.freq;//Max heap based on frequency count
    }
};
int main() {
    int t;int n,k;
    cin>>t;
    int *arr;
    while(t--)
    {
     priority_queue<abc,vector<abc>,functor>pq;//Preparing a priority queue of abc type(ie. based on the number and on the frequency)
     cin>>n>>k;
     arr=new int[n];int nn;
     int count[100]={0};//To maintain frequency count of each number
     for(int i=0;i<n;i++)
     cin>>arr[i];

     for(int i=0;i<n;i++)
     {
     count[arr[i]]++;
     nn=k;
     for(int j=0;j<=i;j++){
     abc y(count[arr[j]],arr[j]);
     pq.push(y);//Pushing an object of class abc(containg the number and its frequency) to the heap
     }
     while(!pq.empty()&&nn--)
     {  
         abc yy=pq.top();
         cout<<yy.num<<" ";
         int l1=yy.freq;
         while(l1--)//Emptying the heap
         pq.pop();
     }
     while(!pq.empty())
     pq.pop();    
     }
     cout<<endl;
    }
	return 0;
}