#include <iostream>
#include <deque>
#include <string>
using namespace std;


void output(string s){
    
    int n  = s.length();    
    int cur_len = 1;
    int max_len = 1;

    int visited[256];
    for(int i=0;i<256;i++){
        visited[i]  = -1;
    }

    visited[s[0]] = 0;

    for(int i =1;i<n;i++){
        int last_occ = visited[s[i]];
        if(last_occ == -1 || i-cur_len > last_occ){
            cur_len +=1;
            max_len = max(cur_len , max_len);
        }
        else{
            max_len = max(cur_len , max_len);
            cur_len = i - last_occ;

        }

        max_len = max(cur_len , max_len);
        visited[s[i]] = i;
    }

    cout<<max_len<<endl;

}
// 1
// ABCDEFGHIJKKLMNOPQRSTU

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        output(s);
    }
    return 0;
}