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
ll N, A, B;

bool check(ll x, ll y) {
    ll k = x - A;
    if (max(1 - A, 1 - B) <= k && k <= min(N - A, N - B)) {
        if (B + k == y) {
            return true;
        }
    }
    if (max(1 - A, B - N) <= k && k <= min(N - A, B - 1)) {
        if (B - k == y) {
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> A >> B;
    ll P, Q, R, S;
    cin >> P >> Q >> R >> S;

    vector<string> T;
    for (ll i = P; i <= Q; ++i) {
        string s;
        for (ll j = R; j <= S; ++j) {
            if (check(i, j))
                s.push_back('#');
            else
                s.push_back('.');
        }
        T.push_back(s);
    }

    REP(i, T.size()) {
        cout << T[i] << endl;
    }
    return 0;
}