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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    vector<bool> seen(N, false);
    vector<ll> B(N);
    REP(i, N) {
        if (seen[i])
            continue;
        vector<ll> v;
        ll index = i;
        while (index < N) {
            v.push_back(A[index]);
            seen[index] = true;
            index += K;
        }
        sort(v.begin(), v.end());
        index = i;
        REP(j, v.size()) {
            B[index] = v[j];
            index += K;
        }
    }


    REP(i, N - 1) {
        if (B[i] > B[i + 1]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}