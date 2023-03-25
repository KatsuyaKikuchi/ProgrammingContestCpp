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
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    ll ans = 0;
    REP(i, N) {
        ll right = N - i;
        ll t = std::min(i, right);
        ll n = i;
        ll x = std::min(n, t) * (std::min(n, t) + 1) / 2 + (n - std::min(n, t)) * t;
        ans += x;
    }

    vector<vector<ll>> X(N);
    REP(i, N) {
        X[A[i] - 1].push_back(i);
    }

    REP(i, N) {
        stack<ll> st;
        ll sum = 0;
        ll count = 0;
        for (auto t: X[i]) {
            ll right = N - t;
            while (!st.empty()) {
                ll tmp = st.top();
                if (tmp < right)
                    break;
                st.pop();
                sum -= tmp + 1;
                count++;
            }
            ll s = sum + count * right;
            ans -= s;
            if (t < (N + 1) / 2) {
                st.push(t);
                sum += t + 1;
            } else {
                count++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}