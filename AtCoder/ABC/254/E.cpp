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
    vector<ll> node;
};

ll N, M;
vector<Vertex> V;

ll solve(ll x, ll k) {
    queue<pll> q;
    q.push(pll(x, 0));

    std::set<ll> st;
    st.insert(x);
    ll ret = 0;
    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        ret += t.first + 1;
        ll cost = t.second + 1;
        if (cost > k)
            continue;
        for (auto n: V[t.first].node) {
            if (st.find(n) != st.end())
                continue;
            q.push(pll(n, cost));
            st.insert(n);
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;

    V.resize(N);
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll x, k;
        cin >> x >> k;
        x--;

        cout << solve(x, k) << endl;
    }
    return 0;
}