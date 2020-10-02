#include<iostream>

using namespace std;


class queue{
    int *arr;
    int f, r, cs, ms;

    public:
        queue(int ds = 5){
            arr = new int[ds];
            cs = 0;
            ms = ds;
            f = 0;
            r = ms-1;
        }

        bool empty(){
            return cs == 0;
        }
        bool full(){
            return cs == ms;
        }
        void push(int data){
            if(!full()){
                r = (r+1) % ms;
                arr[r] = data;
                cs++;
                return;
            }

            cout<<"queue overflow "<<endl;

        }

        void pop(){
            if(!empty()){
                f = (f+1)%ms;
                cs--;
            }
            else
            {
                cout<<"queue is empty  "<<endl;
            }
            
        }

        int front(){
            if(!empty())
             return arr[f];
             
             cout<<"queue is empty "<<endl;
             return 0;
        }
        ~queue(){
            if(arr!= NULL)
            {
                delete[] arr;
                arr = NULL;
            }
        }
};


int main(){

    queue q;
    for(int i=1;i<=6;i++){
        q.push(i);
    }
    q.pop();
    q.pop();
    q.push(7);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}