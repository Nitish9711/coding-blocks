#include <iostream>
using namespace std;




int main()
{	
	int x ;
	cin>>x;
	cout<<endl;
	// declaration with intialization
	int *y = &x;
	
	// if we do not intialize then it will throw the garbage value2
	// size of pointer variable is same irrespective of its data type either 4 bytes and 8 bytes
	// data type of the pointer should be same as the variable because datatype of pointers basically denotes no of cells to be read
	// for example like int pointer reads 4 cells of memory
	/**/

	cout<<y<<endl;

	return 0;
}