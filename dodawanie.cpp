#include <iostream>
#include <cmath>

using namespace std;
long long p, ile;
int main()
{
    cin>>p;
    for (int i = 0; i < p; i++)
    {
        long long c,s;
        cin>>c>>s;
        long long k=0;
        while(c>0)
        {
            
            ile+=(c%10)*pow(s,k);
            c/=10;
            k++;
        }
    }
    cout<<ile;


    return 0;
}
