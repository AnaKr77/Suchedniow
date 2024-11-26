
#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;
long long droga(long long n)
{
    
    if(n==0)
    {
        return 1;
    }
    long long w;
    if(n==1)
    {
        return 2;
    }
    w=droga(n-1);
    return (((w*w)%MOD)*(w+1))%MOD;
    
}
long long a;
int main()
{
    cin>>a;
    cout<<droga(a)%MOD;

    return 0;
}
