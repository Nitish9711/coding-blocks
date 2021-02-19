#include <iostream>
#include<vector>
#include<string>
using namespace std;
#define ll long long 
#define null NULL


template<typename T>
class Node{

    public:
    string key;
    T value;
    Node<T>*next;
    Node(string key, T val){
        this->key = key;
        value = val;
        next = null;
    }
    ~Node(){
        if(next != null){
            delete next;
        }
    }
};

template<typename T>

class Hashtable{

    Node<T>** table;
    int table_size;
    int current_size;
    int hashFn(string key){
        int idx = 0;
        int p = 1;
        for(int i =0;i<key.length();i++){
            idx = idx + (key[i]*p)%table_size;
            idx = idx%table_size;
            p = (p*27 )%table_size;
        }
        return idx;
    }
    void rehash(){
        Node<T>**oldTable = table;
        int oldTableSize = table_size;
        table_size = 2*table_size;
        table = new Node<T>*[table_size];

        for(int i=0;i<table_size;i++){
            table[i] = null;
        }
        current_size = 0;
        for(int i=0;i<oldTableSize;i++){
            Node<T>*temp = oldTable[i];
            while (temp!= null)
            {
               insert(temp->key, temp->value);
               temp = temp->next;
            }

            if(oldTable[i]!= null){
                delete oldTable[i];
            }
            
        }

        delete [] oldTable;
        
    }

    public:

        Hashtable(int ds = 7){
            table_size = ds;
            current_size =0;
            table = new Node<T>*[table_size];
            for(int i =0;i<table_size ;i++){
                table[i] = null;
            }
        }
        void insert(string key, T value){
            int idx = hashFn(key);
            Node<T> *n = new Node<T>(key, value);
            n->next = table[idx];
            table[idx] = n;
            current_size++; 

            // rehash...
            float load_factor  = current_size/(1.0*table_size);
            if(load_factor > 0.7){
                rehash();
            } 
        } 
        void print(){
            
            for(int i=0;i<table_size;i++){
                cout<<"Bucket "<<i<<" ->";
                Node<T>*temp = table[i];
                while (temp!= null)
                {
                    cout<<"( "<<temp->key<<", "<<temp->value<<" )" <<" -";
                    temp = temp->next;
                }
                cout<<endl;
                
            }
        }
        T* search(string key){
            int idx = hashFn(key);
            Node<T>*temp = table[idx];
            while(temp!= null){
                if(temp->key == key){
                    return &temp->value;
                }

                temp = temp->next;
            }
            return null;
            
        }
        void erase(string key){
            // int idx = hashFn(key);
            // Node<T>*temp = table[idx];
            // while(temp!= null){
            //     if(temp->key == key){
            //         return &temp->value;
            //     }

            //     temp = temp->next;
            // }
            // return null;
        }

        T& operator[] (string key){
            T*f = search(key);
            if(f == null){
                T garbage;
                insert(key, garbage);
                f = search(key);
            }

            return *f;
        }
    
};



int main()
{
    
    Hashtable<int> price_menu;
    price_menu.insert("pepsi", 15);
    price_menu.insert("Burer", 20);
    price_menu.insert("Noodels", 120);
    price_menu.insert("coke", 150);
    price_menu.insert("orange", 25);

    price_menu.print();
    
    cout<<*price_menu.search("pepsi")<<endl;
    price_menu["pepsi"] += 90;
    cout<<*price_menu.search("pepsi")<<endl;


    return 0;
}