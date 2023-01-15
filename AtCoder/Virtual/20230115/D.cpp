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

ll solve(ll x, vector<ll> &A) {
    ll ret = INF;
    ll index = lower_bound(A.begin(), A.end(), x) - A.begin();
    if (index > 0) {
        ret = std::min(ret, abs(x - A[index - 1]));
    }
    if (index < A.size()) {
        ret = std::min(ret, abs(x - A[index]));
    }
    return ret;
}

ll solve(ll x, vector<ll> &S, vector<ll> &T) {
    ll ret = INF;
    {
        ll index = lower_bound(S.begin(), S.end(), x) - S.begin();
        if (index > 0) {
            ll p = S[index - 1];
            ret = std::min(ret, abs(x - S[index - 1]) + solve(p, T));
        }
        if (index < S.size()) {
            ll p = S[index];
            ret = std::min(ret, abs(x - S[index]) + solve(p, T));
        }
    }
    {
        ll index = lower_bound(T.begin(), T.end(), x) - T.begin();
        if (index > 0) {
            ll p = T[index - 1];
            ret = std::min(ret, abs(x - T[index - 1]) + solve(p, S));
        }
        if (index < T.size()) {
            ll p = T[index];
            ret = std::min(ret, abs(x - T[index]) + solve(p, S));
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> S(A), T(B);
    REP(i, A) {
        cin >> S[i];
    }
    REP(i, B) {
        cin >> T[i];
    }
    REP(_, Q) {
        ll x;
        cin >> x;
        cout << solve(x, S, T) << endl;
    }
    return 0;
}