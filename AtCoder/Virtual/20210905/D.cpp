#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)

const ll INF = (ll) 2e18;
ll K, N, M;
vector<ll> A;

bool check(ll x, bool out = false) {
    vector<ll> B(K, 0);
    vector<ll> D(K, 0);
    ll sum = 0;
    REP(i, K) {
        ll mn = std::max(0LL, M * A[i] - x);
        B[i] = (mn + N - 1) / N;
        ll mx = std::min(INF, M * A[i] + x);
        D[i] = std::min(M, std::max(0LL, mx / N - B[i]));
        sum += B[i];
    }
    if (sum > M)
        return false;

    REP(i, K) {
        ll s = std::min(M - sum, D[i]);
        B[i] += s;
        sum += s;
    }

    if (sum < M)
        return false;

    if (out) {
        REP(i, K) {
            cout << B[i] << " ";
        }
        cout << endl;
    }
    return true;
}

int main() {
    cin >> K >> N >> M;
    A.resize(K);
    REP(i, K) {
        cin >> A[i];
    }

    ll ok = INF, ng = 0;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (check(mid))ok = mid;
        else ng = mid;
    }

    check(ok, true);
    return 0;
}