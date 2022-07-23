#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD0 = 1000000007;
const ll MOD1 = 1000000009;
const ll base = 998244353;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

struct Data {
    vector<pll> prime;
};

ll makeHash(const vector<ll> &v, ll mod) {
    ll hash = 0;
    ll r = base;
    REP(i, v.size()) {
        hash += (r * v[i]) % mod;
        r = (r * base) % mod;
        hash %= mod;
    }
    return hash;
}

pll makeHash(const vector<ll> &v) {
    pll ret = pll(makeHash(v, MOD0), makeHash(v, MOD1));
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<Data> D(N);
    vector<ll> P;
    REP(i, N) {
        ll m;
        cin >> m;
        REP(_, m) {
            ll p, e;
            cin >> p >> e;
            D[i].prime.emplace_back(p, e);
            P.push_back(p);
        }
    }
    sort(P.begin(), P.end());
    P.erase(unique(P.begin(), P.end()), P.end());
    vector<vector<ll>> T(P.size());
    REP(i, N) {
        for (auto p: D[i].prime) {
            ll index = lower_bound(P.begin(), P.end(), p.first) - P.begin();
            T[index].push_back(p.second);
        }
    }
    vector<pll> M(P.size(), pll(1, 0));
    REP(i, T.size()) {
        sort(T[i].begin(), T[i].end());
        T[i].erase(unique(T[i].begin(), T[i].end()), T[i].end());
        sort(T[i].begin(), T[i].end(), greater<ll>());

        M[i].first = T[i][0];
    }
    REP(i, N) {
        for (auto p: D[i].prime) {
            ll index = lower_bound(P.begin(), P.end(), p.first) - P.begin();
            if (T[index][0] == p.second)
                M[index].second++;
        }
    }

    ll ans = 0;

    std::set<pll> st;
    REP(i, N) {
        vector<ll> v;
        for (auto p: D[i].prime) {
            ll index = lower_bound(P.begin(), P.end(), p.first) - P.begin();
            if (M[index].first == p.second && M[index].second == 1) {
                v.emplace_back(index + 1);
            }
        }

        pll hash = makeHash(v);
        if (st.find(hash) != st.end())
            continue;
        ans++;
        st.insert(hash);
    }

    cout << ans << endl;

    return 0;
}