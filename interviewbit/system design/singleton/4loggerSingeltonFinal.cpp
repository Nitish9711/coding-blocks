//  threadSafe
#include<iostream>
#include<thread>
#include<mutex>
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
    // we also have to make all the copy private
    Logger(const Logger&);
    // assignment operator also private
    Logger operator=(const Logger &);
    static Logger *loggerInstance;
    static mutex mtx;
    public:
        static Logger* getLogger();
        void Log(string msg);
};

int Logger::ctr = 0;
Logger* Logger::loggerInstance = nullptr; 
mutex Logger::mtx;
Logger:: Logger(){
    ctr++;
    cout<<"new instances of logger is created"<<endl;
    cout<<"no of instances is "<<ctr<<endl;
}
void Logger::Log(string msg){
    cout<<msg<<endl;
}

Logger* Logger:: getLogger(){
    // here question will be do need to have lock every single time becz locks are very expensive
    mtx.lock();
    if(loggerInstance == nullptr){

        loggerInstance = new Logger();
    }
    mtx.unlock();
    return loggerInstance;
}

void user1logs(){
    Logger *logger1 = Logger::getLogger();
    logger1->Log("this msg is from user 1");
}
void user2Logs(){
    Logger* logger2 = Logger::getLogger();
    logger2->Log("this msg is from user 2");
}

int main(){

    thread t1(user1logs);
    thread t2(user2Logs);

    t1.join();
    t2.join();
    
    return 0;
}