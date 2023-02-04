#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 200;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
        A[i] %= MOD;
    }
    vector<vector<vector<vector<ll>>>> dp(N + 5, vector<vector<vector<ll>>>(205));
    dp[0][0].push_back(vector<ll>(0));
    pll e(-1, -1);
    REP(i, N) {
        REP(j, 200) {
            for (auto x: dp[i][j]) {
                vector<ll> c;
                for (auto n: x) {
                    c.push_back(n);
                }
                dp[i + 1][j].push_back(c);
            }
            ll s = (A[i] + j) % MOD;
            for (auto x: dp[i][j]) {
                vector<ll> c;
                for (auto n: x) {
                    c.push_back(n);
                }
                c.push_back(i);
                dp[i + 1][s].push_back(c);
            }
        }

        REP(j, 200) {
            ll count = 0;
            for (auto x: dp[i + 1][j]) {
                if (x.size() > 0)count++;
            }
            if (count > 1) {
                e = pll(i + 1, j);
            }
        }
    }

    if (e.second < 0) {
        cout << "No" << endl;
        return 0;
    }
    vector<ll> B, C;
    for (auto x: dp[e.first][e.second]) {
        if (x.size() > 0) {
            if (B.size() == 0)
                B = x;
            else
                C = x;
        }
    }

    cout << "Yes" << endl;
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    cout << B.size();
    REP(i, B.size()) {
        cout << " " << B[i] + 1;
    }
    cout << endl;
    cout << C.size();
    REP(i, C.size()) {
        cout << " " << C[i] + 1;
    }
    cout << endl;

    return 0;
}