#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll MAX = 100000;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

std::map<ll, ll> mp;
std::map<ll, ll> sum;

void init() {
    std::map<ll, ll> tmp;
    mp[1] = 1;
    mp.clear();
    tmp[1] = 1;
    {
        ll s = 0;
        for (ll x = 1; x <= MAX; ++x) {
            ll n = x * x;
            auto it = tmp.find(x);
            if (it != tmp.end()) {
                s += it->second;
                mp[x] = s;
                tmp.erase(it);
            }
            if (n != x)
                tmp[n] = s;
        }
        for (auto it: tmp) {
            s += it.second;
            mp[it.first] = s;
        }
    }
    {
        ll s = 0;
        ll count = 3;
        for (auto &it: mp) {
            sum[it.first] = s;
            s += count * it.second;
            count += 2;
        }
    }
}

ll solve(ll X) {
    ll m = sqrt(X);
    if ((m + 1) * (m + 1) <= X)
        m++;
    if (m * m > X)
        m--;
    auto it0 = sum.lower_bound(m + 1);
    auto it1 = mp.lower_bound(m + 1);
    it0--;
    it1--;
    ll num = m - it0->first + 1;
    return it0->second + it1->second * num;

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    init();

    ll T;
    cin >> T;
    REP(_, T) {
        ll X;
        cin >> X;
        cout << solve(X) << endl;
    }
    return 0;
}