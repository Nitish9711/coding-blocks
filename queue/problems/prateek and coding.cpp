#include <iostream>
#include<stack>
using namespace std;


int answer(stack<int>&s){


    int ans = s.top();
    s.pop();
    return ans;
}

int main()
{
    stack<int>s;
    int q;
    cin>>q;
    int type, cost;
    for(int i=0;i<q;i++){
        cin>>type;
        if(type == 2){
            cin>>cost;
            s.push(cost);
        }
        else{
            if(!s.empty())
                cout<<answer(s)<<endl;
            else{
                cout<<"No Code"<<endl;
            }
        }
    }
    
    return 0;
}