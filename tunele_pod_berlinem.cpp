#include <bits/stdc++.h>
using namespace std;

const int MAX_BAKTERII = 10000100;

int rep[MAX_BAKTERII];
int ile;

int Find(int a) {
    if (rep[a] == a)
        return a;
    rep[a] = Find(rep[a]);
    return rep[a];
}

void Union(int a, int b) {
    int x = Find(a);
    int y = Find(b);
    if (x == y) return;
    rep[x] = y;
    ile--;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int liczba_studzienek, tunele, k, a, b;

    cin >> liczba_studzienek >> tunele >> k;
    vector<pair<int, int>> pary(tunele+1);
    ile = liczba_studzienek;

    for (int i = 1; i <= liczba_studzienek; i++) {
        rep[i] = i;
    }

    for (int i = 1; i <= tunele; i++) {
        cin >> a >> b;
        pary[i]={a, b};
    }
    
    int dzien=-1;
    if(ile==k)
    {
        dzien=tunele+1;
    }

    for (int i = tunele; i >= 1; --i) {
        Union(pary[i].first, pary[i].second);
        if (ile == k) {
           dzien=i;
        }
    }
    cout<<dzien;

    return 0;
}
