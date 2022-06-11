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
string S;
vector<ll> A;

bool check(ll k, bool out = false) {
    ll M = N + 1;
    vector<vector<ll>> B(k, vector<ll>(M, 0));

    REP(i, M) {
        ll n = A[i] / k;
        ll p = A[i] % k;
        REP(j, k) {
            B[j][i] = n;
            if (p > 0)
                B[j][i]++;
            p--;
        }
    }

    REP(i, k) {
        REP(j, N) {
            if (S[j] == '<' && B[i][j] >= B[i][j + 1])
                return false;
            if (S[j] == '>' && B[i][j] <= B[i][j + 1])
                return false;
        }
    }

    if (out) {
        cout << k << endl;
        REP(i, k) {
            REP(j, M) {
                cout << B[i][j] << " ";
            }
            cout << endl;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    cin >> S;
    A.resize(N + 1);
    REP(i, N + 1) {
        cin >> A[i];
    }

    ll ok = 1, ng = 10005;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }
    check(ok, true);
    return 0;
}