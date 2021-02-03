// Making it clear, when the input size is odd, we take the middle element of sorted data. 
// If the input size is even, we pick average of middle two elements in sorted stream.

// Note that output is effective median of integers read from the stream so far. 
// Such an algorithm is called online algorithm.
//  Any algorithm that can guarantee output of i-elements after processing i-th element,
//   is said to be online algorithm. Let us discuss three solutions for the above problem.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int testCases ; 
    cin >> testCases ; 
    while(testCases--){
        long n ;
        long median ;
        priority_queue<long , vector<long> , greater<long> > minHeap ; 
        priority_queue<long> maxHeap ; 
        int minSize = 0 ;
        int maxSize = 0 ;
        int size ;
        cin >> size ;

        median = 0;
        while(size--){

            cin >> n;

            if(n < median){
                maxHeap.push(n);
                maxSize ++ ; 
            }
            else {
                minHeap.push(n);
                minSize ++ ; 
            }
            if(abs(minSize - maxSize) == 2){
                //Imbalance
                if(minSize > maxSize){
                    long temp = minHeap.top() ; 
                    minHeap.pop() ; 
                    minSize -- ;
                    maxHeap.push(temp);
                    maxSize ++ ; 
                }
                else {
                    long temp = maxHeap.top();
                    maxHeap.pop(); 
                    maxSize--;
                    minHeap.push(temp);
                    minSize++;
                }
            }

            //Recalculate median after every iteration
            if(minSize == maxSize){
                median = ( minHeap.top() + maxHeap.top() )/ 2 ;
            }
            else if(minSize > maxSize){
                median = minHeap.top() ;
            }
            else {
                median = maxHeap.top() ;
            }

            cout << median << " ";
        }
        cout << endl;
    }


    return 0;    
}
