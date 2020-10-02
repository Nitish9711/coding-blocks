#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n], b[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    for(int i=0;i<n;i++)
        cin>>b[i];

    int q;
    cin>>q;
    int l[q], r[q], c,temp;
    int maxv=0, minv=0,mini=0;
    for(int i=0;i<q;i++)
        cin>>l[i]>>r[i];
    
    for(int i=0;i<q;i++)
    {
        for(int j=l[i];j<=r[i];j++)
        {   c = l[i];
            if(j==l[i])
            {
                maxv=a[j];
                temp = j;
                
            }
            else
            {
                if(a[j]>maxv)
                   { maxv = a[j];
                    temp = j;}
                else if(a[j]==maxv)
                {
                    minv = b[j];
                    temp = j;
                    if(minv < b[j])
                        {minv = b[j];
                        temp = j;}
                    else if (minv == b[j])
                    {
                        mini = c;
                        temp = j;
                        
                    }
                }


            }
            
        }
        cout<<temp<<endl;
        
    }



    
    
    return 0;
}