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

template<typename T>
struct SegmentTree {
    using F = std::function<T(T, T)>;

    SegmentTree(F func, T id)
            : merge(func), identity(id) {}

    void init(int n) {
        offset = 1;
        while (offset < n)
            offset <<= 1;
        node.assign(offset << 1, identity);
    }

    void build(const std::vector<T> &v) {
        int n = static_cast<int>(v.size());
        init(n);
        for (int i = 0; i < n; ++i) {
            node[offset + i] = v[i];
        }
        for (int i = offset - 1; i >= 0; --i) {
            node[i] = merge(node[(i << 1) | 0], node[(i << 1) | 1]);
        }
    }

    void set(int index, T value) {
        index += offset;
        node[index] = value;
        while (index >>= 1) {
            node[index] = merge(node[(index << 1) | 0], node[(index << 1) | 1]);
        }
    }

    //! [left, right]
    T get(int left, int right) {
        if (left > right)
            return identity;
        left += offset;
        right += offset + 1;

        T val = identity;
        while (left < right) {
            if (left & 1)
                val = merge(val, node[left++]);
            if (right & 1)
                val = merge(val, node[--right]);

            left >>= 1;
            right >>= 1;
        }
        return val;
    }

    T identity;
    F merge;
    std::vector<T> node;
    int offset;
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    vector<ll> C(N);
    vector<ll> X(M);
    SegmentTree<ll> seg([](ll a, ll b) { return std::min(a, b); }, INF);
    seg.init(N + 10);
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> C[i];
        seg.set(i, C[i]);
    }
    REP(i, M) {
        cin >> X[i];
    }

    vector<vector<ll>> dp(M + 5, vector<ll>(N + 5, INF));
    dp[0][0] = 0;
    REP(i, M) {
        ll p = 0;
        if (i > 0)
            p = X[i - 1];
        vector<ll> tmp(N + 5, INF);
        REP(j, N + 5) {
            tmp[j] = dp[i][j];
        }
        for (ll j = p; j < X[i] - 1; ++j) {
            vector<ll> tmp0(N + 5, INF);
            for (ll k = i; k <= j; ++k) {
                tmp0[k] = std::min(tmp[k], tmp0[k]);
                ll c = seg.get(std::max(0LL, j - k), j);
                tmp0[k + 1] = std::min(tmp0[k + 1], tmp[k] + A[j] + c);
            }
            swap(tmp0, tmp);
        }
        for (ll j = i; j < X[i]; ++j) {
            ll c = seg.get(std::max(0LL, X[i] - 1 - j), X[i] - 1);
            dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], tmp[j] + A[X[i] - 1] + c);
        }
    }

    ll ans = INF;
    REP(i, N) {
        FOR(j, N + 1, M) {
            ans = std::min(ans, dp[M][j]);
        }
    }
    cout << ans << endl;
    return 0;
}