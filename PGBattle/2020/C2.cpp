#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

vector<vector<ll>> ans;

ll N, S;

void dfs(vector<ll> &v, ll sum = 0) {
    ll size = v.size();
    if (size == N) {
        if (sum != S)
            return;
        vector<ll> tmp(N);
        REP(i, N) {
            tmp[i] = v[i];
        }
        ans.push_back(tmp);
        return;
    }

    ll s = size == 0 ? 1 : v[size - 1];
    for (ll n = s; n <= S; ++n) {
        if (sum + n * (N - size) > S)
            break;
        sum += n;
        v.push_back(n);
        dfs(v, sum);
        v.pop_back();
        sum -= n;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> S;
    vector<ll> v;
    dfs(v);

    REP(i, ans.size()) {
        REP(j, ans[i].size()) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}