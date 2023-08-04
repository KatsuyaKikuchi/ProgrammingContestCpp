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
    ll N, M;
    cin >> N >> M;
    vector<std::set<ll>> S(N);
    vector<std::set<ll>> I(M + 5);
    REP(i, N) {
        ll n;
        cin >> n;
        REP(_, n) {
            ll x;
            cin >> x;
            S[i].insert(x);
            I[x].insert(i);
        }
    }

    vector<ll> D(M + 5, INF);
    queue<pll> q;
    q.emplace(1, 0);
    D[1] = 0;
    for (auto idx: I[1]) {
        S[idx].erase(1);
    }
    vector<bool> seen(N, false);
    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        for (auto idx: I[t.first]) {
            if (seen[idx])
                continue;
            seen[idx] = true;
            vector<ll> v;
            for (auto x: S[idx]) {
                if (D[x] <= t.second)
                    continue;
                D[x] = t.second;
                v.push_back(x);
            }
            for (auto x: v) {
                q.emplace(x, t.second + 1);
                for (auto idx2: I[x]) {
                    S[idx2].erase(t.first);
                }
            }
        }
    }

    if (D[M] == INF)
        D[M] = -1;
    cout << D[M] << endl;
    return 0;
}