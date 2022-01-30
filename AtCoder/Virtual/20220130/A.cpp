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

    REP(_, K) {
        bool update = false;
        REP(i, N) {
            if (A[i] != N) {
                update = true;
                break;
            }
        }
        if (!update)
            break;
        vector<ll> nxt(N, 0);
        {
            ll s = 0;
            vector<ll> tmp(N + 1, 0);
            REP(i, N) {
                s = s + 1 - tmp[i];
                nxt[i] += s;
                tmp[std::min(N, i + 1 + A[i])]++;
            }
        }
        {
            ll s = 0;
            vector<ll> tmp(N + 1, 0);
            for (ll i = N - 1; i >= 0; --i) {
                s = s + 1 - tmp[i + 1];
                nxt[i] += s;
                tmp[std::max(0LL, i - A[i])]++;
            }
        }
        REP(i, N) {
            nxt[i]--;
        }
        swap(nxt, A);
    }

    REP(i, N) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}