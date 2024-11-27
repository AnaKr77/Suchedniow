#include <iostream>
#include <cmath>
using namespace std;
long long n,a,maxi=-1, r, mini=1000000000, licznik;

int main()
{
    ios_base::sync_with_stdio(0); 
cin.tie(0);
cout.tie(0);
    cin>>n;
    long long t[n+1];
    for (int i = 1; i <=n; i++)
    {
       cin>>a;
       t[a]=i;
    }
    
    for (int i = 1; i <=n; i++)
    {
        if(maxi<t[i])
        {
            maxi=t[i];
        }
        if(mini>t[i])
        {
            mini=t[i];
        }
        r=maxi-mini+1;
        if(r==i)
        {
            licznik++;
        }

    }
    
    cout<<licznik;

    return 0;
}
