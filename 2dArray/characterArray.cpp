#include<iostream>
#include<string>
using namespace std;

int main()
{
    //every character array is terminated by null character '\0'

    char a[20]; // it is a character array of size 20 having garbage value
                // if we do cout before taking input in this array it can either gives us a grabage value or null character '\0'
     

    cout<<a<<endl;  // it will start from a non null character and read till the null character
    cout<<sizeof(a)<<endl;

    //char b[] ={ 'a', 'b', 'c'}; 
    /* here since we do not have given the size of it wil automatically create a character array of size 3. if we do cout either we 
    will get null or abc that's why we should declare it like this */
    char b[] ={ 'a', 'b', 'c', '\0'};
    cout<<b<<endl;

    char c[] ="hello";
    /* In this way of intialization we do not required to give the null character separately it will automaticallu terminated 
    by null character*/
    cout<<c<<endl;
    cout<<sizeof(c)<<endl;

    /* if we need to take input containing special character like space tab etc we should use 
    cin.getline(varable, maxsize, 'delimiter') by default delimiter is '\n'*/

    char d[100];

    cin.getline(d, 100);
    cout<<d<<endl;
    for(int i=0;(d[i]!=' '&& d[i]!='/0');i++)
    
   




    return 0;
}