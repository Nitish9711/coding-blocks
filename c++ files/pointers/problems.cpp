#include<iostream>

using namespace std;
#include <iostream>


using namespace std;

void AddOne(int ar[] ,int size)
{
	ar[size-1]=ar[size-1]+1;


}

int main()
{
	int ar[] = {1,2,3,4,5};
	int size = sizeof(ar)/sizeof(int);
	AddOne(ar,size);
	for(int i=0;i<size;i++)
	{
		cout<<ar[i];
	}


	return 0;
}
