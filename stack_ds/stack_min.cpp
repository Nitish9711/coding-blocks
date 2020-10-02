// O(1) space and in O(1) time

#include<iostream>
#include<stack>

using namespace std;


class MyStack{
    stack<int>s;
    int minEle;
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
    cout<<"Currently minimum element is "<< minEle<<endl;
}
void MyStack:: peek(){
    
    if(s.empty()){
        cout<<"stack is empty"<<endl;
    }

    cout<<s.top()<<"\n";
}


void MyStack:: push(int x){
    
    if(s.empty()){
        minEle = x;
        s.push(x);
        return;
    }

    

    if(x >= minEle){
        s.push(x);
    }
    else
    {
        s.push(2*x - minEle);
        minEle = x;
    }
    
    


}

void MyStack:: pop(){

    if(s.empty()){
        cout<<"Stack is empty\n";
    }

    if(s.top() >= minEle){
        s.pop();
    }
    else
    {
        minEle = 2*minEle - s.top();
        s.pop();
    }
    
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