#include <iostream>
#include <deque>
using namespace std;
#define ll long int

int answer(deque<int> co, deque<int> io, int n)
{
    int ans = 0;

    while (!co.empty())
    {
        if (co.front() == io.front())
        {
            ans++;
            co.pop_front();
            io.pop_front();
        }
        else
        {
            int d = co.front();
            co.push_back(d);
            co.pop_front();
        }
    }
    return ans;
}

int main()
{

    int n;
    cin >> n;
    deque<int> co;
    deque<int> io;
    int d;
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        co.push_back(d);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        io.push_back(d);
    }

    cout << answer(co, io, n) << endl;

    return 0;
}