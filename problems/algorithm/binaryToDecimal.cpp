#include<iostream>
#include<stdlib.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int b[n], d[n];
    for(int i =0;i<n;i++)
    {
        cin>>b[i];
       
    }
    
    for(int j = 0;j<n;j++)
    {
        char binary [64];
        itoa(b[j], binary, 10);
        
        cout<<d[j]<<endl;;
    }

    return 0;
}