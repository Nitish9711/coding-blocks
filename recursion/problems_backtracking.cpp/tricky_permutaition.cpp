#include<iostream>
#include<set>
#include<string>
using namespace std;

set<string>output;

void generate_permutation(char *in, int i)
{
    if(in[i] == '\0')
    {
        output.insert(in);
        return;
    }

    for(int j = i;in[j]!='\0';j++)
    {
        swap(in[i], in[j]);
        generate_permutation(in, i+1);
        swap(in[i], in[j]);
    }

    
}

int main()
{
    char str[10];
    cin>>str;
    
    generate_permutation(str, 0);
    for(auto it: output)
        cout<<it<<endl;

    return 0;
}