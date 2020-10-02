#include <iostream> 

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
  
int main(void) 
{ 
    int arr[] = { 2, 3, 4, 10, 40 }; 
    int x = 10; 
    int n = sizeof(arr) / sizeof(arr[0]); 
//     int result = search(arr, n, x); 
//    (result == -1)? cout<<"Element is not present in array" 
//                  : cout<<"Element is present at index " <<result;


    float b[] = {1.2, 1.3 , 1.24, 1.5};
    float k = 1.5;
    int result = search(b, 4, k); 
   (result == -1)? cout<<"Element is not present in array" 
                 : cout<<"Element is present at index " <<result;
    
   return 0; 
} 