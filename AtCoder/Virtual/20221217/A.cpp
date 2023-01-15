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

ll comb(ll n, ll r) {
    ll ret = 1;
    std::set<ll> t;
    REP(i, r) {
        t.insert(i + 1);
    }
    REP(i, r) {
        ret *= (n - i);
        vector<ll> e;
        for (auto x: t) {
            if (ret % x == 0) {
                ret /= x;
                e.push_back(x);
            }
        }
        for (auto x: e) {
            t.erase(x);
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B, K;
    cin >> A >> B >> K;
    string ans;
    REP(i, A) {
        ans.push_back('a');
    }
    REP(i, B) {
        ans.push_back('b');
    }
    ll top = 0;
    ll first = A;
    REP(i, B) {
        ll a = first - top;
        ll b = B - 1 - i;
        ll sum = 0;
        REP(j, a + 1) {
            ll t = comb(b + 1 + j - 1, j);
            if (sum + t < K) {
                sum += t;
                continue;
            }
            K -= sum;
            swap(ans[first], ans[first - j]);
            top = first - j + 1;
            first = first + 1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}