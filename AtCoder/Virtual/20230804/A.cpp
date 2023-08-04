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


//
// 後で修正する
//
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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    ll ans = INF;
    SegmentTree<ll> seg([](ll a, ll b) { return std::max(a, b); }, -INF);
    seg.init(N);
    vector<ll> v;
    REP(i, K) {
        v.push_back(A[i]);
    }
    v.push_back(0);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    REP(i, K) {
        ll idx = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
        ll value = seg.get(idx, idx);
        seg.set(idx, std::max(value, i));
    }
    FOR(i, N, K) {
        ll idx = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
        ll mx = seg.get(0, idx - 1);
        ll diff = i - mx;
        ans = std::min(diff, ans);
    }

    if (ans >= INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}