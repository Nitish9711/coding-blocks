#include<iostream>
#include<set>
#include<string>
using namespace std;


set<string> s;

void permute(char * in, int i){

  if(in[i] == '\0')
    {   
        s.insert(in);
        // cout<<in<<endl;
        return;
    }

    for(int j =i;in[j]!= '\0';j++)
    {
        swap(in[j], in[i]);
        permute(in, i+1);
        swap(in[j], in[i]);
    }
}

int main()
{
    char in[11];
    cin>>in;

    permute(in, 0);

    for(auto it: s)
    {
        if(it < in)
            cout<<it<<endl;
    }
    return 0;
}