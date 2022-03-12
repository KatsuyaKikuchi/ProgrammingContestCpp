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
    vector<pll> node;
    vector<pll> invNode;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<pll> E(M);
    vector<Vertex> V(N);
    REP(i, M) {
        cin >> E[i].first >> E[i].second;
        E[i].first--;
        E[i].second--;
        V[E[i].first].node.emplace_back(E[i].second, i);
        V[E[i].second].invNode.emplace_back(E[i].first, i);
    }

    vector<ll> D(N, INF);
    vector<ll> invD(N, INF);
    {
        queue<pll> q;
        q.push(pll(0, 0));
        D[0] = 0;
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            ll cost = D[t.first] + 1;
            for (auto nxt: V[t.first].node) {
                ll n = nxt.first;
                if (D[n] <= cost)
                    continue;
                D[n] = cost;
                q.push(pll(n, cost));
            }
        }
    }
    {
        queue<pll> q;
        q.push(pll(N - 1, 0));
        invD[N - 1] = 0;
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            ll cost = invD[t.first] + 1;
            for (auto nxt: V[t.first].invNode) {
                ll n = nxt.first;
                if (invD[n] <= cost)
                    continue;
                invD[n] = cost;
                q.push(pll(n, cost));
            }
        }
    }

    vector<ll> ans(M, D[N - 1]);
    if (D[N - 1] != INF) {
        ll e = N - 1;
        while (e != 0) {
            for (auto n: V[e].invNode) {
                if (D[n.first] + 1 != D[e])
                    continue;

                queue<ll> q;
                q.push(0);
                vector<ll> d(N, INF);
                d[0] = 0;
                while (!q.empty()) {
                    ll t = q.front();
                    q.pop();
                    ll cost = d[t] + 1;
                    for (auto nxt: V[t].node) {
                        if (nxt.second == n.second)
                            continue;
                        if (d[nxt.first] <= cost)
                            continue;
                        d[nxt.first] = cost;
                        q.push(nxt.first);
                    }
                }
                ans[n.second] = d[N - 1];

                e = n.first;
            }
        }
    }

    REP(i, ans.size()) {
        if (ans[i] == INF)
            cout << -1 << endl;
        else
            cout << ans[i] << endl;
    }
    return 0;
}