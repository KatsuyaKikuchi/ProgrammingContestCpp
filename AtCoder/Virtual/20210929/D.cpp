#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Vertex {
    ll cnt = 0;
    vector<ll> node;
};

int main() {
    ll N;
    cin >> N;
    ll M = N * N;
    vector<Vertex> V(M);
    REP(i, N) {
        vector<ll> v;
        REP(j, N - 1) {
            ll a;
            cin >> a;
            a--;
            ll n = std::min(a, i) * N + std::max(a, i);
            v.push_back(n);
        }
        FOR(j, v.size(), 1) {
            V[v[j - 1]].node.push_back(v[j]);
            V[v[j]].cnt++;
        }
    }

    vector<ll> C(M, INF);
    queue<ll> q;
    REP(i, M) {
        if (V[i].cnt == 0) {
            q.push(i);
            C[i] = 1;
        }
    }
    while (!q.empty()) {
        ll t = q.front();
        q.pop();
        for (auto n: V[t].node) {
            V[n].cnt--;
            C[n] = C[t] + 1;
            if (V[n].cnt == 0)
                q.push(n);
        }
    }

    ll ans = 0;
    REP(i, M) {
        ans = std::max(ans, C[i]);
    }
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}