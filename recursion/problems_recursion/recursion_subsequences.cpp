#include<iostream>
#include<string>
using namespace std;

long int temp = 0;

void generate_subsequence(string in, string out)
{
    if(in.size() == 0)
    {
        cout<<out<<" ";
        return;
    }
    char ch = in[0];
    in = in.substr(1);
    generate_subsequence(in, out);
    generate_subsequence(in, out+ch);

}

int main()
{
    string str;
    cin>>str;


    generate_subsequence(str," ");

    int ans = 1<<(str.size());
    cout<<endl;
    cout<<ans;
    

    return 0;
}