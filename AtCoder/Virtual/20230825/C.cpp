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

struct Data {
    pll g;
    ll d;
};

ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<string> S(N);
    REP(i, N) {
        cin >> S[i];
    }

    bool A[205][205][4];
    memset(A, 0, sizeof(A));

    A[1][1][0] = true;
    queue<Data> q;
    q.push(Data{pll(1, 1), 0});
    q.push(Data{pll(1, 1), 1});
    q.push(Data{pll(1, 1), 2});
    q.push(Data{pll(1, 1), 3});

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        ll nx = x[t.d] + t.g.first, ny = y[t.d] + t.g.second;
        if (A[nx][ny][t.d]) {
            continue;
        }
        if (S[nx][ny] == '#') {
            REP(i, 4) {
                if (i == t.d)
                    continue;
                ll nnx = x[i] + t.g.first, nny = y[i] + t.g.second;
                if (A[nnx][nny][i] || S[nnx][nny] == '#')
                    continue;
                A[nnx][nny][i] = true;
                q.push(Data{pll(nnx, nny), i});
            }
        } else {
            A[nx][ny][t.d] = true;
            q.push(Data{pll(nx, ny), t.d});
        }
    }

    ll ans = 0;
    REP(i, N) {
        REP(j, M) {
            REP(k, 4) {
                if (A[i][j][k]) {
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}