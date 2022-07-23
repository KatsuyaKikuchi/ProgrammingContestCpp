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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<Vertex> V(N);
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    deque<ll> ans;
    ans.push_back(0);
    vector<bool> seen(N, false);
    {
        queue<ll> q;
        q.push(0);
        seen[0] = true;
        while (!q.empty()) {
            ll t = q.front();
            q.pop();
            for (auto n: V[t].node) {
                if (seen[n])
                    continue;
                seen[n] = true;
                q.push(n);
                ans.push_back(n);
                break;
            }
        }
    }
    {
        queue<ll> q;
        q.push(0);
        seen[0] = true;
        while (!q.empty()) {
            ll t = q.front();
            q.pop();
            for (auto n: V[t].node) {
                if (seen[n])
                    continue;
                seen[n] = true;
                q.push(n);
                ans.push_front(n);
                break;
            }
        }
    }

    cout << ans.size() << endl;
    while (!ans.empty()) {
        ll t = ans.front();
        ans.pop_front();
        cout << t + 1 << " ";
    }
    cout << endl;

    return 0;
}