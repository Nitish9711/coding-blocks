#include<iostream>
//#include<cstring>
#include<algorithm>

using namespace std;
bool compareString(string a, string b)
{
    // return (a.length()>b.length()); // it means if a.length()>b.length() in that case return true
    return a<b;
}



int main()
{
    /*string is  an inbuilt class in c++ STL
      char s[x][y] -list of string using character array here x represents the no of arrays and y represents the maximum size of each 
      string  */
    // to get a string getline(cin,s)

    // to intilize string varible
    string s("string 1 ");
    string b = "string 2";

    cout<< s<<endl;
    cout<< b << endl;
    // to print the length

    // to check string is empty or not we can use  s.empty()
    // we can add something in string by s.append()  
    // to clear everything from the string 
    // we can compare two strings by s.compare() 
    // we can also use relational operators for strings because they are overloaded for strings 

    // Finding index of substring 
    string str = "I want to have apple juice";
    int idx= str.find("apple");
    cout<<idx<<endl;
    
    // to remove the word 
    string word = "apple";
    int len = word.length();
    str.erase(idx, len+1);
    cout<<str<<endl;
    
    //for each loop
    for(auto c:str)
    {
        cout<<c<<" ";
    }
    cout<<endl;

    cout<< b.length()<<endl;
    string c[] ={"apple","guava", "banana","apple","pineapple"};
    sort(c , c+4);
    for(int i=0;i<5;i++)
        cout<<c[i]<<endl;

    // sorting on another basis
    cout<<endl;
    string d[] ={"apple","guava", "banana","pineapple"};
    sort(d , d+4,compareString);




    
    for(int i=0;i<4;i++)
        cout<<d[i]<<endl;
    
    return 0;
}