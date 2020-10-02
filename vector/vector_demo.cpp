#include<iostream>
#include "ownVector.h"
using namespace std;

int main(){
    Vector v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.pop_back();
    v.push_back(6);

    cout<<"Capcity "<<v.capacity()<<endl;
    cout<<"front "<<v.front()<<endl;
    cout<<"back "<<v.back()<<endl;
    cout<<"at "<<v.at(6)<<endl;
    

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }


    return 0;
}