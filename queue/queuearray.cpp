#include <iostream>

using namespace std;

class Queue
{
    int *arr;
    int f, r, cs, ms;

public:
    Queue(int ds = 5)
    {
        arr = new int[ds];
        cs = 0;
        ms = ds;
        f = 0;
        r = ms - 1;
    }

    bool full()
    {
        return cs == ms;
    }

    void push(int data)
    {
        if (!full())
        {
            r = (r + 1) % ms;
            arr[r] = data;
            cs++;
        }
    }

    bool empty()
    {
        return cs == 0;
    }

    void pop()
    {
        if (!empty())
        {
            f = (f + 1) % ms;
            cs--;
        }
    }

    int front()
    {
        if (!empty())
            return arr[f];

        return 0;
    }
    ~Queue()
    {
        delete arr;
    }
};

int main()
{

    Queue q;
    for (int i = 1; i <= 6; i++)
    {
        q.push(i);
    }
    q.pop();
    q.pop();
    q.push(7);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}