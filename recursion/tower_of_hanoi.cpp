#include<iostream>

using namespace std;



    int i =0;
void move(int n, char src,char helper, char dest)
{
    if(n==0)
        return;
    // i++;
    // move n-1 disk from src to helper

    move(n-1, src,dest , helper);
    
    cout<<"Moving ring "<<n<<" from "<< src << " to "<<dest<<endl;
    move(n-1, helper, src, dest);
    
}

int main()
{
    int n;
    cin>>n;

    move(n, 'A', 'B','C');
    
    cout<<i<<endl;
    return 0;
}