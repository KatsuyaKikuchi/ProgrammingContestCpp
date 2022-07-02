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
ll A[15][15];
ll x[8] = {1, 0, 1, 1, -1, 0, -1, -1};
ll y[8] = {0, 1, 1, -1, 0, -1, -1, 1};

ll solve2(ll s, ll t, ll d) {
    ll ret = 0;
    REP(i, N) {
        ret = ret * 10 + A[s][t];
        s += x[d];
        t += y[d];
        s = (s + N) % N;
        t = (t + N) % N;
    }
    return ret;
}

ll solve(ll s, ll t) {
    ll ret = 0;
    REP(i, 8) {
        ret = std::max(ret, solve2(s, t, i));
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    REP(i, N) {
        string s;
        cin >> s;
        REP(j, N) {
            A[i][j] = s[j] - '0';
        }
    }

    vector<ll> S;
    REP(i, N) {
        REP(j, N) {
            S.push_back(solve(i, j));
        }
    }
    sort(S.begin(), S.end(), greater<ll>());
    cout << S[0] << endl;


    return 0;
}