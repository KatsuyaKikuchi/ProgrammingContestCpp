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
    ll index;
    ll t;
    ll x, y;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    vector<Query> q(Q);
    REP(i, Q) {
        q[i].index = i;
        cin >> q[i].t;
        if (q[i].t == 1)
            cin >> q[i].x >> q[i].y;
        else
            cin >> q[i].x;
        q[i].x--;
        q[i].y--;
    }

    std::map<ll, ll> mp;
    std::map<ll, vector<ll>> edge;
    std::set<ll> seen;
    ll ans = N;
    REP(i, Q) {
        if (q[i].t == 1) {
            mp[q[i].x]++;
            mp[q[i].y]++;
            if (mp[q[i].x] == 1)
                ans--;
            if (mp[q[i].y] == 1)
                ans--;
            edge[q[i].x].push_back(i);
            edge[q[i].y].push_back(i);
        } else {
            for (auto n: edge[q[i].x]) {
                if (seen.find(n) != seen.end())
                    continue;
                ll next = q[n].x;
                if (next == q[i].x)
                    next = q[n].y;
                mp[next]--;
                if (mp[next] == 0)
                    ans++;
                seen.insert(n);
            }
            edge[q[i].x].clear();
            if (mp[q[i].x] > 0)
                ans++;
            mp[q[i].x] = 0;

        }
        cout << ans << endl;
    }


    return 0;
}