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
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<Vertex> to(N), from(N);
    REP(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        to[a].node.push_back(pll(b, c));
        from[b].node.push_back(pll(a, c));
    }

    vector<ll> T(N, INF), F(N, INF);
    {
        priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
        q.push(pll(0, 0));
        T[0] = 0;
        while (!q.empty()) {
            pll t = q.top();
            q.pop();
            if (T[t.first] < t.second)
                continue;
            for (auto n: to[t.first].node) {
                ll cost = t.second + n.second;
                if (T[n.first] <= cost)
                    continue;
                T[n.first] = cost;
                q.push(pll(n.first, cost));
            }
        }
    }
    {
        priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
        q.push(pll(N - 1, 0));
        F[N - 1] = 0;
        while (!q.empty()) {
            pll t = q.top();
            q.pop();
            if (F[t.first] < t.second)
                continue;
            for (auto n: from[t.first].node) {
                ll cost = t.second + n.second;
                if (F[n.first] <= cost)
                    continue;
                F[n.first] = cost;
                q.push(pll(n.first, cost));
            }
        }
    }

    REP(i, N) {
        ll s = T[i] + F[i];
        if (s >= INF)
            s = -1;
        cout << s << endl;
    }
    return 0;
}