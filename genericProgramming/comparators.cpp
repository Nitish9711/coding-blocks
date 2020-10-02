#include <iostream> 
// #include<algorithm
#include<list>
#include<vector>
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

// forward iterator + comparators

template<class ForwardIterator, class T, class Compare>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key, Compare cmp)
{
    while(start!=end)
    {
        if(cmp(*start , key))
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

class BookCompare{
    public:
        bool operator()(Book A, Book B){
            if(A.name == B.name)
                return true;
            
            return false;
        }
};

int main(void) 
{ 
   Book b1("C++", 100);
   Book b2("python", 120);
   Book b3("java", 130);
   

   vector<Book> l;
   l.push_back(b1);
   l.push_back(b2);
   l.push_back(b3);

   Book booktofind("C++", 110);
   BookCompare cmp;
//    if(cmp(b1, booktofind))
//         cout<<"True same books";

    // list<Book>::iterator it = search(l.begin(), l.end(), booktofind, cmp);
    auto it = search(l.begin(), l.end(), booktofind, cmp);

    if(it!= l.end()){
        cout<<" book found in the library";
    }
    else
    {
        cout<<"book not found";
    }
    
    
   return 0; 
} 