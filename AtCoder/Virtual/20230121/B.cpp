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
    }

    vector<pll> ans;

    REP(i, N) {
        if (i + 1 < N && (P[i] % 2 == i % 2) && (P[i + 1] % 2 == (i + 1) % 2)) {
            swap(P[i], P[i + 1]);
            ans.emplace_back(1, i);
        }
        if (i + 2 < N && (P[i] % 2 == i % 2)) {
            swap(P[i], P[i + 2]);
            ans.emplace_back(2, i);
        }
    }
    REP(i, N) {
        if (i + 1 < N && (P[i] % 2 == i % 2) && (P[i + 1] % 2 == (i + 1) % 2)) {
            swap(P[i], P[i + 1]);
            ans.emplace_back(1, i);
        }
        if (i + 2 < N && (P[i] % 2 == i % 2)) {
            swap(P[i], P[i + 2]);
            ans.emplace_back(2, i);
        }
    }

    for (ll i = 0; i < N; i += 2) {
        for (ll j = N - 1 - ((N + 1) % 2); j > i; j -= 2) {
            if (P[j] < P[j - 2]) {
                swap(P[j], P[j - 2]);
                ans.emplace_back(2, j - 2);
            }
        }
    }
    for (ll i = 1; i < N; i += 2) {
        for (ll j = N - 1 - (N % 2); j > i; j -= 2) {
            if (P[j] < P[j - 2]) {
                swap(P[j], P[j - 2]);
                ans.emplace_back(2, j - 2);
            }
        }
    }

    cout << ans.size() << endl;
    REP(i, ans.size()) {
        if (ans[i].first == 1)cout << "A ";
        else cout << "B ";
        cout << ans[i].second + 1 << endl;
    }


    return 0;
}