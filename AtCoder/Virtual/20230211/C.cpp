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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    string s = S, t = T;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s != t) {
        cout << -1 << endl;
        return 0;
    }

    ll index = N - 1;
    for (ll i = N - 1; i >= 0; --i) {
        while (index > 0) {
            if (T[index] == S[i])
                break;
            index--;
        }

        if (index < 0) {
            cout << i + 1 << endl;
            return 0;
        }
        index--;
    }
    cout << 0 << endl;
    return 0;
}