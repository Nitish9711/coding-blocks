#include<iostream>

using namespace std;

int main()
{
    int arr[] = {3, 2, 3, 5, 6, 5, 2};
    int size = sizeof(arr)/sizeof(int);

    int ans = 0;
    for(int i=0;i<size;i++)
        ans = ans ^ arr[i];

    cout<<ans<<endl;
    return 0;
}