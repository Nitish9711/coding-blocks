#include <iostream>
using namespace std;
class test
{
private:
    int x;

    static const int c = 300;
    static const char b = "d";
public:
    static int i;
    test():
    {
        
        cout << " \n default called ";
    }
    test(int xl)
    {
        cout << "\n parameterized called \n";
        x = xl;
    }
    test(const test &t2, int i)
    {
        cout << " \n \n copy constructor for " << i << "\n";
        x = t2.x;
    }
};
// int test::i = 0;
int main()
{
    test a;
    // cout << a.c << endl;
    // cout << a.i << endl;
    return 0;
}
