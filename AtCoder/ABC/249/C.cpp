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

ll solve(vector<string> &S, ll K) {
    ll N = S.size();
    ll ret = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        ll count = 0;
        REP(i, N) {
            bool e = false;
            REP(j, S[i].length()) {
                if (S[i][j] == c)
                    e = true;
            }
            if (e) {
                count++;
            }
        }
        if (count == K)ret++;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    vector<string> S(N);
    REP(i, N) {
        cin >> S[i];
    }

    ll ans = 0;
    REP(bit, pow(2LL, N)) {

        vector<string> s;
        REP(i, N) {
            if ((bit >> i) & 1)
                s.push_back(S[i]);
        }
        ans = std::max(ans, solve(s, K));
    }
    cout << ans << endl;
    return 0;

}