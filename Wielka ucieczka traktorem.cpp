#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

long long odl[1000001];
long long odln[1000001];
vector<pair<long long, long long>> v[1000001];
long long n, m, a, b, o;

void dijkstra(int start, long long dist[]) {
    for (int i = 1; i <= n; i++) {
        dist[i] = LLONG_MAX;
    }
    dist[start] = 0;

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
    q.push({0, start});

    while (!q.empty()) {
        auto [d, w] = q.top();
        q.pop();

        if (d > dist[w]) continue;

        for (auto [s, cost] : v[w]) {
            if (dist[w] + cost < dist[s]) {
                dist[s] = dist[w] + cost;
                q.push({dist[s], s});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> o;
        v[a].push_back({b, o});
        v[b].push_back({a, o});
    }

    dijkstra(1, odl);
    dijkstra(n, odln);

    vector<int> sciezka;
    long long ns = odl[n];

    for (int i = 1; i <= n; i++) {
        if (odl[i] != LLONG_MAX && odln[i] != LLONG_MAX && odl[i] + odln[i] == ns) {
            sciezka.push_back(i);
        }
    }

    sort(sciezka.begin(), sciezka.end());

    for (int x : sciezka) {
        cout << x << endl;
    }

    return 0;
}
