#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 998244353;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<pll> A(N);
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    ll M = 10;
    map<ll,ll> dp;
    dp[0] = 0;
    REP(i, N) {
        map<ll,ll> tmp;
        REP(j, M + 1) {
            // x = 10Cj組み合わせで;
            // 高橋君の美味しさの総和が A[i].first * j 増える;

            // 高橋:青木 = 0:10, 1:9, ... 10:0 で分けたときの係数を調べていきたい
            
        }
        swap(tmp,dp);
    }

    REP(bit, pow(2LL, N)) {

    }
    return 0;
}