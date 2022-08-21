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
    ll N, X;
    cin >> N >> X;
    vector<ll> ans;

    if (N % 2 == 1 && (N + 1) / 2 == X) {
        ll p = 1;
        while (ans.size() < N) {
            ans.push_back(X);
            X += p;
            ll sign = p / abs(p);
            p = -sign * (abs(p) + 1);
        }
    } else if (N % 2 == 0 && (N / 2 == X || N / 2 == X - 1)) {
        ll p = -1;
        if (N / 2 == X) {
            p = 1;
        }
        while (ans.size() < N) {
            ans.push_back(X);
            X += p;
            ll sign = p / abs(p);
            p = -sign * (abs(p) + 1);
        }
    } else {
        ans.push_back(X);
        vector<ll> v;
        ll p = 1;
        ll index = N / 2 - 1;
        REP(i, N) {
            if (i == X - 1)
                continue;
            v.push_back(i + 1);
        }
        while (ans.size() < N) {
            ans.push_back(v[index]);
            index += p;
            ll sign = p / abs(p);
            p = -sign * (abs(p) + 1);
        }
    }

    REP(i, N) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}