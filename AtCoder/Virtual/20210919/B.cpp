#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
vector<ll> A;

int main() {
    ll N, K;
    cin >> N >> K;
    A.resize(N + 1);
    REP(i, N) {
        cin >> A[i];
    }
    A[N] = 0;
    sort(A.begin(), A.end(), greater<ll>());
    ll sum = 0;
    REP(i, N) {
        ll n = i + 1;
        ll k = std::min(K, (A[i] - A[i + 1]) * n);
        ll m = k / n;
        sum += A[i] * m * n - (m * (m - 1) / 2) * n + std::max(0LL, (A[i] - m)) * (k - n * m);
        K -= k;
    }

    cout << sum << endl;
    return 0;
}