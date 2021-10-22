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
    vector<ll> to;
    vector<ll> from;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<Vertex> V(N);
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].to.push_back(b);
        V[b].from.push_back(a);
    }

    vector<ll> C(N, INF);
    C[N - 1] = 0;
    queue<ll> q;
    q.push(N - 1);
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (auto &n: V[t].from) {
            ll c = C[t] + 1;
            if (C[n] <= c)
                continue;
            C[n] = c;
            q.push(n);
        }
    }

    if (C[0] == INF) {
        cout << -1 << endl;
        return 0;
    }
    vector<ll> ans;
    ans.push_back(1);
    ll s = 0;
    while (s != N - 1) {
        ll nxt = INF;
        for (auto &n: V[s].to) {
            if (C[n] == C[s] - 1)
                nxt = std::min(nxt, n);
        }
        ans.push_back(nxt + 1);
        s = nxt;
    }

    REP(i, ans.size()) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}