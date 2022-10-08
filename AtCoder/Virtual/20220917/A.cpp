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
    string S;
    cin >> S;
    ll left = 0, right = S.length() - 1;
    ll ans = 0;
    while (left < right) {
        if (S[left] == S[right]) {
            left++;
            right--;
            continue;
        }
        if (S[left] == 'x') {
            left++;
            ans++;
            continue;
        } else if (S[right] == 'x') {
            right--;
            ans++;
            continue;
        }
        ans = -1;
        break;
    }
    cout << ans << endl;

    return 0;
}