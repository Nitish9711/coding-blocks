#include<bits/stdc++.h>
using namespace std;
// In Factory pattern, we create object without 
// exposing the creation logic to the client and refer to newly created object using a common interface.
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
// after making this factory class now we have shifted if else to the backend side so whenver we want to add some other 
// vehcile we can just add vehicle over here rather then adding on the client side
// also now client doesn't know how the object if being created
class VehicleFactory{
    public: 
    // we made function as static so that we don't have to create objects of it
        static Vehicle *getVehicle(string vehicleType);
};

Vehicle * VehicleFactory:: getVehicle(string vehicleType){
    Vehicle* vehicle;
    if(vehicleType == "car"){
        vehicle = new Car();
    }
    else if(vehicleType == "bike"){
        vehicle = new Bike();
    }   
    return vehicle;
}

int main()
{
    string vehicleType;
    cin>>vehicleType;
    Vehicle* vehicle = VehicleFactory::getVehicle(vehicleType);
    vehicle->createVehicle();
    return 0;
}