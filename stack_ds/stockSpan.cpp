#include <iostream>
#include<stack>
using namespace std;


void display(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}


void calculateSpan(int price[], int n, int output[]){

    stack<int>s;
    output[0] = 1;

    for(int i =0;i<n;i++){
        int cp = price[i];

        while(!s.empty() and price[s.top()] <=cp) {
            s.pop();
        }

        if(!s.empty()){
        int prev_highest = s.top();
        output[i] = i - prev_highest;
        }
        else{
            output[i] = i+1;
        }

        s.push(i);

    }


}


int main()
{
   int price[] = { 10, 4, 5, 90, 120, 80 }; 
   int n = sizeof(price) / sizeof(price[0]); 

   int output[10000] = {0};

   calculateSpan(price, n,output);

    for(int i=0;i<n;i++){
        cout<<output[i]<<endl;
    }
    return 0;
}