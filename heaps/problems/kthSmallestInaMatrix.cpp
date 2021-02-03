#include <iostream>
#include<queue>
#include<utility>
using namespace std;
#define node pair<int, pair<int, int>>

int kthSmallest(int mat[4][4], int n, int k){
    //  priority_queue<node, vector<node>, greater<node>> pq;
    priority_queue<node, vector<node>, greater<node>>pq;

    
    for(int i =0;i<4;i++){
      
        pq.push(make_pair(mat[0][i], make_pair(0, i)));
    }
    // cout<<pq.size()<<endl;

//    while(!pq.empty()){
//         cout<<pq.top().first<<" "<<pq.top().second.first<<" "<<pq.top().second.second<<endl;
//         pq.pop();
//     }

    for(int i =0;i<k;i++){
        node p = pq.top();
        pq.pop();
        if(p.second.first >= n-1){
            return -1;
        }
        else{
            p = make_pair(mat[p.second.first+1][p.second.second], make_pair(p.second.first+1, p.second.second));
        }
    }

    cout<<pq.top().first<<endl;
    return pq.top().first;



}
int main() {

   int mat[4][4] = {
        { 10, 20, 30, 40 },
        { 15, 25, 35, 45 },
        { 25, 29, 37, 48 },
        { 32, 33, 39, 50 },
    };
    // cout << "7th smallest element is "
        kthSmallest(mat, 4, 7);
    return 0;
}
