#include<iostream>
#include<cstring>
#include<vector>
using namespace std;




int no_of_ways (int n, int m)
{
    if(n<=m-1)
        return 1;
    
    return no_of_ways(n-1, m) + no_of_ways(n-4, m);
    

}

int main()
{
    int t;
    cin>>t;
   while(t--)
   {
       int n, m;
       cin>>n>>m;

       cout<<no_of_ways(n, m)<<endl;

   }


    return 0;
}