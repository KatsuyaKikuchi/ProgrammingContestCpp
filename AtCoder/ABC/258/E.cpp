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

struct Query {
    ll K;
    ll index;
    ll ans;
};
struct Data {
    ll count;
    ll start, nxt;
};

ll D[200005][55];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q, X;
    cin >> N >> Q >> X;
    vector<ll> W(N);
    REP(i, N) {
        cin >> W[i];
    }

    vector<ll> S(N + 5, 0);
    REP(i, N) {
        S[i + 1] += S[i] + W[i];
    }

    vector<ll> V(N, 0);

    REP(i, N) {
        ll x = X % S[N];
        ll count = (X / S[N]) * N;
        ll nxt = N, ng = i - 1;
        ll p = i;
        if (S[N] - S[i] < x) {
            x -= (S[N] - S[i]);
            count += N - i;
            ng = -1;
            p = 0;
        }

        while (abs(nxt - ng) > 1) {
            ll mid = (nxt + ng) / 2;
            if (S[mid] - S[p] >= x)
                nxt = mid;
            else
                ng = mid;
        }
        count += nxt - p;

        D[i][0] = nxt % N;
        V[i] = count;
    }

    REP(j, 50) {
        REP(i, N) {
            ll nxt = D[D[i][j]][j];
            D[i][j + 1] = nxt;
        }
    }

    REP(i, Q) {
        ll k;
        cin >> k;
        k--;
        ll d = 0;
        ll index = 0;
        while (k > 0) {
            if ((k & 1) == 1)
                d = D[d][index];
            index++;
            k /= 2;
        }
        ll ans = V[d];
        cout << ans << endl;
    }
    return 0;
}