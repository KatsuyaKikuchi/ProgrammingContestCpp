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

ll N;
ll D[3005][10];

bool check(ll m) {
    ll p = pow(2LL, 5);
    vector<bool> x(p, false);
    REP(i, N) {
        ll bit = 0;
        REP(j, 5) {
            if (D[i][j] >= m)
                bit |= (1 << j);
        }
        x[bit] = true;
    }

    REP(a, p) {
        REP(b, p) {
            REP(c, p) {
                if ((a | b | c) != p - 1)
                    continue;
                if (x[a] && x[b] && x[c])
                    return true;
            }
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    vector<ll> v;
    REP(i, N) {
        REP(j, 5) {
            cin >> D[i][j];
        }
    }

    ll ok = 0, ng = INF;
    while (abs(ng - ok) > 1) {
        ll mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }
    cout << ok << endl;


    return 0;
}