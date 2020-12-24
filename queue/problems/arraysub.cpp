#include <iostream>
#include <deque>
using namespace std;

void printKMax(int ar[], int n, int k)
{

    deque<int> q(k);

    int i;
    for (i = 0; i < k; i++)
    {

        while (!q.empty() && ar[i] >= ar[q.back()])
        {
            q.pop_back();
        }

        q.push_back(i);
    }

    for (; i < n; i++)
    {
        cout << ar[q.front()] << " ";

        while (!q.empty() && q.front() <= i - k)
        {
            q.pop_front();
        }
        while (!q.empty() && ar[i] >= ar[q.back()])
        {
            q.pop_back();
        }

        q.push_back(i);
    }
    cout << ar[q.front()] << " ";
}

int main()
{

    int arr[] = {12, 1, 78, 90, 57, 89, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);

    return 0;
}