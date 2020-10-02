#include<iostream>

using namespace std;




void replace(char s[], int i)
{
    if(s[i] =='\0' or s[i+1] == '\0')
        return;


    if(s[i] == 'p' && s[i+1] == 'i' )
    {
        int j = i+2;
        while (s[j] !='\0')
        {

            j++;
        }
        while(j >=i+2)
        {
            s[j+2] = s[j];
            j--;
        }
        s[i] = '3';
        s[i+1] = '.';
        s[i+2]=  '1';
        s[i+3]=  '4';

        replace(s, i+4);
        
    }
    
    else
    {
        replace(s, i+1);
        
    }
    
    return ;

    
    
}

int main()
{
  int t;
  cin>>t;
  while (t--)
  {
       char s[1000] ;
        cin>>s;

        replace(s, 0);
        cout<<s<<endl;
  }
  
    
    
    return 0;
}