#include<iostream>
#include<stack>

using namespace std;


void insertAtBottom(stack<int> &s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }

    // rec case
    int data = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(data);


}
void reverse(stack<int> &s){
    
    // base case
    if(s.empty()){
        return;
    }

    int x = s.top();
    s.pop();

    // rec reverse
    reverse(s);
    insertAtBottom(s, x);

   
}


int main(){

   stack<int >s;
    int n;
    cin>>n;
    int d;
    
    for(int i=0;i<n;i++){
        cin>>d;
        s.push(d);
    }
    reverse(s);
     while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}