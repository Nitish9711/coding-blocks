#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> v;
    vector<int> b(5, 10); // five elements with value 10
    vector<int> c(b.begin(), b.end());
    
    int n;
    cin>>n;
    v.reserve(100);

    // we should avoid using below loop without using reserve beacuse it is an time taking operation as doubling of size of array occur
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp); // benefit of using push_back is that it automatically increase the size of vector whereas if we normall use cin
                            // then it will give segmental fault 
                            //for most of time time complextiy is O(1) for push_back and pop_back
    }
    v.pop_back();
    sort(v.begin(),v.end());
    cout<<v.capacity()<<endl; // size of underlying array


    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    cout<<v.max_size()<<endl;
    
    // insert 
    b.insert(v.begin()+3,1000);  // will add the 1000 at 4th position
    b.insert(v.begin()+3, 4, 1000); // will add the four 1000 after the third position time-complexity  O(n)


    // erase
    b.erase(b.begin()+ 2);
    b.erase(b.begin(), b.begin()+3);

    // resize
    b.resize(8);
    // if the we are increasing the size then memory will be allocated and capacity will change otherwise capacity will remain the same
        






   return 0;
}