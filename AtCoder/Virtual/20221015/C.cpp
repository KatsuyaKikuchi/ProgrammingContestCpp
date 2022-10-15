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
ll H, W, N, M;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W >> N >> M;
    vector<string> S(H);
    REP(i, H) {
        REP(j, W) {
            S[i].push_back('.');
        }
    }
    REP(i, N) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        S[a][b] = 'x';
    }
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        S[a][b] = '#';
    }
    vector<vector<bool>> T(H, vector<bool>(W, false));

    REP(i, H) {
        bool e = false;
        REP(j, W) {
            if (S[i][j] == 'x')
                e = true;
            else if (S[i][j] == '#')
                e = false;

            if (e)
                T[i][j] = true;
        }
    }
    REP(j, W) {
        bool e = false;
        REP(i, H) {
            if (S[i][j] == 'x')
                e = true;
            else if (S[i][j] == '#')
                e = false;

            if (e)
                T[i][j] = true;
        }
    }
    REP(i, H) {
        bool e = false;
        REP(j, W) {
            if (S[i][j] == 'x')
                e = true;
            else if (S[i][j] == '#')
                e = false;

            if (e)
                T[i][j] = true;
        }
    }
    for (ll i = H - 1; i >= 0; --i) {
        bool e = false;
        for (ll j = W - 1; j >= 0; --j) {
            if (S[i][j] == 'x')
                e = true;
            else if (S[i][j] == '#')
                e = false;

            if (e)
                T[i][j] = true;
        }
    }
    for (ll j = W - 1; j >= 0; --j) {
        bool e = false;
        for (ll i = H - 1; i >= 0; --i) {
            if (S[i][j] == 'x')
                e = true;
            else if (S[i][j] == '#')
                e = false;

            if (e)
                T[i][j] = true;
        }
    }

    ll ans = 0;
    REP(i, H) {
        REP(j, W) {
            if (T[i][j])
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}