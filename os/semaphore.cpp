#include <bits/stdc++.h>
#include <mutex>
#include <thread>
#include <semaphore.h>
using namespace std;


binary_semaphore sem(1);

void add(int* x, int val) {
    sem.acquire();
    int y = *x;
    y += val;
    *x = y;
    sem.release();
}

int32_t main() {
    IO();
    int x = 10;
    thread t1(add, &x, 5), t2(add, &x, -5);
    t1.join();
    t2.join();
    cout << x;
}