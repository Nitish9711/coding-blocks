#include<iostream>
#include<stack>
using namespace std;


int main(){
    stack<int> s;
    
    s.push(23);
    s.push(2);
    s.push(1);
    cout<<s.top()<<endl;
    s.pop(); 
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }



    return 0;
}