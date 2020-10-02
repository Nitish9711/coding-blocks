#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int mycompare(string X, string Y) 
{ 
    // first append Y at the end of X 
    string XY = X.append(Y); 
  
    // then append X at the end of Y 
    string YX = Y.append(X); 
  
    // Now see which of the two formed numbers is greater 
    return XY.compare(YX) > 0 ? 1: 0; 
} 


int main()
{
    int t;
    cin>>t;
    vector<vector<string>>v(t);
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        v[i] = vector<string>(n);
        for(int j = 0;j<n;j++)
            {
                cin>>v[i][j];
            }
        sort(v[i].begin(), v[i].end(), mycompare);
    }
    
    // for(int i =0;i<t;i++)
    // {
    //     for(int j =0;j<v[i].size();j++)
    //         cout<<v[i][j];
        
    //     cout<<endl;23
    // }
      

    return 0;
}