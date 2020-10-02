#include<iostream>

using namespace std;

void duplicateAndMissing(int arr[],int size)
{
	int check[100]={};
	for(int i=0;i<size;i++)
	{
		(check[arr[i]])++;
	}
	for(int i=1;i<=size;i++)
	{
		if( check[i]>1)
			cout<<"Duplicate  "<<i<<endl;
		if(check[i]==0)
			cout<<"Missing "<<i<<endl;
	}
}

int main()
{
	int arr[]= {1,3,3,4};
	int size = sizeof(arr)/sizeof(int);
	duplicateAndMissing(arr,size);
	return 0;
}
