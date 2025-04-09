

#include <iostream>
using namespace std;
long long n, ile;
int main()
{
    cin>>n;
    long long t[n];
    ile=n-1;
    for (int i = 0; i < n; i++)
    {
        cin>>t[i];
    }
    for (int i = n-1; i>0; i--)
    {
        if(t[ile-1]<=t[ile])
        {
            ile--;
        }
    }
    cout<<ile;

    return 0;
}
