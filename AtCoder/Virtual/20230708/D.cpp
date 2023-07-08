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

vector<ll> get() {
    string n;
    cin >> n;
    vector<ll> ret;
    if (n == "-1" || n == "OK") {
        return ret;
    }

    ll N = ::atoi(n.c_str());
    REP(i, N) {
        ll x;
        cin >> x;
        x--;
        ret.push_back(x);
    }
    return ret;
}

void query(ll n) {
    cout << n + 1 << endl;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    stack<ll> stk;
    vector<bool> seen(N, false);
    seen[0] = true;
    ll prev = 0;
    while (true) {
        auto nxt = get();
        if (nxt.empty())
            break;
        ll q = -1;
        for (auto n: nxt) {
            if (seen[n])
                continue;
            seen[n] = true;
            q = n;
            break;
        }
        if (q < 0) {
            q = stk.top();
            stk.pop();
        } else {
            stk.push(prev);
        }
        prev = q;
        query(q);
    }
    return 0;
}