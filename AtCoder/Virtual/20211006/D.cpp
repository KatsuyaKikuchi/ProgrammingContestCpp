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
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll left = 0;
    ll ans = 1;
    REP(i, N) {
        ans = (ans * (i + 1)) % MOD;
    }
    REP(i, S.length()) {
        if (S[i] == 'B') {
            if (left % 2 == 0)
                left++;
            else {
                ans *= left;
                left--;
            }
        } else {
            if (left % 2 == 1)
                left++;
            else {
                ans *= left;
                left--;
            }
        }
        ans %= MOD;
    }
    if (left != 0)
        ans = 0;
    cout << ans << endl;
    return 0;
}