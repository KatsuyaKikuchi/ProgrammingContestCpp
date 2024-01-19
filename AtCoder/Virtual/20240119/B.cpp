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

struct Data {
    ll T, N, C;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W, C, Q;
    cin >> H >> W >> C >> Q;
    vector<Data> A(Q);
    REP(i, Q) {
        cin >> A[i].T >> A[i].N >> A[i].C;
    }
    vector<ll> ans(C);
    ll h = 0, w = 0;
    set<ll> usedH, usedW;
    for (ll i = Q - 1; i >= 0; --i) {
        if (A[i].T == 1) {
            if (usedH.find(A[i].N) == usedH.end()) {
                ans[A[i].C - 1] += W - w;
                h++;
            }
            usedH.insert(A[i].N);
        } else {
            if (usedW.find(A[i].N) == usedW.end()) {
                ans[A[i].C - 1] += H - h;
                w++;
            }
            usedW.insert(A[i].N);
        }
    }

    REP(i, C) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}