#include<iostream>
#include<cstring>
using namespace std;



class Car{
private:
	float price;


public:
	int model_no ;
	char *name;
	const int msp ;

	//Init LIst
    // initializATIOn_list is used to initialize const data members as well as other members 
	Car():msp(99){
        name = NULL;
    }
	Car(float p,int m,char *n,int minprice=99):price(p),msp(minprice){
		model_no = m;
		name = new char[strlen(n)+1];
		strcpy(name,n);
	}

	Car(Car &X):msp(X.msp){
		cout<<"Inside copy constructor";
		price = X.price;
		model_no = X.model_no;
		//deep copy
		name = new char[strlen(X.name)+1];
		strcpy(name,X.name);
	}
    // for copy assignment operator
	void operator=(Car &X){
		price = X.price;
		model_no = X.model_no;
		//deep copy
		name = new char[strlen(X.name)+1];
		strcpy(name,X.name);
		
	}

	void setprice(float p){
		price = p;
	}

	void print(){
		cout<<"Name "<<name<<endl;
		cout<<"Model No "<<model_no<<endl;
		cout<<"Price "<<price<<endl;
	}
	~Car(){
		cout<<"Destroying car"<<name;
		if(name!=NULL){
			delete [] name;
		}
	}
};

int main(){

	//static car
	Car c(100,200,"BMW"); //parameterised constructor
	cout<<c.msp<<endl;
	//c.msp++;

	Car d;//constructor
	d = c; //copy assignment operator as many times
	d.name[0] = 'A';
	d.setprice(400);

	c.print();
	
	
	d.print(); 


	//Dynamically Created Car
	Car *e = new Car(10,20,"Ferari");

    // for calling functions by dyanmically created objects we have to use this operator
	e->print();

	//delete keyword to delete those objects 
    // we can only delete dyanimally created objects
	delete e;

	

	return 0;
}






