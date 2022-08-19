#include<bits/stdc++.h>
using namespace std;

class Vehicle{
    public:
    //pure virtual function every child class has to implement it
        virtual void createVehicle() =0;
};

class Car: public Vehicle {
    public:
       void createVehicle();
};

class Bike: public Vehicle{
    public:
        void createVehicle();
};

void Car:: createVehicle(){
    cout<<"Creating Car"<<endl;
}

void Bike:: createVehicle(){
    cout<<"Creating Bike"<<endl;
}
// in this case whenever we create a new 
// type of vehicle we have to add a new if else so basically client side has to be changed that is very incoveninet.

int main()
{
    string vehicleType;
    cin>>vehicleType;
    Vehicle* vehicle;
    if(vehicleType == "car"){
        vehicle = new Car();
    }
    else if(vehicleType == "bike"){
        vehicle = new Bike();
    }
    vehicle->createVehicle();
    return 0;
}