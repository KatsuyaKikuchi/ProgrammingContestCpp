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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, K;
    cin >> N >> M >> K;
    vector<Vertex> V(N);
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    vector<ll> H(N, -1);
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.first < b.first; });
    REP(i, K) {
        ll p, h;
        cin >> p >> h;
        p--;
        q.push(pll(h, p));
        H[p] = h;
    }

    while (!q.empty()) {
        pll t = q.top();
        q.pop();
        if (t.first < H[t.second])
            continue;
        ll count = t.first - 1;
        for (auto n: V[t.second].node) {
            if (H[n] >= count)
                continue;
            H[n] = count;
            q.push(pll(count, n));
        }
    }
    vector<ll> ans;
    REP(i, N) {
        if (H[i] >= 0)
            ans.push_back(i + 1);
    }
    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}