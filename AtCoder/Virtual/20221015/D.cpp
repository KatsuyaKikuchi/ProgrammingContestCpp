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
    ll N, X, M;
    cin >> N >> X >> M;
    vector<ll> T(M + 1, -1);
    vector<ll> S(M + 1, 0);
    T[X] = 0;
    S[0] = X;
    ll index = 1;
    while (true) {
        X = (X * X) % M;
        if (T[X] >= 0)
            break;
        T[X] = index;
        S[index] = S[index - 1] + X;
        index++;
    }

    ll ans;
    if (index - 1 >= N - 1) {
        ans = S[N - 1];
    } else {
        ans = S[index - 1];
        N -= index;
        ll count = index - T[X];
        ll s = S[index - 1];
        if (T[X] > 0)
            s -= S[T[X] - 1];
        ans += s * (N / count);
        N %= count;
        while (N > 0) {
            ans += X;
            X = (X * X) % M;
            N--;
        }
    }
    cout << ans << endl;
    return 0;
}