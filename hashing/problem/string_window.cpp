#include <iostream>
#include<unordered_map>
#include<string>
#include<climits>
using namespace std;

#define no_of_char 256

int main() {
    string str, pat;
    getline(cin, str);
    getline(cin, pat);
    int len1= str.length();
    int len2 = pat.length();

    if(len2 > len1){
        cout<<"No String"<<endl;
        return 0;
    }

    int hash_pat[no_of_char] = {0};
    int hash_str[no_of_char] = {0};

    for(int i = 0;i<len2;i++){
        hash_pat[pat[i]]++;
    }

    int start = 0, min_len = INT_MAX, start_idx = -1;
    int count = 0;
    for(int i =0;i<len1;i++){

        hash_str[str[i]]++;

        if(hash_str[str[i]] <= hash_pat[str[i]])
            count++;

        if(count == len2){
        while(hash_str[str[start]] >hash_pat[str[start]] || hash_pat[str[start]] == 0){
            if(hash_str[str[start]] > hash_pat[str[start]])
                hash_str[str[start]]--;
            start++;
        }
          int temp = i - start +1;
        if(min_len > temp){
            min_len = temp;
            start_idx = start;
        }
        }
      
    }


    if(start_idx == -1){
         cout<<"No String"<<endl;
    }
    else{
        cout<<str.substr(start_idx, min_len)<<endl;
    }


}
