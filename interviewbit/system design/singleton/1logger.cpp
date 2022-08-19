#include<bits/stdc++.h>
using namespace std;

//singleton make sure that only one instances of class is created.
// 


class Logger{
    static int ctr;
    public:
        Logger();
        void Log(string msg);
};

int Logger::ctr = 0;

Logger:: Logger(){
    ctr++;
    cout<<"new instances of logger is created"<<endl;
    cout<<"no of instances is "<<ctr<<endl;
}
void Logger::Log(string msg){
    cout<<msg<<endl;
}



int main(){

    Logger* logger1 = new Logger();
    logger1->Log("this msg is from user 1");

    Logger* logger2 = new Logger();
    logger2->Log("this msg is from user 2");
    
    return 0;
}