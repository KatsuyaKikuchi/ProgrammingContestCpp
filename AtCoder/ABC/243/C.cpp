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

string S;
ll N;
vector<pll> A;

bool solve() {
    std::map<ll, ll> L, R;
    REP(i, N) {
        ll y = A[i].second;
        ll x = A[i].first;
        if (S[i] == 'L') {
            {
                auto it = R.find(y);
                if (it != R.end()) {
                    if (it->second < x) {
                        return true;
                    }
                }
            }
            {
                auto it = L.find(y);
                if (it == L.end() || it->second < x)
                    L[y] = x;
            }
        } else {
            {
                auto it = L.find(y);
                if (it != L.end()) {
                    if (it->second > x) {
                        return true;
                    }
                }
            }
            {
                auto it = R.find(y);
                if (it == R.end() || it->second > x)
                    R[y] = x;
            }
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    A.resize(N);

    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }

    cin >> S;
    if (solve())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}