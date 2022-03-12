
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

ll sum(ll a, ll d, ll n) {
    return n * (2 * a + (n - 1) * d) / 2;
}

ll solve() {
    ll N, M;
    cin >> N >> M;
    vector<pll> C(N);
    REP(i, N) {
        cin >> C[i].first >> C[i].second;
    }

    vector<ll> B(N);
    B[0] = 0;
    FOR(i, N, 1) {
        B[i] = B[i - 1] + C[i - 1].first * C[i - 1].second;
    }


    ll ret = C[0].first;
    ll s = 0;
    REP(i, N) {

        if (C[i].first < 0) {
            ll left = 1, right = C[i].second;
            while (abs(left - right) > 2) {
                ll c0 = (left * 2 + right) / 3;
                ll c1 = (left + right * 2) / 3;
                ll s0 = sum(B[i] + C[i].first, C[i].first, c0);
                ll s1 = sum(B[i] + C[i].first, C[i].first, c1);

                if (s0 < s1) {
                    left = c0;
                } else {
                    right = c1;
                }
            }

            ll sm = std::max({sum(B[i] + C[i].first, C[i].first, right),
                              sum(B[i] + C[i].first, C[i].first, left),
                              sum(B[i] + C[i].first, C[i].first, std::min(left + 1, right))});
            ret = std::max(ret, s + sm);
        } else {
            ret = std::max(ret, s + sum(B[i] + C[i].first, C[i].first, C[i].second));
        }

        s += sum(B[i] + C[i].first, C[i].first, C[i].second);
        ret = std::max(ret, s);

    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(_, T) {
        cout << solve() << endl;
    }
    return 0;
}