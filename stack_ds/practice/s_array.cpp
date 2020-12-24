#include<iostream>

using namespace std;
#define MAX 1000

class stack{
    int top;
    public:
    int ar[MAX];

    stack(){
        top = -1;
    }
    void push(int x);
    void pop();
    int peek();
    bool isEmpty();
    void display();
};


int stack::peek(){
    if(top < 0){
        cout<<"stack is empty";
        return 0;
    }
    return ar[top];
}
void stack::display(){
    if(top == -1){
        cout<<"stack is empty"<<endl;
        return;
    }

    for(int i = top;i>=0;i--){
        cout<<ar[i]<<endl;
    }
}

void stack::push(int x){
    if(top >= MAX-1){
        cout<<"stack is full"<<endl;
        return;
    }

    
    ar[++top] = x;
}   

bool stack::isEmpty(){
    if(top < 0){
        cout<<"stack is empty"<<endl;
        return true; 
    }
    
    return false;
}

void stack::pop(){
    if(top < 0){
        cout<<"stack is empty"<<endl;
        return;
    }
    top--;
}


int main(){

    
    class stack s;
    s.push(10);
    s.push(30);
    s.push(20);
    cout<<s.peek()<<endl;
    if(s.isEmpty()){
        cout<<"stack is underflow"<<endl;
    }
    else{
        cout<<"not empty"<<endl;
    }
    
    s.display();
    // s.display();

    // s.pop();
    // s.peek();
    // s.pop();
    // s.pop();
    // s.isEmpty();
    // s.display();
    
    return 0;
}