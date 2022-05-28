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
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    ll ans = 0;
    vector<ll> S(200005, 0);
    std::map<ll, ll> count;

    vector<ll> IL(200005, INF);
    vector<ll> I(200005, 0);
    vector<ll> C(200005, 0);
    vector<ll> J(200005, 0);

    ll sum = 0;

    REP(i, N) {
        if (i >= 2) {
            ll s = (i - 1) * i / 2 - sum;
            ans += s;
            ll t = std::max(0LL, i - 1 - IL[A[i]]) * C[A[i]];
            ans -= (I[A[i]] + t);
            ans -= J[A[i]];
            ans += S[A[i]] * 2;
        }
        //cout << ans << " ";

        J[A[i]] += i;

        S[A[i]] += count[A[i]];
        sum += count[A[i]];
        count[A[i]]++;
        if (i > 0) {
            I[A[i - 1]] += std::max(0LL, i - 1 - IL[A[i - 1]]) * C[A[i - 1]];
            C[A[i - 1]]++;
            IL[A[i - 1]] = i - 1;
        }
    }
    // cout << endl;

    cout << ans << endl;
    return 0;
}