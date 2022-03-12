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
    ll nxt = -1;
    ll sum = 0;
    ll index = -1;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    vector<Data> D(N);
    ll x = 0;
    ll s = 0;
    ll idx = 1;
    while (D[x].nxt < 0) {
        ll p = x;
        s += A[x];
        D[x].sum = s;
        D[x].index = idx;
        x += A[x];
        x %= N;
        D[p].nxt = x;
        idx++;
    }

    ll loop = x;
    ll loopSize = idx - D[loop].index;
    ll loopSum = s - D[loop].sum + A[loop];
    ll ans = 0;
    if (D[loop].index > K) {
        REP(i, N) {
            if (D[i].index == K) {
                ans = D[i].sum;
                break;
            }
        }
    } else if (loopSize == 0) {
        assert(false);
    } else {
        ans = D[loop].sum - A[loop];
        K -= (D[loop].index - 1);
        ans += loopSum * (K / loopSize);
        K %= loopSize;
        ll tt = loop;
        REP(_, K) {
            ans += A[tt];
            tt += A[tt];
            tt %= N;
        }
    }

    cout << ans << endl;

    return 0;
}