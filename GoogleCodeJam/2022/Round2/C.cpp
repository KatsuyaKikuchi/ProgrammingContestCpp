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

ll calcDist(pll &a, pll &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<pll> C(N);
    REP(i, N) {
        cin >> C[i].first >> C[i].second;
    }
    vector<pll> A(N + 1);
    REP(i, N + 1) {
        cin >> A[i].first >> A[i].second;
    }

    vector<ll> d(N);
    REP(i, N) {
        d[i] = i;
    }

    vector<vector<pll>> P(N);
    REP(i, N) {
        REP(j, N + 1) {
            P[i].push_back(pll(j, calcDist(C[i], A[j])));
        }
        sort(P[i].begin(), P[i].end(), [](pll a, pll b) {
            if (a.second == b.second)
                return a.first > b.first;
            return a.second < b.second;
        });
    }

    vector<pll> ans;
    do {
        ans.clear();
        ll count = 0;
        vector<bool> seen(N + 1, false);
        for (auto n: d) {
            ll nxt = 0;
            FOR(j, N + 1, 0) {
                ll index = P[n][j].first;
                if (seen[index])
                    continue;
                nxt = index;
                break;
            }
            if (nxt == 0)
                break;
            count++;
            seen[nxt] = true;
            ans.emplace_back(n, nxt);
        }
        if (count == N) {
            cout << "POSSIBLE" << endl;
            REP(i, ans.size()) {
                cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
            }
            return;
        }
    } while (next_permutation(d.begin(), d.end()));
    cout << "IMPOSSIBLE" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(i, T) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}