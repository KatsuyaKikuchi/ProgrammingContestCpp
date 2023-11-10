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

ll N;
ll A[20][20];
bool S[20];

ll dfs(ll index = 0, ll sum = 0) {
    if (index == N - 1) {
        return sum;
    }
    if (S[index]) {
        return dfs(index + 1, sum);
    }
    ll ret = 0;
    FOR(i, N, index) {
        if (S[i]) {
            continue;
        }
        S[i] = true;
        ret = std::max(ret, dfs(index + 1, sum + A[index][i]));
        S[i] = false;
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;

    REP(i, N - 1) {
        FOR(j, N, i + 1) {
            ll a;
            cin >> a;
            A[i][j] = A[j][i] = a;
        }
    }
    REP(i, N) {
        S[i] = false;
    }
    cout << dfs() << endl;

    return 0;
}