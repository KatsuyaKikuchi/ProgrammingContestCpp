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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N), B(K);
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, K) {
        cin >> B[i];
        B[i]--;
    }

    vector<pll> v(1, pll(-1, -1));
    REP(i, N) {
        if (v.back().second > A[i])
            continue;
        if (v.back().second < A[i]) {
            v.clear();
        }
        v.emplace_back(i, A[i]);
    }

    bool e = false;
    REP(i, v.size()) {
        REP(j, K) {
            if (v[i].first == B[j]) {
                e = true;
                break;
            }
        }
    }

    if (e) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}