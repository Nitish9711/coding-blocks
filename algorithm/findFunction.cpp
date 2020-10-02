#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// passing funciton as a parameter
int add(int a, int b)
{
    return a == b;
}
void result(int c, int(&cmp)(int a, int b)){
 cout<<c;
}

int main()
{
    int arr[] = {1, 10, 11, 40, 90, 100};
    int n = sizeof(arr)/sizeof(int);
    

    // find 
    // it will return the size of array if element not found

    int key;
    cin>>key;
    auto it = find(arr, arr+n, key);
    int index = it - arr;
    cout<<index;

    //binary search function
    // it will return true or falls depending upon we got the file or not
    bool present = binary_search(arr, arr+n, key);
    if(present){
        cout<<"Present"<<endl;
    }
    else
    {
        cout<<"Absent"<<endl;
    }
    
    // to find the addresss of where the element is stored 
    // lower_bound function will return the address  of first element wich is greater than or equal to key;


    // upper_bound function will return the address of first element which is strickly greater to key  
    // we can use this to find the frequency of elements in a given sorted array by upper_bound - lower_bound
    // time complexity is log(n) for both the funcitons
    auto i = lower_bound(arr, arr+n, 40);
    cout<<i-arr<<endl;
    
    // sort function does not consider the last element thus we write sort(ar, ar+n);

    // rotate array 
    rotate(arr, arr+2, arr+n );
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;
    vector<int>v{1,2,3,65,5};

    vector<int>v1{3,2,1};

    cout<<*(v.begin()+3)<<endl;
    int m = *max_element(v.begin(), v.begin()+3);
    cout<<m<<endl;
    // Next_permuation generates array having number greater than the no formed by the elements
    // it returns false if no next_permutation is present

    next_permutation(v1.begin(), v1.end());
    for(int x:v){
        cout<<x<<" ";
    }


    int a= 10;
    int b= 10;
    swap(a, b);
    cout<<a<<" and "<<b<<endl;

    int ar[] = {1,2,3,4,5};
    reverse(ar, ar+4);
    

   for(int i=0;i<5;i++)
   {
       cout<<ar[i]<<" ";
   }


    // pair container in c++

    pair<int, char>p;
    p.first = 10;
    p.second = 'B';

    pair<int, char>p2(p);
    
    // make pair function in c++
     pair<int, string> p3 = make_pair(100, "audi");

    pair<pair<int,int>, string>car;
    car.second = "Audi";
    car.first.first = 10;
    car.first.second = 20;

    cout<<car.second<<endl;
    cout<<car.first.first<<endl;
    





    return 0;
}