#include <iostream>
using namespace std;




int main()
{
	int x =20;
	cin>>x;
	int*xptr = &x;
	cout<<&x<<endl;
	cout<<xptr<<endl;

	cout<<x<<endl;
	cout<<*xptr<<endl;

	cout<<*(&x)<<endl;
	cout<<*(xptr)<<endl;

	cout<<*(&xptr)<<endl;
	cout<<&(*xptr)<<endl;

	cout<<&xptr<<endl;

	//pointer to a pointer is called double pointer
	int**xxptr = &xptr;
	cout<<xxptr<<endl;

	return 0;
}
