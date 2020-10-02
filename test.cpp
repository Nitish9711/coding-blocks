#include <bits/stdc++.h> 

using namespace std;

void change(char input[])
{
    int len = strlen(input);
    static int i = 0;
    if(len == 0)
        return;
    if(input[i] == '\0')
        return;
    if(input[i] == 'x')
    {
        for(int j = i;j<len;j++)
            input[j] = input[j+1];
        
        i++;
        change(input);
    }
    else
    {
        i++;
        change(input);        
    }
    
}
int main()
{
    char a[] ="xx";
    change(a);
    // a[1] = '\0';
    cout<<a<<endl;
   
    return 0;
}