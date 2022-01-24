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

ll N;
vector<ll> A;

bool checkAve(double x) {
    vector<double> dp(N + 5, 0);
    dp[1] = A[0] - x;
    FOR(i, N, 1) {
        dp[i + 1] = std::max(dp[i], dp[i - 1]) + A[i] - x;
    }
    return max(dp[N], dp[N - 1]) >= 0;
}

bool checkMid(ll x) {
    ll upCount = 0;
    vector<bool> used(N, false);
    REP(i, N) {
        if (A[i] >= x) {
            used[i] = true;
            upCount++;
        }
    }
    ll lowCount = 0;
    FOR(i, N, 1) {
        if (used[i] || used[i - 1])
            continue;
        lowCount++;
        used[i] = true;
    }
    return upCount > lowCount;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    A.resize(N);
    REP(i, N) {
        cin >> A[i];
    }

    double ave = 0;
    {
        double ng = INF;
        REP(_, 200) {
            double mid = (ave + ng) * 0.5;
            if (checkAve(mid))
                ave = mid;
            else
                ng = mid;
        }
    }
    ll midd = 0;
    {
        ll ng = INF;
        while (abs(ng - midd) > 1) {
            ll mid = (midd + ng) / 2;
            if (checkMid(mid))
                midd = mid;
            else
                ng = mid;
        }
    }

    cout << OF64 << ave << endl;
    cout << midd << endl;
    return 0;
}