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


double calc(vector<ll> &A, double x) {
    ll N = A.size();
    double ret = x;
    REP(i, N) {
        ret += (A[i] - std::min((double) A[i], 2 * x)) / N;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    double left = 0, right = INF;
    REP(_, 1000) {
        double l = left + (right - left) / 3.0;
        double r = right - (right - left) / 3.0;

        if (calc(A, l) >= calc(A, r)) {
            left = l;
        } else {
            right = r;
        }
    }
    cout << OF64 << calc(A, left) << endl;
    return 0;
}