#include<iostream>
#include<stack>

using namespace std;

int getMaxArea(int his[], int n){

    stack<int>s;
    int maxArea = 0;
    int curArea = 0;
    int i = 0;
    int tp ;
    while(i<n){
        
        if(s.empty() || his[s.top()] < his[i])
            s.push(i++);
        
        else
        {
            tp = s.top();
            s.pop();

            curArea = his[tp]* (s.empty()? i: i - s.top()- 1);

            maxArea = max(curArea, maxArea);
        }
        
    }

    while(s.empty() == false){
        tp = s.top();
        s.pop();
        curArea = his[tp]* (s.empty()? i: i - s.top()- 1);
         maxArea = max(curArea, maxArea);
    }

    return maxArea;

}


int main(){

    int hist[] = {6, 2, 5, 4, 5, 1, 6}; 
    int n = sizeof(hist)/sizeof(hist[0]); 
    cout << "Maximum area is " << getMaxArea(hist, n); 
    return 0; 
    return 0;
}