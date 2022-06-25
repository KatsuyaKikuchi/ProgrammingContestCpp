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

bool check(const string &S, ll K, ll len) {
    ll N = S.length();
    if (N % len != 0)
        return false;
    ll sum = 0;
    REP(i, len) {
        vector<ll> count(30, 0);
        for (ll j = i; j < N; j += len) {
            count[S[j] - 'a']++;
        }
        ll mx = 0;
        REP(j, 30) {
            mx = std::max(mx, count[j]);
        }
        sum += (N / len) - mx;
    }
    return sum <= K;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    REP(i, N) {
        if (check(S, K, i + 1)) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}