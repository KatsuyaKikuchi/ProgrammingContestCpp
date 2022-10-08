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
    ll count = 0;
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
        V[a].node.push_back(b);
        V[b].count++;
    }

    priority_queue<ll, vector<ll>, greater<ll>> q;
    vector<ll> ans;
    REP(i, N) {
        if (V[i].count == 0)
            q.push(i);
    }
    while (!q.empty()) {
        ll t = q.top();
        q.pop();
        ans.push_back(t);
        for (auto n: V[t].node) {
            V[n].count--;
            if (V[n].count == 0)
                q.push(n);
        }
    }

    if (ans.size() < N) {
        cout << -1 << endl;
    } else {
        REP(i, N) {
            cout << ans[i] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}