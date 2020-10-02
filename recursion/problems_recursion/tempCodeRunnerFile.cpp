#include <iostream>
#include<string>
// #include<vector>
using namespace std;

char keypad[][10]={" ","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz"};

// int i = 0;
void print(char* in, char * out, int i, int j, int &ctr)
{
    
    if(in[i] == '\0')
    {
        ctr++;
        out[j] = '\0';
        cout<<out<<" ";
        return;
    }

    int digit = in[i] - '0';

    for(int k =0;keypad[digit][k]!='\0';k++)
    {
        out[j] = keypad[digit][k];
        print(in, out, i+1, j+1, ctr);
    }

}

int main() {
    char in[100];
    cin>>in;
    char out[100];
    int ctr = 0;

    cout<<in<<endl;
    print(in,out,0,0, ctr);

    cout<<endl;
    cout<<ctr;
    return 0;
}