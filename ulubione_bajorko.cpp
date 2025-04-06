#include <iostream>
using namespace std;

int NWD(long a, long b)
{
	long pom;

  	while(b!=0)
	{
    	pom = b;
    	b = a%b;
    	a = pom;  
  	}
    return a;
}

int main()
{ 
    long long a,b;
	cin>>a>>b;
	
	cout<<a/NWD(a, b)*b<<endl;
	

	return 0;
}
