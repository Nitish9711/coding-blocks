#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int T;
    cin>>T;
    int c1[T], c2[T], c3[T], c4[T], n[T], m[T];
    int cc[T], tc[T], rc[T];

    for(int i=0;i<T;i++)
    {
        cin>>c1[i]>>c2[i]>>c3[i]>>c4[i];
        cin>>n[i]>>m[i];
        int a[i][n[i]], b[i][m[i]];
    
        
        int sum = 0;
        for(int j=0;j<n[i];j++)
        {
            cin>>a[i][j];
            sum +=min(a[i][j]*c1[i],c2[i]);
        }
        rc[T] = min(sum, c3[i]);
        int sum2 =0;
        for(int k =0;k<m[i];k++)
          {  cin>>b[i][k];
            sum2 += min(b[i][k]*c1[i], c2[i]);
          }
          cc[T] = min(sum2, c3[i]);

    }
    
    for(int i=0;i<T;i++)
    {
        tc[i] = min((cc[i]+rc[i]), c4[i]);
        cout<<tc[i]<<endl;
    }
    
     return 0;

}