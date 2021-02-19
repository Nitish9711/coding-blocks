#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL
int RightAngled(int a[][2], int n) 
{ 
  
  unordered_map<int, int>x;
  unordered_map<int, int>y;

  for(int i=0;i<n;i++){
      x[a[i][0]]++;
      y[a[i][1]]++;
  }
   
   int cnt = 0;
   for(int i =0;i<n;i++){
       if(x[a[i][0]] >=1 && y[a[i][0]]>=1){
           cnt += (x[a[i][0]]-1)*(y[a[i][1]]-1);
       }
   }
   return cnt;
} 
  

int main()
{
    int N = 5; 
  
    // Given N points 
    int arr[][2] = { { 1, 2 }, { 2, 1 }, 
                     { 2, 2 }, { 2, 3 }, 
                     { 3, 2 } }; 
  
    // Function Call 
    cout << RightAngled(arr, N); 
    return 0;
}