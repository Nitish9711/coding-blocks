#include<iostream>
#include<list>


using namespace std;

class Queue{
    int cs;
    list<int>l;

    public:
        Queue(){
            cs = 0;
        }

        bool isEmpty(){
            return cs ==0;
        }
        void push(int d){
            l.push_back(d);
            cs++;
        }

        void pop(){
            if(!isEmpty()){
                l.pop_front();
                cs--;
            }
        }

        int front(){
           return l.front();
        }

};

int main(){

    Queue q;
    for(int i=1;i<=10;i++){
        q.push(i);
    }

    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}