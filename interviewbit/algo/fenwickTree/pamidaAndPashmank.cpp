#include <iostream> 
#include <cstring> 
#include <algorithm> 
using namespace std ; 

const int MAXN = 1000 * 1000 + 10 ;      

int fen [ MAXN ];

void add ( int x , int val ) 
{
    for ( int i = x + 1 ; i < MAXN ; i += i & (- i )) {
        fen [ i ] += val ;   
        cout<<"fen "<<i<<" "<<fen[i]<<endl;
    } 
}

int get ( int x )
{
    int ans = 0 ; 
    for ( int i = x ; i > 0 ; i -= i & (- i )) ans += fen [ i ];   
    return ans ;
}

int sum ( int x , int y ) 
{
    return get ( y ) - get ( x ); 
}

int rem [ MAXN ], cnt [ MAXN ], a [ MAXN ], tot [ MAXN ], sz ;

int main ()
{
    ios :: sync_with_stdio ( false );

    int n ;
    cin >> n ;
    // cout<<sz<<endl;
    sz = 0;
    for ( int i = 0 ; i < n ; i ++) cin >> a [ i ], tot [ sz++] = a [ i ];   

    sort ( tot , tot + sz );
    
    sz = unique ( tot , tot + sz ) - tot ; 
    cout<<sz<<endl;
    for(int i=0;i<sz;i++)
        cout<<tot[i]<<" ";
    cout<<endl;
    for ( int i = 0 ; i < n ; i ++) a [ i ] = lower_bound ( tot , tot + sz , a [ i ]) - tot ;    
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    for ( int i = n - 1 ; i >= 0 ; i --)   
    {
        cnt [ a [ i ]] ++; 
        cout<<a[i]<<" "<<cnt[a[i]]<<endl;
        add ( cnt [ a [ i ]], 1 ); 
        rem [ i ] = cnt [ a [ i ]]; 
    }

    memset ( cnt , 0 , sizeof cnt );  
    long long ans = 0 ;  
    for ( int i = 0 ; i < n ; i ++)  
    {
        add ( rem [ i ], - 1 ); 
        
        cnt [ a [ i ]] ++; 
        ans += sum ( 1 , cnt [ a [ i ]]);
    }

    cout << ans << endl ;
    return 0 ; 
}