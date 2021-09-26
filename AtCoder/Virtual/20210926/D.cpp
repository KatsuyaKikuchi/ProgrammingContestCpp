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

const ll MOD = 998244353;
const ll INF = (ll) 1e15;

struct Vertex {
    vector<ll> node;
};

int main() {
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
    REP(i, N) {
        V[i].node.push_back(i);
    }
    ll s = 1;
    vector<ll> dp(N, 0);
    dp[0] = 1;
    REP(i, K) {
        vector<ll> t(N, s);
        ll nxt = 0;
        REP(j, N) {
            ll x = 0;
            for (auto &n: V[j].node) {
                x += dp[n];
            }
            t[j] = (t[j] + MOD - (x % MOD)) % MOD;
            nxt += t[j];
        }
        s = nxt % MOD;
        swap(dp, t);
    }

    cout << dp[0] << endl;
    return 0;
}