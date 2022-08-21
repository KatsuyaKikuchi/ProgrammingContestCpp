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
    vector<ll> P(2 * N);
    REP(i, 2 * N) {
        cin >> P[i];
    }

    vector<ll> ans;

    REP(i, 2 * N) {
        vector<ll> v;
        if (P[i] % 2 == 0) {
            if (P[i] <= N)
                continue;
            FOR(j, 2 * N - 1, i) {
                v.push_back(i);
                if (P[j + 1] > N)
                    break;
            }
        } else {
            if (P[i] > N)
                continue;
            FOR(j, 2 * N - 1, i) {
                v.push_back(i);
                if (P[j + 1] <= N)
                    break;
            }
        }

        reverse(v.begin(), v.end());
        REP(j, v.size()) {
            ll index = v[j];
            swap(P[index], P[index + 1]);
            ans.push_back(index);
        }
    }

    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}