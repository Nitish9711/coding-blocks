// CPP program to demonstrate multithreading
// using three different callables.
#include <iostream>
#include <thread>
using namespace std;


static bool finished = false;

void doSomething(){
    cout<<"current thread id "<<this_thread::get_id()<<endl;
    while(!finished){
        cout<<"doing something"<<endl;
        this_thread::sleep_for(1s);
    }
}



int main()
{
	thread worker(doSomething);
    cin.get();//separate thread
    finished = true;
    worker.join();
    cout<<"finished working"<<endl;
    cout<<"finsih thread id "<<this_thread::get_id()<<endl;
    cin.get();
	return 0;
}
