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

const ll N = 4;
ll A[N][N];
ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

void dfs(const vector<vector<bool>> &M, vector<vector<bool>> &seen, pll g) {
    REP(i, 4) {
        ll nx = x[i] + g.first, ny = y[i] + g.second;
        if (nx < 0 || ny < 0 || nx >= N + 2 || ny >= N + 2)
            continue;
        if (seen[nx][ny])
            continue;
        if (M[g.first][g.second] != M[nx][ny])
            continue;
        seen[nx][ny] = true;
        dfs(M, seen, pll(nx, ny));
    }
}

bool painted(ll bit, ll h, ll w) {
    ll mask = (1LL << (N * h + w));
    return (bit & mask) > 0;
}

bool check(ll bit) {
    ll n = N + 2;
    vector<vector<bool>> M(n, vector<bool>(n, false));
    REP(i, N) {
        REP(j, N) {
            M[i + 1][j + 1] = painted(bit, i, j);
        }
    }

    vector<vector<bool>> seen(n, vector<bool>(n, false));
    ll count = 0;
    REP(i, n) {
        REP(j, n) {
            if (seen[i][j])
                continue;
            seen[i][j] = true;
            dfs(M, seen, pll(i, j));
            count++;
        }
    }

    return count == 2;
}

int main() {
    REP(i, N) {
        REP(j, N) {
            cin >> A[i][j];
        }
    }

    ll ans = 0;
    REP(bit, pow(2, N * N)) {
        bool e = true;
        REP(i, N) {
            REP(j, N) {
                if (A[i][j] == 1 && !painted(bit, i, j))
                    e = false;
            }
        }
        if (e && check(bit))
            ans++;
    }
    cout << ans << endl;
    return 0;
}