#include <iostream>

using namespace std;


void SubString(char input[])
{
    int c;
    for(c=0;input[c]!='\0';c++);
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<c;j++)
        {
            for(int k =i;k <=j;k++)
            {
                cout<<input[k];
            }    

            for(int m=0;m<1;m++)
                cout<<endl;
        }
        
        
    }
}
int main() 
{
    char str[] = "abcd";
    SubString(str);
    
    
   
    return 0;
}
