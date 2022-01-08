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

ll test(vector<ll> v) {

    while (v.size() > 1) {
        vector<ll> tmp;
        FOR(i, v.size() - 1, 1) {
            vector<ll> x = {v[i - 1], v[i], v[i + 1]};
            sort(x.begin(), x.end());
            tmp.push_back(x[1]);
        }
        swap(tmp, v);
    }

    return v[0];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, x;
    cin >> N >> x;

#if false
    vector<ll> v(2LL * N - 1);
    REP(i, v.size()) {
        v[i] = i + 1;
    }
    do {
        cout << test(v) << endl;
    } while (next_permutation(v.begin(), v.end()));
#else
    ll n = 2 * N - 1;
    if (x == n || x == 1) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    vector<ll> t(n, 0);
    ll m = n / 2;
    t[m] = x;
    vector<bool> U(n, false);
    U[x - 1] = true;
    ll a = x - 1, b = x + 1;
    for (ll i = 1; i <= m; ++i) {
        if (i % 2 == 0)
            swap(a, b);
        if (a > 0 && a <= n) {
            t[m - i] = a;
            U[a - 1] = true;
        }
        if (b <= n && b > 0) {
            t[m + i] = b;
            U[b - 1] = true;
        }
        if (i % 2 == 0)
            swap(a, b);
        a--;
        b++;
    }

    ll index = 0;
    REP(i, t.size()) {
        if (t[i] > 0)
            continue;
        while (U[index])
            index++;
        t[i] = index + 1;
        U[index] = true;
    }

    REP(i, t.size()) {
        cout << t[i] << endl;
    }

#endif
    return 0;
}