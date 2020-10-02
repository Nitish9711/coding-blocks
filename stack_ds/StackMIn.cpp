// O(1) space and in O(1) time

#include<iostream>
#include<stack>

using namespace std;


class MyStack{
    stack<int>s;
    stack<int>min;
    public:
    void getMin();
    void peek();
    void push(int x);
    void pop();

};

void MyStack:: getMin(){
    if(s.empty()){
        cout<<"Stack is empty"<<endl;
    }
    cout<<"Currently minimum element is "<< min.top()<<endl;
}
void MyStack:: peek(){
    
    if(s.empty()){
        cout<<"stack is empty"<<endl;
    }

    cout<<s.top()<<"\n";
}


void MyStack:: push(int x){
    
    if(s.empty()){
        s.push(x);
        min.push(x);
        return;
    }

    s.push(x);
    if(x < min.top()){
        min.push(x);
    }
    else
        min.push(min.top());

}

void MyStack:: pop(){

    if(s.empty()){
        cout<<"Stack is empty\n";
    }
    s.pop();
    min.pop();
    
}

int main(){
    
    MyStack s;
    s.push(3);
    s.push(5);
    s.push(34);
    s.push(2);
    s.getMin();
    s.pop();
    s.pop();
    s.getMin();
    return 0;
}