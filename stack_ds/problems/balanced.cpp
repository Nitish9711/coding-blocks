#include <iostream>
#include<stack>
#include<string>
using namespace std;


bool check(string str){

    stack<char>s;

    for(int i=0;i<str.length();i++){
        if(str[i] == '{' || str[i] == '(' || str[i] == '['){
            s.push(str[i]);
            continue;
        }
        if(s.empty())
            return false;
        
       if(str[i] == '}'){
           if(s.top()  == '{')
                s.pop();
            else
                return false;
       }
       if(str[i] == ')'){
           if(s.top()  == '(')
                s.pop();
            else
                return false;
       }
       if(str[i] == ']'){
           if(s.top()  == '[')
                s.pop();
            else
                return false;
       }
    }

    return s.empty();
}

int main()
{
    string s;
    cin>>s;
    if(check(s))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}