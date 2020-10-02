#include<iostream>
using namespace std;

int main()
{
	// c++ store address of variable in the form of hexadecimal numbers
	// &operator is used to find the address
	int x =15;
	cout<<&x<<endl;
	float y = 16;
	cout<<&y<<endl;
	// it does not work for character variables due to operator overloading cascading operator 
	char ch = 'A';
	cout<<&ch<<endl;
	// to find the address of character variables we can typecast 
	// explicit typecasting that means now we don't know the datatype of variable .datatype is now void*
	cout<<(void*)ch<<endl;

}
