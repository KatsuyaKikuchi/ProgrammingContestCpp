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

vector<vector<ll>> V;

void dfs(vector<ll> &v) {
    if (v.size() > 0) {
        vector<ll> t(v);
        V.push_back(t);
    }
    if (v.size() == 11)
        return;

    ll s = v.size() == 0 ? 0 : v.back();
    for (ll n = s; n <= 9; ++n) {
        v.push_back(n);
        dfs(v);
        v.pop_back();
    }
}

ll N, B;

bool check(vector<ll> &v) {
    ll m = 1;
    REP(i, v.size()) {
        m *= v[i];
    }

    ll n = B + m;
    if (n > N)
        return false;
    vector<ll> cnt(10, 0);
    while (n > 0) {
        cnt[n % 10]++;
        n /= 10;
    }

    REP(i, v.size()) {
        cnt[v[i]]--;
    }

    REP(i, cnt.size()) {
        if (cnt[i] != 0)
            return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> B;

    vector<ll> v;
    dfs(v);
    ll ans = 0;
    for (auto &v: V) {
        if (check(v))
            ans++;
    }
    cout << ans << endl;
    return 0;
}