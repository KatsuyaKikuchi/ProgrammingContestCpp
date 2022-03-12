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
vector<string> S;

bool check(ll x, ll y) {
    {
        ll count = 0;
        REP(i, 6) {
            if (i + x >= N) {
                count = -1;
                break;
            }
            if (S[i + x][y] == '#')count++;
        }

        if (count >= 4)
            return true;
    }
    {
        ll count = 0;
        REP(i, 6) {
            if (i + y >= N) {
                count = -1;
                break;
            }
            if (S[x][i + y] == '#')count++;
        }

        if (count >= 4)
            return true;
    }
    {
        ll count = 0;
        REP(i, 6) {
            if (i + y >= N || i + x >= N) {
                count = -1;
                break;
            }
            if (S[i + x][i + y] == '#')count++;
        }

        if (count >= 4)
            return true;
    }
    {
        ll count = 0;
        REP(i, 6) {
            if (y - i < 0 || i + x >= N) {
                count = -1;
                break;
            }
            if (S[i + x][y - i] == '#')count++;
        }

        if (count >= 4)
            return true;
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    S.resize(N);

    REP(i, N) {
        cin >> S[i];
    }

    REP(i, N) {
        REP(j, N) {
            if (check(i, j)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}