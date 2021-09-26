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

int main() {
    string S;
    cin >> S;
    ll N = S.length();

    ll ans = 0;
    vector<ll> C(30, 0);
    for (ll i = N - 1; i >= 0; --i) {
        ll n = S[i] - 'a';
        C[n]++;
        if (i < N - 1 && S[i] == S[i + 1]) {
            REP(j, C.size()) {
                if (j == n)
                    continue;
                ans += C[j];
                C[j] = 0;
            }
            C[n] = N - i;
        }
    }
    cout << ans << endl;
    return 0;
}