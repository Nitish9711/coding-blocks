// CPP program to demonstrate multithreading
// using three different callables.
#include <iostream>
#include <thread>
using namespace std;
void doSomething(){
    for(int i=0;i<10;i++)
        cout<<i<<endl;
}

int main()
{
	thread worker(doSomething);
    worker.join();
    cout<<"hi"<<endl;
	return 0;
}
