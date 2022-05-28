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

string toString(const vector<ll> &v) {
    string ret = "";
    for (auto n: v) {
        ret.push_back('0' + n);
    }
    return ret;
}

struct Vertex {
    vector<ll> node;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll M;
    ll N = 9;
    cin >> M;
    vector<pll> v(M);
    REP(i, M) {
        cin >> v[i].first >> v[i].second;
        v[i].first--;
        v[i].second--;
    }
    vector<ll> p(N, 8);
    REP(i, N - 1) {
        ll x;
        cin >> x;
        x--;
        p[x] = i;
    }

    vector<ll> g{0, 1, 2, 3, 4, 5, 6, 7, 8};

    vector<Vertex> V;
    std::map<string, ll> index;
    ll goal = 0;

    do {
        string s = toString(g);
        index[s] = V.size();
        V.push_back(Vertex{});

    } while (next_permutation(g.begin(), g.end()));

    for (auto t: index) {
        REP(i, M) {
            string s = t.first;
            if (s[v[i].first] == '8' || s[v[i].second] == '8') {
                swap(s[v[i].first], s[v[i].second]);
                ll nxt = index[s];
                V[nxt].node.push_back(t.second);
                V[t.second].node.push_back(nxt);
            }
        }
    }
    auto st = toString(p);
    ll start = index[st];

    vector<ll> D(V.size(), INF);
    D[start] = 0;
    queue<ll> q;
    q.push(start);
    while (!q.empty()) {
        ll t = q.front();
        ll cost = D[t] + 1;
        q.pop();
        for (auto n: V[t].node) {
            if (D[n] <= cost)
                continue;
            D[n] = cost;
            q.push(n);
        }
    }

    ll ans = D[goal];
    if (ans == INF)
        ans = -1;
    cout << ans << endl;

    return 0;
}