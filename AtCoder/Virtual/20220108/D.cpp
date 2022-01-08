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

ll toint(string s) {
    ll ret = 0;
    ll n = 9;
    bool dot = false;
    REP(i, s.length()) {
        if (s[i] == '.') {
            dot = true;
            continue;
        }
        if (dot)
            n--;
        ret = ret * 10LL + s[i] - '0';
    }

    while (n > 0) {
        ret *= 10LL;
        n--;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> v(N);
    REP(i, N) {
        string S;
        cin >> S;
        v[i] = toint(S);
    }
    vector<pll> A(N, pll(0, 0));
    REP(i, N) {
        ll n = v[i];
        while (n % 2 == 0) {
            n /= 2;
            A[i].first++;
        }
        while (n % 5 == 0) {
            n /= 5;
            A[i].second++;
        }
        A[i].first = std::min(20LL, A[i].first);
        A[i].second = std::min(20LL, A[i].second);
    }

    ll ans = 0;
    vector<vector<ll>> C(21, vector<ll>(21, 0));
    REP(i, N) {
        REP(a, 21) {
            REP(b, 21) {
                if (std::min(A[i].first + a, A[i].second + b) >= 18)
                    ans += C[a][b];
            }
        }
        C[A[i].first][A[i].second]++;
    }
    cout << ans << endl;
    return 0;
}