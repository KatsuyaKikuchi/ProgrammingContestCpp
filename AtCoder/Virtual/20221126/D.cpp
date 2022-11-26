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

bool check(ll a, ll b, ll c, pll t) {
    return a * t.first + b * t.second + c == 0;
}

void solve(pll t0, pll t1, ll &a, ll &b, ll &c) {
    if (t0.first == t1.first) {
        a = 1;
        b = 0;
        c = -t0.first;
        return;
    }
    a = t0.second - t1.second;
    b = -(t0.first - t1.first);
    c = -t0.first * a - b * t0.second;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    vector<pll> A(N);
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    if (K == 1) {
        cout << "Infinity" << endl;
        return 0;
    }

    ll ans = 0;
    REP(i, N) {
        FOR(j, N, i + 1) {
            ll a, b, c;
            solve(A[i], A[j], a, b, c);
            ll count = 2;
            REP(k, N) {
                if (k == i || k == j)
                    continue;
                if (check(a, b, c, A[k])) {
                    if (k < j) {
                        count = -1;
                        break;
                    }
                    count++;
                }
            }
            if (count >= K)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}