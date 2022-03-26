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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    vector<ll> B(N);
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> B[i];
    }
    bool a = true, b = true;
    FOR(i, N, 1) {
        bool na = false, nb = false;

        if (a) {
            if (abs(A[i - 1] - A[i]) <= K)na = true;
            if (abs(A[i - 1] - B[i]) <= K)nb = true;
        }
        if (b) {
            if (abs(B[i - 1] - A[i]) <= K)na = true;
            if (abs(B[i - 1] - B[i]) <= K)nb = true;
        }
        a = na;
        b = nb;
        if (!a && !b) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}