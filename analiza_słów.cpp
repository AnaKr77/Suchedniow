
#include <iostream>
#include <set>
using namespace std;
//int t[1000];
set <char> zbior;
string text;
int main()
{
    cin>>text;
    int d=text.size();
    for (int i = 0; i < d; i++)
    {
        //t[text[i]]++;
        zbior.insert(text[i]);
    }
    
    cout<<zbior.size()<<endl;
    
    for( auto iter = zbior.begin(); iter != zbior.end(); ++iter )
         std::cout << * iter << ' ';
    
    

    return 0;
}
