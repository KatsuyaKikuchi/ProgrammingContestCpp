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

ll calc(vector<ll> A) {
    ll ret = 0;
    REP(i, A.size() - 1) {
        ret += abs(A[i] - A[i + 1]);
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
    sort(A.begin(), A.end());
    ll ans = 0;
    if (N % 2 == 0) {
        vector<ll> t;
        vector<ll> a, b;
        REP(i, N / 2) {
            a.push_back(A[i]);
            b.push_back(A[i + N / 2]);
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        REP(i, N / 2) {
            t.push_back(a[i]);
            t.push_back(b[i]);
        }
        ans = calc(t);
    } else {
        vector<ll> a, b;
        REP(i, N / 2) {
            a.push_back(A[i]);
            b.push_back(A[i + 1 + N / 2]);
        }
        {
            vector<ll> t;
            t.push_back(A[N / 2]);
            REP(i, N / 2) {
                t.push_back(b[i]);
                t.push_back(a[i]);
            }
            ans = std::max(ans, calc(t));
        }
        {
            vector<ll> t;
            t.push_back(A[N / 2]);
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            REP(i, N / 2) {
                t.push_back(a[i]);
                t.push_back(b[i]);
            }
            ans = std::max(ans, calc(t));
        }
    }

    cout << ans << endl;
    return 0;
}