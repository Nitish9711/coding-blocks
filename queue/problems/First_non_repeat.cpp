#include<iostream>
#include<queue>

using namespace std;

void output(queue<char> , int fre[] ){

}

int main(){
    queue<char>q;
    int fre[27]={0} ;


    char ch;
    cin>>ch;
    while(ch!='.'){
        q.push(ch);
        fre[ch-'a']++;

        // query 
        while(!q.empty()){
            
            int element = q.front() -'a';
            if(fre[element] > 1){
                q.pop();
            }
            else
            {
                cout<<"out "<<q.front()<<endl;
                break;
            }
        }
        if(q.empty())
            cout<<"-1"<<endl;
            

        

        cin>>ch;
    }





    return 0;
}