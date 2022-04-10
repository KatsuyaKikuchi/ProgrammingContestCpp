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
    vector<pll> node;
};

ll dist(string s, const string &g, ll sum = 0) {
    ll n = s.size();
    ll m = g.size();
    if (n == 0) {
        return m + sum;
    }
    if (n <= m) {
        bool e = true;
        REP(i, n) {
            if (s[i] != g[i])
                e = false;
        }
        if (e) {
            return m - n + sum;
        }
    }
    s.pop_back();
    return dist(s, g, sum + 1);
}

vector<string> pattern(vector<ll> v) {
    vector<string> ret;
    do {
        string s;
        REP(i, v.size()) {
            s.push_back('0' + v[i]);
        }
        ret.push_back(s);
    } while (next_permutation(v.begin(), v.end()));
    return ret;
}

vector<string> S;
vector<Vertex> V;
std::map<string, ll> mp;

ll solve() {
    ll E, W;
    cin >> E >> W;
    vector<vector<ll>> X(E + 1, vector<ll>(W, 0));
    REP(i, E) {
        REP(j, W) {
            cin >> X[i][j];
        }
    }

    vector<ll> dp(S.size(), INF);
    ll emp = mp[""];
    dp[emp] = 0;
    vector<string> prev;
    prev.emplace_back("");
    REP(i, E + 1) {
        vector<ll> v;
        REP(j, W) {
            REP(_, X[i][j]) {
                v.push_back(j);
            }
        }

        auto now = pattern(v);
        vector<ll> tmp(S.size(), INF);
        for (auto s0: now) {
            ll ni = mp[s0];
            for (auto s1: prev) {
                ll pi = mp[s1];
                ll d = dist(s1, s0);
                tmp[ni] = std::min(tmp[ni], dp[pi] + d);
            }
        }

        swap(now, prev);
        swap(dp, tmp);
    }

    return dp[emp];
}

ll solve2() {
    ll E, W;
    cin >> E >> W;
    vector<vector<ll>> X(E, vector<ll>(W, 0));
    REP(i, E) {
        REP(j, W) {
            cin >> X[i][j];
        }
    }

    ll ret = 0;
    REP(j, W) {
        ll min = INF;
        REP(i, E) {
            min = std::min(X[i][j], min);
        }
        ret += min;
        REP(i, E) {
            X[i][j] -= min;
        }
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    REP(i, 4) {
        REP(j, 4) {
            REP(k, 4) {
                vector<ll> v;
                REP(_, i) {
                    v.push_back(0);
                }
                REP(_, j) {
                    v.push_back(1);
                }
                REP(_, k) {
                    v.push_back(2);
                }
                auto p = pattern(v);
                for (auto s: p) {
                    mp[s] = V.size();
                    S.push_back(s);
                    V.push_back(Vertex{});
                }
            }
        }
    }

    ll T;
    cin >> T;
    REP(i, T) {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
    return 0;
}