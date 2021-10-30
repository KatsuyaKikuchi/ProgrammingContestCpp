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

struct Vertex {
    vector<ll> node;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll M;
    cin >> M;
    vector<pll> edg(M);
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        edg[i] = pll(a, b);
    }
    vector<ll> P(9, -1);
    REP(i, 8) {
        ll p;
        cin >> p;
        p--;
        P[p] = i;
    }
    REP(i, P.size()) {
        if (P[i] < 0)
            P[i] = 8;
    }

    vector<ll> tmp = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<vector<ll>> v;
    std::map<string, ll> mp;
    ll count = 0;
    do {
        vector<ll> t(9);
        string s = "";
        REP(i, tmp.size()) {
            t[i] = tmp[i];
            s.push_back(tmp[i]);
        }
        v.push_back(t);
        mp[s] = count;
        count++;
    } while (next_permutation(tmp.begin(), tmp.end()));

    vector<Vertex> V(v.size());
    REP(i, v.size()) {
        string s = "";
        ll ep = -1;
        REP(j, v[i].size()) {
            s.push_back(v[i][j]);
            if (8 == v[i][j])
                ep = j;
        }
        ll index = mp[s];

        REP(j, M) {
            if (edg[j].first == ep || edg[j].second == ep) {
                swap(s[edg[j].first], s[edg[j].second]);
                ll next = mp[s];
                V[index].node.push_back(next);
                V[next].node.push_back(index);
                swap(s[edg[j].first], s[edg[j].second]);
            }
        }
    }

    string ss = "";
    REP(i, P.size()) {
        ss.push_back(P[i]);
    }
    vector<ll> C(V.size(), INF);
    ll st = mp[ss];
    queue<pll> q;
    q.push(pll(st, 0));
    C[st] = 0;
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (auto &nxt: V[t.first].node) {
            ll c = t.second + 1;
            if (C[nxt] <= c)
                continue;
            C[nxt] = c;
            q.push(pll(nxt, c));
        }
    }

    string ls = "";
    REP(i, 9) {
        ls.push_back(i);
    }
    ll last = mp[ls];

    ll ans = C[last];
    if (ans == INF)
        ans = -1;
    cout << ans << endl;

    return 0;
}