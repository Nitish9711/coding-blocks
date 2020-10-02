#include<iostream>

using namespace std;

int main()
{
   int n, m;
   cin>>n>>m;

    int ar[n][m];
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
            cin>>ar[i][j];
   } 

   int f;
   cin>>f;

    int i=0, j = m-1, t =0;
   while(1)
   {
       if(i==n || j==-1){
            break;
       } 
       if(f>ar[i][j])
            i++;
        else if(f <ar[i][j])
            j--;
        else 
        {
            t++;
            break;
        }
   }
   if(t == 1)
   {
       cout<<"1"<<endl;
   }
   else{
       cout<<"0"<<endl;
   }
    return 0;
}