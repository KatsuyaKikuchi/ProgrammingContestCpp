#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>
#include <map>
#include <set>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Vertex {
    vector<pll> node;
    ll num = 1;
    ll cnt = 0;
    ll parent = -1;
    ll len = 0;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<Vertex> V(N);
    REP(i, N - 1) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        V[a].node.push_back(pll(b, c));
        V[b].node.push_back(pll(a, c));
    }
    {
        queue<ll> q;
        REP(i, N) {
            if (V[i].node.size() != 1)
                continue;
            q.push(i);
        }

        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (auto n: V[t].node) {
                if (V[n.first].parent != -1)
                    continue;
                V[n.first].num += V[t].num;
                V[n.first].cnt++;
                V[t].parent = n.first;
                if (V[n.first].cnt == V[n.first].node.size() - 1) {
                    q.push(n.first);
                }
            }
        }
    }
    vector<ll> P, Q;
    ll len = 0;
    {
        ll p = -1, q = -1;
        REP(i, N) {
            if (V[i].num == N / 2) {
                p = i;
                q = V[i].parent;
                for (auto &n: V[i].node) {
                    if (n.first == q) {
                        len = n.second;
                        break;
                    }
                }
            }
        }
        if (p < 0 || q < 0) {
            cout << 0 << endl;
            return 0;
        }
        vector<bool> seen(N, false);
        seen[p] = true;
        seen[q] = true;
        stack<pll> stk;
        stk.push(pll(p, 0));
        while (!stk.empty()) {
            auto t = stk.top();
            stk.pop();
            P.push_back(t.second);
            for (auto &n: V[t.first].node) {
                if (seen[n.first] || n.first == q)
                    continue;
                ll l = t.second + n.second;
                seen[n.first] = true;
                stk.push(pll(n.first, l));
            }
        }
        stk.push(pll(q, 0));
        while (!stk.empty()) {
            auto t = stk.top();
            stk.pop();
            Q.push_back(t.second);
            for (auto &n: V[t.first].node) {
                if (seen[n.first] || n.first == p)
                    continue;
                ll l = t.second + n.second;
                seen[n.first] = true;
                stk.push(pll(n.first, l));
            }
        }
        sort(P.begin(), P.end());
        sort(Q.begin(), Q.end());
    }

    ll ans = 0;
    REP(i, P.size()) {
        ll x = P[i];
        ll y = len;

        // x-y < t <= x+yとなるQの頂点数を数える
        ll mini, maxi, ng;
        {
            mini = Q.size() + 1;
            ng = -1;
            while (abs(mini - ng) > 1) {
                ll mid = (mini + ng) / 2;
                if (Q[mid] > x - y)
                    mini = mid;
                else
                    ng = mid;
            }
        }
        {
            maxi = -1;
            ng = Q.size();
            while (abs(maxi - ng) > 1) {
                ll mid = (maxi + ng) / 2;
                if (Q[mid] <= x + y)
                    maxi = mid;
                else
                    ng = mid;
            }
        }
        ans += std::max(0LL, maxi - mini + 1);
    }
    REP(i, P.size()) {
        ll x = P[i];
        ll y = len;

        // x-y < t <= x+yとなるQの頂点数を数える
        ll mini, maxi, ng;
        {
            mini = Q.size() + 1;
            ng = -1;
            while (abs(mini - ng) > 1) {
                ll mid = (mini + ng) / 2;
                if (Q[mid] >= x - y)
                    mini = mid;
                else
                    ng = mid;
            }
        }
        {
            maxi = -1;
            ng = Q.size();
            while (abs(maxi - ng) > 1) {
                ll mid = (maxi + ng) / 2;
                if (Q[mid] < x + y)
                    maxi = mid;
                else
                    ng = mid;
            }
        }
        ans += std::max(0LL, maxi - mini + 1);
    }

    cout << ans << endl;

    return 0;
}