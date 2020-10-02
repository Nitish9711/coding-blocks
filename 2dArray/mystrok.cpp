#include<iostream>
#include<cstring>

using namespace std;

char* mystrtok(char str[], char delim)
{
    static char* input = NULL;
    if(str!=NULL)
    {
        input = str;
    }
    if(input==NULL)
    {
        return NULL;
    }

    char* output = new char[strlen(input)+1]; // +1 is for null character at the end
    // a static array cannot be returned from a function that's why we are are creating a dyanamic array to return
    // read the word from input and store in output and just return the word till the delimiter
    int i;
    for( i=0; input[i]!='\0'; i++)
    {
        if(input[i]!=delim)
        {
            //copy the character in the output array
            output[i] = input[i];
        }
        else{
            // now we are at delim
            output[i] = '\0';
            input = input + i+1;
            return output;
        }
    }
    // return the last word if input is not there
        output[i] ='\0';
        return output;
}
int main()

{
    char str[] = {"Hi, my name is nitish"};
    char * ptr;
    

    ptr = mystrtok(str,' ');//strtok is a static variable which stores the state the state of string in the previous function call
    cout<<ptr<<endl;
    
    ptr = mystrtok(NULL,' ');
    cout<<ptr<<endl;



    return 0;
}