#include<iostream>
#include<math.h>

using namespace std;

int minSteps(int t)
{
    int count= 0 , temp;
    
     while(1)
    {
        temp = log2(t);
        t = t- pow(2, temp);
        count++;
        if(t==1)
        {
            count++;
            break;
        }
        else if(t==0)
            break;

    }
    return count;
    
}

int main()
{
    int T, t[10],w[10];
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>t[i];
        w[i]=minSteps(t[i]);
    }
    for(int i=0;i<T;i++)
    {
        cout<<w[i]<<endl;
    }


    
    return 0;

}