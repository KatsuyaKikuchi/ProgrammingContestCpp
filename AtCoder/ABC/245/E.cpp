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
    vector<pll> A(N), B(M);
    REP(i, N) {
        cin >> A[i].first;
    }
    REP(i, N) {
        cin >> A[i].second;
    }
    REP(i, M) {
        cin >> B[i].first;
    }
    REP(i, M) {
        cin >> B[i].second;
    }
    sort(A.begin(), A.end(), [](pll a, pll b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    });
    sort(B.begin(), B.end(), [](pll a, pll b) {
        return a.first > b.first;
    });

    map<ll, ll> mp;
    ll index = 0;

    REP(i, N) {
        while (index < M && B[index].first >= A[i].first) {
            mp[B[index].second]++;
            index++;
        }

        auto it = mp.lower_bound(A[i].second);
        if (it == mp.end()) {
            cout << "No" << endl;
            return 0;
        }
        it->second--;
        if (it->second == 0) {
            mp.erase(it);
        }
    }
    cout << "Yes" << endl;
    return 0;
}