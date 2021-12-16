#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>
#include <map>
#include <set>

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
    vector<ll> A(K);
    vector<bool> X(N + 1, false);
    REP(i, K) {
        ll a;
        cin >> a;
        A[i] = a;
        X[a] = true;
    }

    X[A[K - 1]] = false;

    vector<ll> ans;
    ll x = 1;
    REP(i, K - 1) {
        ans.push_back(A[i]);
        while (x <= N && X[x]) {
            x++;
        }
        if (A[i] > x) {
            X[x] = true;
            ans.push_back(x);
            x++;
        }
    }

    ll n = N;
    while (n >= 1) {
        if (!X[n])
            ans.push_back(n);
        n--;
    }

    REP(i, ans.size()) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}