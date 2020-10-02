#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int ar[n];

    int a=0, b=0, c=0;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        if(ar[i]== '(')
         {   a++;
            cout<<a<<endl;}
        else if(ar[i] == ')')
            a--;
        else if(ar[i] == '[')
            b++;
        else if(ar[i] == ']')
            b--;
        else if(ar[i] == '{')
            c++;
        else if(ar[i] == '}')
            c--;
    }
    if (a == 0 && b == 0 && c==0)
        cout<<"Yes"<<endl;
    else
    {
            cout<<"No"<<endl;
    }
    
      

    return 0;
}