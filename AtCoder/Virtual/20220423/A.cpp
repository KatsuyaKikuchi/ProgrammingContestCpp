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
    ll A, B;
    ll N = 100;
    cin >> A >> B;
    vector<string> ans(N);
    REP(i, N) {
        REP(j, N / 2) {
            ans[i].push_back('.');
        }
        REP(j, N / 2) {
            ans[i].push_back('#');
        }
    }
    A--;
    B--;

    ll h = 1;
    ll w = 1;
    while (B > 0) {
        ans[h][w] = '#';
        w += 2;
        B--;
        if (w >= N / 2 - 1) {
            h += 2;
            w = 1;
        }
    }

    h = 1;
    w = 51;
    while (A > 0) {
        ans[h][w] = '.';
        A--;
        w += 2;
        if (w >= N) {
            h += 2;
            w = 51;
        }
    }

    cout << N << " " << N << endl;
    REP(i, N) {
        cout << ans[i] << endl;
    }
    return 0;
}