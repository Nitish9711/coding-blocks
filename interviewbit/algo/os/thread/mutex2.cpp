#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

int myaccount =0;

mutex m;

void addMoney(){
    m.lock();
    ++myaccount;
    m.unlock();
}
int main(){
    thread t1(addMoney);
    thread t2(addMoney);

    t1.join();
    t2.join();
    cout<<myaccount<<endl;
}