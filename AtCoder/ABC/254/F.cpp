#include <bits/stdc++.h>
#include "atcoder/all"

using namespace atcoder;
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

    void debug() {
        ll row = 2;
        for (int i = 1; i < node.size(); ++i) {
            if (i == row) {
                row *= 2;
                cout << endl;
            }
            cout << node[i] << " ";
        }
        cout << endl;
    }

    T identity;
    F merge;
    std::vector<T> node;
    int offset;
};

ll gcd(ll a, ll b) {
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N), B(N);
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> B[i];
    }
    SegmentTree<ll> segA([](ll a, ll b) { return gcd(a, b); }, 0);
    segA.init(N - 1);
    SegmentTree<ll> segB([](ll a, ll b) { return gcd(a, b); }, 0);
    segB.init(N - 1);
    REP(i, N - 1) {
        segA.set(i, abs(A[i] - A[i + 1]));
    }
    REP(i, N - 1) {
        segB.set(i, abs(B[i] - B[i + 1]));
    }

    REP(i, Q) {
        ll h1, h2, w1, w2;
        cin >> h1 >> h2 >> w1 >> w2;
        h1--;
        h2--;
        w1--;
        w2--;

        ll ans = A[h1] + B[w1];

        if (h1 != h2) {
            ll a = segA.get(h1, h2 - 1);
            ans = gcd(ans, a);
        }
        if (w1 != w2) {
            ll b = segB.get(w1, w2 - 1);
            ans = gcd(ans, b);
        }
        cout << ans << endl;
    }
    return 0;
}