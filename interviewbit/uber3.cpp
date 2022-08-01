#include <bits/stdc++.h>

using namespace std;

#define asc(i,a,n) for(I i=a;i<n;i++)
#define I long long int
#define md 998244353
#define N 2000000


I modex(I a,I b,I m){
  a=a%m;
  if(b==0){
    return 1;
  }
  I temp=modex(a,b/2,m);
  temp=(temp*temp)%m;
  if(b%2){
    temp=(temp*a)%m;
  }
  return temp;
}
I mod(I a,I b,I m){
  a=a%m;
  b=b%m;
  I c=__gcd(a,b);
  a=a/c;
  b=b/c;
  c=modex(b,m-2,m);
  return (a*c)%m;
}
I ncr(I n,I r,I fact[],I m){
  if(n<0 || r<0){
    return 0;
  }
  if(n<r){
    return 0;
  }
  return mod(fact[n],fact[n-r]*fact[r],m);
}
I fact[N];
int main(){
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<I> randGen;
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  fact[0]=1;
  asc(i,1,N){
    fact[i]=fact[i-1]*i;
  }
  I t;
  cin>>t;
  while(t--){
    I k,l,n;
    cin>>k>>l>>n;
    I ans=0;
    asc(i,1,n+1){
      ans+=((ncr(i-1,k-1,fact,md)*ncr(n-i,l-k,fact,md))%md)*i;
      ans%=md;
    }
    cout<<ans<<'\n';
  }
  return 0;
}