#include <bits/stdc++.h> 

using namespace std; 
int dx[]={1,0,0,-1,1,-1,1,-1}; 
int dy[]={0,-1,1,0,1,-1,-1,1};  

void solve(){ 
    int n,m; 
    cin>>n>>m; 

    vector<string> a(n); 
    for(int i =0;i<n;i++){ 
        cin>>a[i]; 
    } 
    bool b1 = false; 
    bool b2 = false; 

    int one = 0; 


    for(int i =0;i<n;i++){ 
        for(int j =0;j<m;j++){ 
            if(a[i][j]=='0'){ 
                b1=true; 
                for(int k =0;k<8;k++){ 
                    int nx = i+dx[k]; 
                    int ny = j+dy[k]; 

                    if(nx<n && nx>=0 && ny>=0 && ny<m && a[nx][ny]=='0'){ 
                        b2=true; 
                    } 
                } 
            }else{ 
                one++; 
            } 
        } 
    } 

    if(b2){ 
        cout<<one<<endl; 
    }else if(b1){ 
        cout<<one-1<<endl; 
    }else{ 
        cout<<one-2<<endl; 
    } 

}  
int main(){ 

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; 
    cin>>t; 

    while(t--){  
        solve(); 
    } 
}