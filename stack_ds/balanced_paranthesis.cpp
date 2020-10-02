#include<iostream>
#include<stack>

using namespace std;


bool isValidExp(char s[]){
    stack<int>s1;

    for(int i =0;i< s[i]!='\0';i++){
        char ch = s[i];

        if(ch == '('){
            s1.push(ch);
        }
        else if(ch == ')'){
            if(s1.empty() or s1.top()!= '('){
                return false;
            }
            s1.pop();
        }
    }

    return s1.empty();
}

int main(){
    char s[] = "((a+b)+ (c-d+f))";
    if(isValidExp(s)){
        cout<<"yes";
    }
    else
        cout<<"no"<<endl;

    return 0;
}