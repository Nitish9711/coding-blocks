#include<iostream>
#include<stack>
using namespace std;

template<typename T>
class queue{
 
    stack<T> s1;
    stack<T> s2;
    public:
        void push(T d){
            s1.push(d);
        }
        void pop(){
            while(s1.size()> 1){
               T element = s1.top();
               s1.pop();
                s2.push(element);
            }
            s1.pop();

            while(!s2.empty()){
                T element = s2.top();
               s2.pop();
                s1.push(element);         
            }
        }
        T front(){
            T ans;
            while(s1.size()> 1){
             T element = s1.top();
               s1.pop();
                s2.push(element);
            }
            ans = s1.top();

            while(!s2.empty()){
                T element = s2.top();
                s2.pop();
                s1.push(element);
                        
            }
            return ans;
        }
        void isEmpty(){
            return s1.empty();

        }
};
int main(){

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout<< q.front()<<endl;
    q.pop();
    cout<< q.front()<<endl;
    return 0;
}