#include <iostream>
#include <vector>
#include <queue>
#include <functional>


using namespace std;

const int MOD = 1000000009; 

vector <long long>v[1000001];
long long n,m,a,b,A,B;

vector<long long>dijkstra(int start)
{
    vector<long long> dp(n + 1, 0);
    vector<int> bw(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        for (int x : v[i]) {
            bw[x]++;
        }
    }
    
    dp[start]=1;
queue<long long> q;
    for (int i = 1; i <=n; i++)
    {
        if (bw[i] == 0) {
            q.push(i);
        }
    }
 
    while(!q.empty())
    {
        long long w=q.front();
        q.pop();
        
        for (int x : v[w]) {
            dp[x] = (dp[x] + dp[w]) % MOD;
            
            bw[x]--;
            if (bw[x] == 0) {
                q.push(x);
            }
        }
    }
    return dp;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>A>>B;
    for (int i = 1; i <= m; i++)
    {
       cin >> a >> b; 
       v[a].push_back(b);
    }
    
    vector<long long> dp=dijkstra(A);

    cout << dp[B] << endl;
    return 0;
}
