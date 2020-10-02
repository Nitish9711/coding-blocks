#include<iostream>
using namespace std;
long long func(int n)
{
    if(n==1)
        return 2;
    if(n==2)
        return 3;
    return func(n-1)+func(n-2);
}
int main() {
    int T;
    cin>>T;
    long long arr[45];
    arr[0]=1;
    arr[1]=2;
    for(int i=2;i<45;i++)
        arr[i]=arr[i-1]+arr[i-2];
    for(int i=1;i<=T;i++)
    {
        cout<<"#"<<i<<" : ";
        int N;
        cin>>N;
        //cout<<func(N)<<endl; --> TLE
        cout<<arr[N]<<endl;
    }
	return 0;
}