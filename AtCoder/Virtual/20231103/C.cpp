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

struct Vertex {
    vector<ll> to;
    vector<ll> from;
    ll count = 0;
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;

    vector<Vertex> V(N);
    REP(i, N) {
        ll c;
        cin >> c;
        REP(_, c) {
            ll a;
            cin >> a;
            a--;
            V[a].to.push_back(i);
            V[i].from.push_back(a);
        }
    }


    queue<ll> q;
    q.push(0);
    vector<bool> seen(N, false);
    seen[0] = true;
    while (!q.empty()) {
        ll t = q.front();
        q.pop();
        for (auto n: V[t].from) {
            if (seen[n])
                continue;
            seen[n] = true;
            q.push(n);
        }
    }

    REP(i, N) {
        if (seen[i] && V[i].from.empty())
            q.push(i);
    }

    vector<ll> ans;
    while (!q.empty()) {
        ll t = q.front();
        q.pop();
        ans.push_back(t);
        for (auto n: V[t].to) {
            if (!seen[n])
                continue;
            V[n].count++;
            if (V[n].from.size() == V[n].count)
                q.push(n);
        }
    }

    REP(i, ans.size() - 1) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}