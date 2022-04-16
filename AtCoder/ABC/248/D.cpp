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

struct Query {
    ll L, R, X;

};

ll solve(ll l, ll r, const vector<ll> &v) {
    ll left = v.size(), ng = -1;
    while (abs(left - ng) > 1) {
        ll mid = (left + ng) / 2;
        if (v[mid] >= l)
            left = mid;
        else ng = mid;
    }
    ll right = -1;
    ng = v.size();
    while (abs(right - ng) > 1) {
        ll mid = (right + ng) / 2;
        if (v[mid] <= r)
            right = mid;
        else ng = mid;
    }

    return std::max(0LL, right + 1 - left);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    ll M;
    cin >> M;
    vector<Query> Q(M);
    vector<vector<ll> > S(N + 5);
    REP(i, N) {
        S[A[i]].push_back(i);
    }
    REP(i, M) {
        ll l, r, x;
        cin >> l >> r >> x;
        cout << solve(l - 1, r - 1, S[x]) << endl;
    }

    return 0;
}