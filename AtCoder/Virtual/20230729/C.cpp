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
    ll count = 1;
    bool center = false;
};

vector<ll> ans;

bool dfs(vector<Vertex> &V, ll index = 0, ll parent = -1) {
    bool ret = false;
    for (auto n: V[index].node) {
        if (n == parent)
            continue;
        if (dfs(V, n, index)) {
            ans.push_back(V[n].count - 1);
            continue;
        }
        V[index].count += V[n].count;
        if (V[n].count != 1) {
            ret = true;
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<Vertex> V(N);
    REP(i, N - 1) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        V[x].node.push_back(y);
        V[y].node.push_back(x);
    }

    dfs(V);
    ans.push_back(V[0].count - 1);
    sort(ans.begin(), ans.end());
    REP(i, ans.size()) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}