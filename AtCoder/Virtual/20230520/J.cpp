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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N = S.size();

    vector<ll> A(N);
    {
        ll n = 0;
        REP(i, N) {
            if (S[i] == 'R') {
                n++;
                if (i + 1 < N && S[i + 1] == 'L')
                    A[i] = n;
            } else {
                n = 0;
            }
        }
    }
    {
        ll n = 0;
        REP(i, N) {
            if (S[N - 1 - i] == 'L') {
                n++;
                if (N - 2 - i >= 0 && S[N - 2 - i] == 'R')
                    A[N - 1 - i] = n;
            } else {
                n = 0;
            }
        }
    }

    vector<ll> B(N);
    REP(i, N) {
        if (A[i] == 0)
            continue;
        if (S[i] == 'R') {
            B[i] += (A[i] + 1) / 2;
            B[i + 1] += A[i] / 2;
        } else {
            B[i] += (A[i] + 1) / 2;
            B[i - 1] += A[i] / 2;
        }
    }

    REP(i, N) {
        cout << B[i] << " ";
    }
    cout << endl;
    return 0;
}