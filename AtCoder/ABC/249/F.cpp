#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;
const long double PI = 3.1415926535897932384626433832795028841971;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    vector<pll> A;

    cin >> N >> K;
    A.resize(N);
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }

    priority_queue<ll, vector<ll>, function<bool(ll, ll)>> q([](ll a, ll b) { return a < b; });
    ll max = -INF;
    ll p = 0;
    ll k = K;
    for (ll i = N - 1; i >= 0; i--) {
        if (A[i].first == 1) {
            max = std::max(max, p + A[i].second);
            k--;
        } else {
            if (A[i].second >= 0)
                p += A[i].second;
            else {
                q.push(A[i].second);
            }
        }
        while (q.size() > k) {
            ll t = q.top();
            q.pop();
            p += t;
        }

        if (k < 0)
            break;

        if (i == 0)
            max = std::max(max, p);
    }

    cout << max << endl;
    return 0;
}