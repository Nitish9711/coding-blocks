#include<iostream>

using namespace std;

int main()
{
    int* p = new int(30);
    cout<<*p<<endl;

    int* q = new int;
    cout<<*q<<endl;

    //intitalization of arrays
    int *arr = new int[30];
    for(int i=0;i<3;i++)
    {
        arr[i] = i;
    }
     for(int i=0;i<3;i++)
    {
        cout<<arr[i]<<endl;
    }

    delete p;
    delete q;
    delete [] arr;  // telling that we want to delete whole array

    int ** ar = new int*[3]; //creating a primary array int the heap area
    for(int i=0;i<3;i++)
    {
        ar[i] = new int[4];  //creating secondary array

    }
    int count =0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++){
            ar[i][j] = count;
            count++;
        }

    }
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++){
            cout<<ar[i][j]<<" ";
        }
        cout<<endl;

    }
    for(int i=0;i<3;i++)
    {
        delete [] ar[i]; //deleting secondary array
    }
    delete [] ar; // deleteing primary array
    return 0;
}