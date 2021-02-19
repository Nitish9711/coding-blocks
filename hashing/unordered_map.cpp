#include <iostream>
#include<unordered_map>

#include<vector>
#include<string>

using namespace std;
#define ll long long 
#define null NULL

int main()
{
    
    unordered_map<string, int>m;
    m.insert(make_pair("Mango", 1502));
    m.insert(make_pair("apple", 130));
    m.insert(make_pair("juice", 1001));
    m.insert(make_pair("carrot", 1050));
    m["banana"] = 20;
    
    
    string key = "juice";
    auto it = m.find(key);
    // map<string, int>::iterator it = m.find(key);
    if(it!= m.end()){
        cout<<"price of "<<key<<" is "<<m[key]<<endl;
    }


    // it stores unique keys only once;
    if(m.count(key)){
        cout<<"price of "<<key<<" is "<<m[key]<<endl;
        
    }
   
   for(auto it = m.begin();it!= m.end();it++){
       cout<<(*it).first<<" and "<<(*it).second<<endl;;
       cout<<it->first<<" and "<<it->second<<endl;;
   }

    return 0;
}