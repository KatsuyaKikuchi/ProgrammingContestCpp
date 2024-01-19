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
    vector<ll> P(N);
    REP(i, N) {
        cin >> P[i];
        P[i]--;
    }

    ll target = 0;
    vector<pll> ans;
    REP(_, 2001) {
        bool enable = true;
        REP(i, N) {
            if (P[i] != i) {
                enable = false;
                break;
            }
        }
        if (enable) {
            cout << "Yes" << endl;
            cout << ans.size() << endl;
            REP(i, ans.size()) {
                cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
            }
            return 0;
        }

        vector<ll> tmp;
        ll index = 0;
        REP(i, N) {
            if (P[i] == target) {
                index = i;
                break;
            }
        }

        pll t;
        if (index == N - 1) {
            t = pll(index - 1, target - 1);
            ans.push_back(t);
        } else {
            t = pll(index, target - 1);
            ans.push_back(t);
            target++;
        }

        vector<ll> q;
        REP(i, N) {
            if (i == t.first || t.first + 1 == i)
                continue;
            q.push_back(P[i]);
        }
        for (ll i = 0; i <= t.second; ++i) {
            tmp.push_back(q[i]);
        }
        tmp.push_back(P[t.first]);
        tmp.push_back(P[t.first + 1]);
        for (ll i = t.second + 1; i < q.size(); ++i) {
            tmp.push_back(q[i]);
        }


        swap(tmp, P);
    }

    cout << "No" << endl;
    return 0;
}