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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, X;
    cin >> N >> X;
    vector<pll> A(N);
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }

    vector<bool> dp(X + 10, false);
    dp[0] = true;
    REP(i, N) {
        vector<bool> tmp(X + 10, false);
        for (ll x = X; x >= 0; --x) {
            if (dp[x]) {
                ll n0 = x + A[i].first;
                ll n1 = x + A[i].second;

                if (n0 <= X)
                    tmp[n0] = true;
                if (n1 <= X)
                    tmp[n1] = true;
            }
        }
        swap(dp, tmp);
    }
    if (dp[X])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}