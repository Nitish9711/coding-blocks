#include<iostream>
#include<string>

using namespace std;

int main()
{
    string input;
    cin>>input;
    int len;
    len = input.length();

    string output;

    output.push_back(input[0]);
    int j=1;
    int i =1;
    int digit =1;
    
    while(i<len)
    {
        
        if(input[i] == input[i-1])
        {
            digit++;
            i++;
        }
        else
        {
            
            output.append(to_string(digit));
            j++;
            digit = 1;
            output.push_back(input[i]);
            i++;
            j++;
        }
    }
    output.append(to_string(digit));
    input = output;
    cout<<input<<endl;
    
    return 0;
}