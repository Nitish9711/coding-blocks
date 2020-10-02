#include<iostream>

using namespace std;

string keypad[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };


void print(char *in, char *out, int i, int j)
{
    if(in[i] == '\0')
    {
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }

    int digit = in[i] - '0';

    for(int k =0;keypad[digit][k]!='\0';k++)
    {
        out[j] = keypad[digit][k];
        print(in, out, i+1, j+1);
    }

}

int main()
{
    char in[11];
    cin>>in;
    char out[11] = {0};

    print(in ,out, 0, 0);
    
   
    return 0;
}