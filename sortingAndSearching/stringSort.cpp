#include<iostream>

using namespace std;

void print(string s[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        cout << s[i] << endl;
    }   
}
bool isprefix(string str1, string str2)
{

    int l1 = str1.length();
    int l2 = str2.length(); 

    int temp =0;
    for(int i=0;i<l1;i++)
    {
        if(str1[i] == str2[i])
            temp++;
    }
    if(temp == l1)
        return true;


   return false;
}
void StringSort(string s[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            
            if(s[i] > s[j] || (s[j] > s[i] && isprefix(s[i], s[j])))
            {  
                // cout<<i<<" "<<j<<endl;
                swap(s[i], s[j]);
            }
            
        

        }
    }

    print(s, n);
}


int main()
{
    int n;
    cin>>n;
    
    string s[n];

    for(int i=0;i<n;i++)
        cin>>s[i];
    
    
    
    StringSort(s, n);
    
    return 0;
}