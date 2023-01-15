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

bool solve() {
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    ll s = N, e = -1;
    REP(i, N) {
        if (S[i] == '1') {
            s = i;
            break;
        }
    }
    REP(i, N) {
        if (S[N - 1 - i] == '1') {
            e = N - 1 - i;
            break;
        }
    }
    if (e - s + 1 > K)
        return false;

    ll t = std::max(0LL, e + 1 - K);
    ll count = 0;
    REP(i, K) {
        if (S[t + i] != '0')
            count++;
    }

    ll ret = 0;
    if (count == K)
        ret++;
    for (ll i = t + 1; i <= std::min(N - K, s); ++i) {
        if (S[i - 1] != '0')
            count--;

        if (S[i + K - 1] != '0')
            count++;

        if (count == K)
            ret++;
    }
    return ret == 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(_, T) {
        if (solve())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}