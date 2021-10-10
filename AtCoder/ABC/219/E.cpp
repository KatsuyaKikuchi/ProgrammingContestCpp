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
const ll MAX = 5;

ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

bool U[MAX][MAX];
ll A[MAX][MAX];
vector<vector<pll>> W;

bool check(vector<pll> &v) {
    vector<vector<ll>> C(MAX, vector<ll>(MAX, 0));
    REP(i, v.size() - 1) {
        pll p0 = v[i];
        pll p1 = v[i + 1];
        if (p0.first == p1.first)
            continue;
        ll w = p0.second;
        ll h = std::min(p0.first, p1.first);
        C[h][w]++;
    }

    REP(i, MAX) {
        REP(j, MAX - 1) {
            C[i][j + 1] += C[i][j];
        }
    }
    REP(i, MAX) {
        REP(j, MAX) {
            if (A[i][j] == 1 && C[i][j] % 2 == 0)
                return false;
        }
    }
    return true;
}

void dfs(vector<pll> &v) {
    pll g = v.back();
    pll p = v.size() > 1 ? v[v.size() - 2] : pll(-1, -1);
    pll s = v.front();
    U[g.first][g.second] = true;
    REP(i, 4) {
        ll nx = x[i] + g.first, ny = y[i] + g.second;
        if (nx < 0 || ny < 0 | nx >= MAX || ny >= MAX)
            continue;
        if (nx == p.first && ny == p.second)
            continue;
        if (nx == s.first && ny == s.second) {
            vector<pll> c;
            v.emplace_back(nx, ny);
            copy(v.begin(), v.end(), back_inserter(c));
            v.pop_back();
            W.push_back(c);
            continue;
        }
        if (U[nx][ny])
            continue;

        v.emplace_back(nx, ny);
        dfs(v);
        v.pop_back();
    }
    U[g.first][g.second] = false;
}

int main() {
    REP(i, 4) {
        REP(j, 4) {
            cin >> A[i][j];
        }
    }

    memset(U, 0, sizeof(U));
    REP(i, MAX) {
        REP(j, MAX) {
            vector<pll> t;
            t.emplace_back(i, j);
            dfs(t);
            U[i][j] = true;
        }
    }

    ll ans = 0;
    for (auto &t: W) {
        if (check(t))
            ans++;
    }
    cout << ans / 2 << endl;
    return 0;
}