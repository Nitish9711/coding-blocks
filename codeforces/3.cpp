 #include<iostream> 
using namespace std; 
class base { 
public: 
	base()	 
	{ cout<<"Constructing base "; } 
	~base() 
	{ cout<<"Destructing base "; }	 
}; 

class derived: public base { 
public: 
	derived()	 
	{ cout<<"Constructing derived "; } 
	~derived() 
	{ cout<<"Destructing derived "; } 
}; 

int main(void) 
{ 
derived *d = new derived(); 
base *b = d; 
delete b; 
getchar(); 
return 0; 
} 
