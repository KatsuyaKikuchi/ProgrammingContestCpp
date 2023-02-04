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

ll N, K;
vector<ll> A;
vector<vector<ll>> T;

bool solve2(ll l, ll r) {
    vector<ll> tmp;
    for (ll i = l; i <= r; ++i) {
        tmp.push_back(A[i]);
    }
    ll index = 0;
    while (true) {
        ll t = index + K - 1;
        if (t >= tmp.size())
            break;
        ll x = tmp[index];
        REP(j, K) {
            tmp[index + j] -= x;
        }
        index++;
    }
    //cout << left << " " << right << endl;
    REP(i, tmp.size()) {
        if (tmp[i] != 0)
            return false;
    }
    return true;
}

bool solve(ll l, ll r) {
    if (r - l <= 100) {
        return solve2(l, r);
    }
    ll left = (l + K - 1) / K;
    ll right = (r - K + 1) / K;
    left = std::min(left, right);

    vector<ll> tmp(K, 0);
    REP(i, K) {
        tmp[i] += T[right][i] - T[left][i];
    }
    {
        vector<ll> v;
        for (ll i = l; i < left * K; ++i) {
            v.push_back(A[i]);
        }
        REP(i, v.size()) {
            ll x = v[i];
            FOR(j, v.size(), i) {
                v[j] -= x;
            }
            ll size = K - v.size() + i;
            REP(j, size) {
                tmp[j] -= x;
            }
        }
    }
    ll len = r - right * K + 1;
    vector<ll> ret(len);
    REP(i, K) {
        ret[i] = tmp[i];
    }
    {
        ll t = 0;
        for (ll i = right * K; i <= r; ++i) {
            ret[t] += A[i];
            t++;
        }
    }
    ll index = 0;
    while (true) {
        ll t = index + K - 1;
        if (t >= len)
            break;
        ll x = ret[index];
        REP(j, K) {
            ret[index + j] -= x;
        }
        index++;
    }
    //cout << left << " " << right << endl;
    REP(i, ret.size()) {
        if (ret[i] != 0)
            return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    A.resize(N);
    REP(i, N) {
        cin >> A[i];
    }
    ll index = 0;
    T.resize(0);
    {
        vector<ll> v;
        REP(i, K) {
            v.push_back(0);
        }
        T.push_back(v);
    }
    while (true) {
        ll t = index + K;
        if (t >= N)
            break;
        vector<ll> v(K, 0);
        vector<ll> tmp;
        REP(i, K) {
            tmp.push_back(A[index + i]);
        }
        REP(i, K) {
            ll x = tmp[i];
            FOR(j, K, i) {
                tmp[j] -= x;
            }
            REP(j, i) {
                v[j] -= x;
            }
        }
        if (T.size() > 0) {
            REP(i, K) {
                v[i] += T[T.size() - 1][i];
            }
        }
        T.push_back(v);
        index += K;
    }
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll l, r;
        cin >> l >> r;
        if (solve(l - 1, r - 1))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}