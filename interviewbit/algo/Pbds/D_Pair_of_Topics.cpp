#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
#define I long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<I, I>, null_type, less<pair<I, I>>, rb_tree_tag, tree_order_statistics_node_update>pbds;
int main(){
    I n;
    cin>>n;
    pbds pb;
    vector<pair<I, I>>ar(n);
    for(I i=0;i<n;i++){
        cin>>ar[i].first;
    }
    for(I i=0;i<n;i++){
        cin>>ar[i].second;
    }
    I ans =0;
    for(I i=0;i<n;i++){
        ans += pb.size() - pb.order_of_key({(ar[i].second - ar[i].first), 10000000});
        pb.insert({(ar[i].first- ar[i].second), i});
    }
    std::cout<<ans<<endl; 
    return 0;
}