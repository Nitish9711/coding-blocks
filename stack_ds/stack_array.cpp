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
    bool push(int x);
    void pop();
    void peek();
    void isEmpty();
    void display();
};

void stack:: display(){
    if(top == -1)
    {
        cout<<"stack has nothing to show\n";
        return;
    }
    cout<<ar[top]<<"<--"<<endl;
    for(int i=top-1;i>=0;i--){
        cout<<ar[i]<<endl;
    }
}
bool stack::push(int x){
    if(top> (MAX-1))
    {
        cout<<"stack overflow\n";
        return false;
    }
    ar[++top] = x;
    cout<< x <<" pushed into the stack\n";
    return true;
}

void stack::pop(){
    if(top<0){
        cout<<"Stack underflow"<<endl;
        return;
    }
    int x = ar[top--];
    cout<<x <<" is popped from the stack\n";
}

void stack::peek(){
    if(top<0){
        cout<<"Stack is Empty\n";
        return;
    }
    int x = ar[top];
    cout<<"Peek of the stack is "<<x<<"\n";
}

void stack::isEmpty(){
    if(top<0){
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        cout<<"Stack is not empty"<<endl;
    }
    
}




int main(){

    class stack s;
    s.push(10);
    s.push(30);
    s.push(20);
    s.peek();
    s.display();
    s.isEmpty();

    s.pop();
    s.peek();
    s.pop();
    s.pop();
    s.isEmpty();
    s.display();
    

    return 0;
}