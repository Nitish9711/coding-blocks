// this code is not threadSafe
#include<bits/stdc++.h>
using namespace std;

//singleton make sure that only one instances of class is created.
// It restricts to intialize only one instance

// steps
// 1. make construtor private
// 2. create a static instance;
// 3. create a public static function to return instance;


class Logger{
    static int ctr;
    // here we have restricted the user to create objets by making constructor private
    Logger();
    static Logger *loggerInstance;
    public:
        static Logger* getLogger();
        void Log(string msg);
};

int Logger::ctr = 0;
Logger* Logger::loggerInstance = nullptr; 
Logger:: Logger(){
    ctr++;
    cout<<"new instances of logger is created"<<endl;
    cout<<"no of instances is "<<ctr<<endl;
}
void Logger::Log(string msg){
    cout<<msg<<endl;
}

Logger* Logger:: getLogger(){
    // here if there are two therads then two instance will be created which we don't want
    if(loggerInstance == nullptr){

        loggerInstance = new Logger();
    }
    return loggerInstance;
}


int main(){

    Logger* logger1 = Logger::getLogger();
    logger1->Log("this msg is from user 1");

    Logger* logger2 = Logger::getLogger();
    logger2->Log("this msg is from user 2");
    
    return 0;
}