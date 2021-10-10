#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    ll c, l, r;
};

int main() {
    ll N, M;
    cin >> N >> M;
    priority_queue<Data, vector<Data>, function<bool(Data, Data)>> q([](Data a, Data b) {
        if (a.l == b.l)
            return a.c > b.c;
        return a.l > b.l;
    });
    REP(i, M) {
        Data d;
        cin >> d.c >> d.l >> d.r;
        d.l--;
        d.r--;
        q.push(d);
    }
    ll ans = 0;
    REP(i, N) {
        if (q.empty()) {
            ans = -1;
            break;
        }
        auto t = q.top();
        q.pop();
        if (t.l != i) {
            ans = -1;
            break;
        }
        ans += t.c;
        while (!q.empty() && q.top().l == i) {
            auto x = q.top();
            q.pop();
            if (t.l == x.l && t.r == x.r)
                continue;
            if (t.r < x.r)
                x.l = t.r + 1;
            else {
                x.l = x.r + 1;
                x.r = t.r;
            }
            q.push(x);
        }
    }
    cout << ans << endl;
    return 0;
}