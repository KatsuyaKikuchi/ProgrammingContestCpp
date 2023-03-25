#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e19;
const long double PI = 3.1415926535897932384626433832795028841971;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    if (K == 0) {
        ll ans = 0;
        REP(i, N) {
            ans += (0 ^ A[i]);
        }
        cout << ans << endl;
        return 0;
    }

    vector<ll> B;
    while (K > 0) {
        B.push_back(K % 2);
        K /= 2;
    }
    while (B.size() < 60) {
        B.push_back(0);
    }
    reverse(B.begin(), B.end());

    vector<ll> dp(2, -INF);
    dp[0] = 0;
    ll t = (1LL << (B.size() - 1));
    REP(i, B.size()) {
        vector<ll> tmp(2, -INF);
        vector<ll> sum(2, 0);
        REP(j, N) {
            sum[1] += ((A[j] & t) ^ t);
            sum[0] += ((A[j] & t) ^ 0LL);
        }
        if (B[i] == 0) {
            tmp[0] = std::max({dp[0] + sum[0], tmp[0]});
            if (dp[1] >= 0)
                tmp[1] = std::max({dp[1] + sum[0], dp[1] + sum[1], tmp[1]});
        } else {
            tmp[0] = std::max({dp[0] + sum[1], tmp[0]});
            tmp[1] = std::max({dp[1] + sum[0], dp[1] + sum[1], dp[0] + sum[0], tmp[1]});
        }

        swap(dp, tmp);
        t /= 2;
    }

    cout << std::max(dp[0], dp[1]) << endl;
    return 0;
}