#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL

bool check(string str, int n)
{

    if(n%2 != 0){
        return false;
    }
    if (str[0] == ')' || str[n - 1] == '(')
        return false;

    stack<char> s;
    int i = 0;
    while (i < n)
    {
        if (str[i] == '(' || str[i] == '?')
        {
            s.push(str[i]);
        }
        else
        {
            if (s.empty())
            {
                return false;
            }

            else
            {
                s.pop();
            }
        }
        i++;
    }

    while (!s.empty())
    {
        if(s.top()!= '?')
            return false;
        s.pop();
    }
    
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();

        if (check(s, n))
        {
            cout << "YES" << endl;
        }
        else
        {

            cout << "NO" << endl;
        }
    }
    return 0;
}