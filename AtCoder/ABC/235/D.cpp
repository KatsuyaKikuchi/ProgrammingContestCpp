#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

struct Vertex {
    vector<ll> node;
};

ll nxt(ll n) {
    ll m = n % 10;
    n /= 10;
    ll x = 1;
    while (x <= n) {
        x *= 10;
    }

    return m * x + n;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, N;
    cin >> A >> N;
    ll M = 1000010;
    vector<Vertex> V(M);
    REP(i, M) {
        if (i * A < M)
            V[i].node.push_back(i * A);
        if (i % 10 != 0 && i >= 10) {
            ll n = nxt(i);
            if (n < M)
                V[i].node.push_back(n);
        }
    }

    vector<ll> D(V.size(), INF);
    D[1] = 0;
    queue<ll> q;
    q.push(1);
    while (!q.empty()) {
        ll t = q.front();
        q.pop();
        ll cost = D[t] + 1;
        for (auto n: V[t].node) {
            if (D[n] <= cost)
                continue;
            D[n] = cost;
            q.push(n);
        }
    }

    if (D[N] == INF)
        cout << -1 << endl;
    else
        cout << D[N] << endl;
    return 0;
}