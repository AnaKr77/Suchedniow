

#include <iostream>
#include <algorithm>

using namespace std;
long long n, ile;
int main()   
{
    cin>>n;
    long long t[n];
    ile=0;
    long long wynik=1;
    for (long long i = 0; i < n; i++)
    {
        cin>>t[i];
    }
    
    sort(t,t+n);
    
    for (long long i = 0; i<n; i++)
    {
        wynik*=(n-(n-t[i])-ile);
        wynik%=1000000007;
        ile++;
    }
    cout<<wynik;

    return 0;
}
