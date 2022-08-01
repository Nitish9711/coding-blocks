#include<bits/stdc++.h>
#define int long long
#define N 100010
using namespace std;
inline int read(){
int x=0,f=1; 
char c=getchar();
while(c<48)
{
    if(c=='-') f=0;c=getchar(); 
}
    while(c>=48) x=(x<<3)+(x<<1)+(c^48), c=getchar(); 
    return f?x:-x;
    }
    
    int n,m,k;
    int a[N];
    bool check(int n, int m){
int s=0; for(int i=1;i<=k;i++){
int val=a[i]/n; if(val<2) return 0; s+=val;
if(s>=m&&2*i<=m) return 1; 
}return 0;
}
void solve(){
n=read(); m=read();k=read() ;
for(int i=1;i<=k; i++) a[i]=read();
sort(a+1, a+k+1); reverse(a+1, a+k+1);
if (check (n,m) || check (m,n)) cout<<"Yes"<<endl; else cout<<"No"<<endl;
}



signed main(){
   int t;
   cin>>t;
   while(t--) solve();
   return 0;
}