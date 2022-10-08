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
    ll N, X;
    cin >> N >> X;
    std::map<ll, ll> mp;
    mp[1] = 1;
    REP(i, N) {
        ll L;
        cin >> L;
        std::map<ll, ll> tmp;
        REP(j, L) {
            ll n;
            cin >> n;
            if (X % n != 0)
                continue;
            for (auto p: mp) {
                ll nxt = p.first * n;
                if (nxt < p.first || nxt < n)
                    continue;
                if (nxt > X || X % nxt != 0)
                    continue;
                tmp[nxt] += p.second;
            }
        }
        swap(mp, tmp);
    }

    cout << mp[X] << endl;
    return 0;
}