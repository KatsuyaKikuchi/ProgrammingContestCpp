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

struct List {
    ll prev;
    ll next;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    vector<ll> P(N);
    REP(i, N) {
        cin >> P[i];
    }
    ll t = N - K + 1;
    vector<List> ls(N + 5);
    REP(i, N) {
        ls[i + 1].prev = i;
        ls[i + 1].next = i + 2;
    }
    vector<ll> ans;
    for (ll i = N - 1; i >= K - 1; --i) {
        ans.push_back(t);
        ll index = P[i];
        if (P[i] >= t) {
            t = ls[t].prev;
        }
        ll p = ls[index].prev;
        ll n = ls[index].next;
        ls[p].next = n;
        ls[n].prev = p;
    }

    reverse(ans.begin(), ans.end());
    REP(i, ans.size()) {
        cout << ans[i] << endl;
    }
    return 0;
}