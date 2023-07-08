#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = ((ll) 1e18) * 2LL;
const long double PI = 3.1415926535897932384626433832795028841971;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N;
    cin >> N;
    reverse(S.begin(), S.end());
    string T = "";
    while (N > 0) {
        ll n = N % 2;
        N /= 2;
        T.push_back('0' + n);
    }
    while (T.size() < S.size()) {
        T.push_back('0');
    }
    while (S.size() < T.size()) {
        S.push_back('0');
    }
    reverse(S.begin(), S.end());
    reverse(T.begin(), T.end());
    ll M = S.size();

    vector<vector<ll>> dp(S.size() + 5, vector<ll>(2, -INF));
    dp[0][0] = 0;
    REP(i, M) {
        ll n = M - (i + 1);
        if (S[i] == '0') {
            if (T[i] == '0') {
                dp[i + 1][0] = std::max({dp[i + 1][0], dp[i][0]});
                dp[i + 1][1] = std::max({dp[i + 1][1], dp[i][1]});
            } else {
                dp[i + 1][1] = std::max({dp[i + 1][1], dp[i][1], dp[i][0]});
            }
        } else if (S[i] == '1') {
            if (T[i] == '0') {
                dp[i + 1][1] = std::max({dp[i + 1][1], dp[i][1] + (1LL << n)});
            } else {
                dp[i + 1][1] = std::max({dp[i + 1][1], dp[i][1] + (1LL << n)});
                dp[i + 1][0] = std::max({dp[i + 1][0], dp[i][0] + (1LL << n)});
            }
        } else {
            if (T[i] == '0') {
                dp[i + 1][0] = std::max({dp[i + 1][0], dp[i][0]});
                dp[i + 1][1] = std::max({dp[i + 1][1], dp[i][1] + (1LL << n)});
            } else {
                dp[i + 1][0] = std::max({dp[i + 1][0], dp[i][0] + (1LL << n)});
                dp[i + 1][1] = std::max({dp[i + 1][1], dp[i][1] + (1LL << n), dp[i][0]});
            }
        }
    }

    cout << std::max({-1LL, dp[S.size()][0], dp[S.size()][1]}) << endl;
    return 0;
}