#include<bits/stdc++.h>

using namespace std;

#define pi 3.1415926536
#define pb push_back
#define endl "\n"
#define bs binary_search
#define int long long
#define float double



int inf = 1e18;
int ans = inf;
int n,m,k;
vector<vector<int>> a1,b1;

int avg(int l,int r,int n1,int m1){
    int d =  (n1-l+1)*(n1-l+1);
    int s  = b1[n1][m1] - b1[l-1][m1]-b1[n1][r-1]+b1[l-1][r-1];
    float ans = s/d;
    if(ans>=k){
        return 1;
    }
    return 0;
}

int func(int ul,int ur,int ll,int lr){
        int n1= ll,m1=lr;
        int ml,mr;
        while(ul<=ll){
            ml = (ul+ll)/2;
            mr = (ur+lr)/2;
            if(avg(ml,mr,n1,m1)){
                ll=ml-1;
                lr=mr-1;
            }
            else{
                ul=ml+1;
                ur=mr+1;
            }
        }
        return n1-ul+1;
}

int32_t main(){
ios::sync_with_stdio(0);
cin.tie(0);
int t=1;
cin>>t;
while(t--){
    cin>>n>>m>>k;
    a1.clear();
    b1.clear();

    //int a[n+1][m+1],b[n+1][m+1];
    for(int i=0;i<=n;i++){
        vi temp;
        for(int j=0;j<=m;j++){
            temp.pb(0);
        }
        a1.pb(temp);
        b1.pb(temp);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a1[i][j];
            b1[i][j]=a1[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            b1[i][j]= b1[i][j-1]+b1[i][j];
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            b1[i][j] = b1[i-1][j]+b1[i][j];
        }
    }
    int ans=0;
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            ans+=func(i-min(i,j)+1,j-min(i,j)+1,i,j);
        }
    }
    cout<<ans<<endl;
}
}