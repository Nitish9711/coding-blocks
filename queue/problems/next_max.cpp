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

        int pop(){
            int ans;
            if(!empty()){
                 ans = arr[f];
                f = (f+1)%ms;
                cs--;
            }
            else
            {
                cout<<"queue is empty  "<<endl;
            }

            return ans;
            
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

void next_max(queue q){
    int x = q.pop();
    q.push(x);
    int z = INT16_MIN;
    while(z!= x){
        z = q.front();
        if(z > x){
            cout<<z<<" ";
            return;
        }
        
    }
    cout<<"-1"<<" ";
    return;
}


int main(){

    int n;
    cin>>n;
    queue q(n);
    int d;

    for(int i=0;i<n;i++)
    {
        cin>>d;
        q.push(d);
    }

    for(int i=0;i<n;i++){
        next_max(q);
    }
    


    return 0;
}