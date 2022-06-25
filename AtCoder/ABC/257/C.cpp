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
    string S;
    cin >> S;
    vector<ll> A, B, W;
    REP(i, N) {
        ll a;
        cin >> a;
        if (S[i] == '0')
            A.push_back(a);
        else
            B.push_back(a);
        W.push_back(a);
    }
    W.push_back(INF);
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(W.begin(), W.end());
    ll ans = B.size();
    ll ia = 0, ib = 0;
    REP(i, W.size()) {
        while (ia < A.size()) {
            if (A[ia] >= W[i])
                break;
            ia++;
        }
        while (ib < B.size()) {
            if (B[ib] >= W[i])
                break;
            ib++;
        }
        ll t = ia + B.size() - ib;
        ans = std::max(ans, t);
    }

    cout << ans << endl;
    return 0;
}