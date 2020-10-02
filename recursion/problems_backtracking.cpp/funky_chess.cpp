#include<iostream>

using namespace std;



int main()
{
    int n;
    cin>>n;

    int ar[13][13];
    for(int i=0;i<n;i++)
    {
        for(int j =0;j<n;j++)   
            cin>>ar[i][j];
    }


    return 0;
}