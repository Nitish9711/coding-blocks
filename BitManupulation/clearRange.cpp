 #include<iostream>

using namespace std;

void clearLastBits(int &n, int i)
{
    int mask =  (-1<<i);
    n = n & mask;
}
void clearFirstBits(int &n, int i)
{
    int mask = (-1>>i);
    n = n & mask;
}

void clearRangeOfBits(int &n, int i, int j)
{
    int a = (-1<<(j+1));
    // 000 01111 is of the form of 2^n -1
    int b = (1<<i) - 1;
    int mask = a | b;
    n = n & mask;

}

int main()
{
    // clear last i+1 bits
    int n;
    cin>>n;
    int i;
    cin>>i;
    // -1 in bits is 32 times 1 
    clearLastBits(n, i);
    cout<<n<<endl;
    clearFirstBits(n, i);
    cout<<n<<endl;

    int j;
    cin>>j;
    clearRangeOfBits(n, i, j);
    cout<<n<<endl;


    return 0;
}