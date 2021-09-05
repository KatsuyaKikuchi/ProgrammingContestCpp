#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)

const ll INF = (ll) 1e15;

ll gcd(ll a, ll b) {
    if (a < b)return gcd(b, a);
    ll c = a % b;
    if (c == 0)return b;
    return gcd(b, c);
}

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    vector<ll> B(N + 1, 1);
    B[N - 1] = A[N - 1];
    for (ll i = N - 2; i >= 0; --i) {
        B[i] = gcd(B[i + 1], A[i]);
    }
    ll ans = B[1];
    ll n = A[0];
    FOR(i, N - 1, 1) {
        ans = std::max(gcd(n, B[i + 1]), ans);
        n = gcd(A[i], n);
    }
    cout << std::max(ans, n) << endl;
    return 0;
}