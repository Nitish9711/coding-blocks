#include <iostream> 
// #include<algorithm
#include<list>
using namespace std; 


template<typename T> 
int search(T arr[], int n, T x) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        if (arr[i] == x) 
            return i; 
    return -1; 
} 
  

// forward iterator
template<class ForwardIterator, class T>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key)
{
    while(start!=end)
    {
        if(*start == key)
            return start;
        
        start++;
    }

    return end;
}

class Book {
    public: 
    string name;
    int price;

    Book(){

    }
    Book(string name, int price){
        this->name = name;
        this->price = price;
    }
};

int main(void) 
{ 
   list<int> l;
   l.push_back(1);
   l.push_back(5);
   l.push_back(3);
   l.push_back(2);

    auto it = search(l.begin(), l.end(),50 );

    if(it == l.end())
    {
        cout<<"not found";
    }
    else    
        cout<<*it<<endl;

    
   return 0; 
} 