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
#include "../../lib/atcoder/all"

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

struct Data {
    ll x, y, z;
    ll index;
};

ll op(ll a, ll b) {
    return std::min(a, b);
}

ll e() {
    return INF;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<Data> D(N);
    vector<ll> v;
    REP(i, N) {
        cin >> D[i].x >> D[i].y >> D[i].z;
        v.push_back(D[i].y);
        D[i].index = i;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    atcoder::segtree<ll, op, e> seg(v.size() + 5);
    sort(D.begin(), D.end(), [](Data a, Data b) {
        if (a.x == b.x) {
            return a.z > b.z;
        }
        return a.x < b.x;
    });

    vector<bool> ans(N, false);
    REP(i, N) {
        ll y = lower_bound(v.begin(), v.end(), D[i].y) - v.begin();
        ll val = seg.prod(0, y);
        if (D[i].z > val)
            ans[D[i].index] = true;
        ll t = seg.get(y);
        if (t > D[i].z)
            seg.set(y, D[i].z);
    }

    REP(i, N) {
        if (ans[i])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}