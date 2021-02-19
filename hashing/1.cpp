// find the smallest windows in a string containing all characters of another string.

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

int main()
{
     string s = "this is a test string";
    string p = "tist";

    int sl = s.length();
    int pl = p.length();
    int FS[256] = {0};
    int FP[256] = {0};
    for(int i=0;i<pl;i++){
        // char ch = p[i];
        FP[p[i]]++;
    }
    int cnt = 0;
    int start = 0;
    int min_len = INT_MAX;
    int start_idx =-1;
    for(int i =0;i<sl;i++){
        // char ch = s[i];
        FS[s[i]]++;

        // maintaing the cnt of characters matched
        if(FS[s[i]] <= FP[s[i]]){
            cnt++;
        }

        if(cnt == pl){
            // shrinking the window
            char temp  = s[start];
            while(FP[s[start]] == 0 or FS[s[start]] > FP[s[start]] ){
                if(FS[s[start]] > FP[s[start]])
                    FS[s[start]]--;
                start++;
                // temp = s[start];
            }
        }
        // windows size
        int len_window  = i - start + 1;

        if(len_window  < min_len){
            min_len = len_window ;
            start_idx  = start;
        }

    }

    if(start_idx == -1){
        cout<<""<<endl;
    }
    else{
        cout<<min_len<<endl;
        string ans = s.substr(start_idx, min_len);
        cout<<ans<<endl;
    }
    return 0;
}