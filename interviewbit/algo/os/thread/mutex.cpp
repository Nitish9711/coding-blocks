#include <bits/stdc++.h>
#include <mutex>
#include <thread>
using namespace std;



mutex m;

void add(int*x,int val){
    m.lock();
    int y=*x;
    y+=val;
    *x=y;
    m.unlock();
}

int32_t main() {
  
    int x=10;
    thread t1(add,&x,5), t2(add,&x,-5);
    t1.join();
    t2.join();
    cout<<x;
}