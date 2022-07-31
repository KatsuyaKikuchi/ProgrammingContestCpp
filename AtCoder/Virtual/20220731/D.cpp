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

string S;

ll solve(ll k) {
    ll N = S.length();
    ll ret = 0;
    ll count = 0;
    ll d = 0, m = 0;
    REP(i, N) {
        ll p = i - k;
        if (p >= 0) {
            if (S[p] == 'D') {
                d--;
                count -= m;
            } else if (S[p] == 'M') {
                m--;
            }
        }

        if (S[i] == 'D') {
            d++;
        } else if (S[i] == 'M') {
            count += d;
            m++;
        } else if (S[i] == 'C') {
            ret += count;
        }
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    cin >> S;
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll k;
        cin >> k;
        cout << solve(k) << endl;
    }
    return 0;
}