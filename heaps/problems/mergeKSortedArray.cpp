#include <iostream>
#include<queue>

using namespace std;
#define ll long long 
#define null NULL

#define node  pair<int, pair<int, int>>


vector<int>mergeKSortedArrays(vector<vector<int>>arr){

    vector<int>result;
    priority_queue<node, vector<node>, greater<node>> pq;

    for(int i=0;i<arr.size(); i++){
        node p = make_pair(arr[i][0], make_pair(i, 0));
        pq.push(p);
        // cout<<pq.top().first<<endl;
    }

  

    while (!pq.empty())
    {
        node current = pq.top();
        pq.pop();
        int element = current.first;
        int x = current.second.first;
        int y = current.second.second;
        result.push_back(element);
        // cout<<*result.begin()<<endl;

        if(y+1 <arr[x].size()){
            node p = make_pair(arr[x][y+1], make_pair(x, y+1));
            pq.push(p);
        }
    }

    return result;


}

int main()
{
    vector<vector<int>> arr {{2, 6, 12, 15}, {1, 3, 14, 20}, {3, 5, 8, 10}};


    vector<int>output=  mergeKSortedArrays(arr);
    for(auto x: output){
        cout<< x<<" ";
    }


    return 0;
}