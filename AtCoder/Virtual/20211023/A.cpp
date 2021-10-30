#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>
#include <map>
#include <set>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

struct Edge {
    ll to;
    ll from;
    ll cost;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, P;
    cin >> N >> M >> P;
    vector<Edge> E(M);
    REP(i, M) {
        cin >> E[i].from >> E[i].to >> E[i].cost;
        E[i].from--;
        E[i].to--;
    }

    vector<ll> C(N, INF);
    C[0] = 0;
    REP(_, 2 * N + 5) {
        bool update = false;
        REP(i, E.size()) {
            ll a = E[i].from;
            ll b = E[i].to;
            ll c = P - E[i].cost + C[a];
            if (c < C[b]) {
                update = true;
                C[b] = c;
            }
        }
        if (!update)
            break;
    }
    vector<bool> can(N, false);

    queue<ll> q;
    q.push(0);
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        if (can[t])
            continue;
        can[t] = true;
        for (auto &e: E) {
            if (e.from != t)
                continue;
            if (can[e.to])
                continue;
            q.push(e.to);
        }
    }
    REP(i, E.size()) {
        ll a = E[i].from;
        ll b = E[i].to;
        ll c = P - E[i].cost + C[a];
        if (c < C[b] && can[b]) {
            C[b] = c;
            q.push(b);
        }
    }
    vector<bool> loop(N, false);
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        if (loop[t])
            continue;
        loop[t] = true;
        for (auto &e: E) {
            if (e.from != t)
                continue;
            if (loop[e.to])
                continue;
            q.push(e.to);
        }
    }


    if (loop[N - 1])
        cout << -1 << endl;
    else
        cout << std::max(0LL, -C[N - 1]) << endl;
    return 0;
}