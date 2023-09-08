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

ll convert(string s) {
    ll ret = 0;
    REP(i, s.length()) {
        ret *= 2;
        if (s[i] == '0')
            ret += 0;
        else
            ret += 1;
    }
    return ret;
}

bool check(ll a, ll b) {
    ll t = a ^ b;
    ll count = 0;
    while (t > 0) {
        count += (t % 2);
        t /= 2;
    }
    return count % 2 == 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    REP(i, N) {
        string s;
        cin >> s;
        A[i] = convert(s);
    }
    sort(A.begin(), A.end());
    ll ans = N * (N - 1) / 2;
    vector<ll> D(N, 0);
    REP(i, N) {
        for (ll j = i - 1; j >= 0; --j) {
            if (check(A[i], A[j])) {
                D[i] += D[j] + 1;
                break;
            }
        }
        ans -= D[i];
    }
    cout << ans << endl;
    return 0;
}