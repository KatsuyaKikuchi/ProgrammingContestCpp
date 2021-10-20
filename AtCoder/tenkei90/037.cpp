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

struct Data {
    ll L, R, V;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll W, N;
    cin >> W >> N;
    vector<Data> D(N);
    REP(i, N) {
        cin >> D[i].L >> D[i].R >> D[i].V;
    }
    vector<ll> dp(W + 5, -INF);
    dp[0] = 0;
    REP(i, N) {
        vector<ll> tmp(W + 5, -INF);
        deque<pll> q;
        REP(j, W + 1) {
            while (!q.empty() && q.front().first + D[i].R < j) {
                q.pop_front();
            }
            if (j >= D[i].L) {
                ll v = dp[j - D[i].L] + D[i].V;
                while (!q.empty() && q.back().second < v) {
                    q.pop_back();
                }
                q.push_back(pll(j - D[i].L, v));
            }
            ll val = q.empty() ? -INF : q.front().second;
            tmp[j] = std::max({tmp[j], dp[j], val});
        }

        swap(dp, tmp);
    }

    cout << std::max(dp[W], -1LL) << endl;

    return 0;
}