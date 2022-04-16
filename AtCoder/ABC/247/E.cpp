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
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    SegmentTree<ll> segMin([](ll a, ll b) { return std::min(a, b); }, INF);
    SegmentTree<ll> segMax([](ll a, ll b) { return std::max(a, b); }, -INF);
    segMin.init(N + 5);
    segMax.init(N + 5);
    REP(i, N) {
        segMin.set(i, A[i]);
        segMax.set(i, A[i]);
    }

    ll ans = 0;
    REP(left, N) {
        if (A[left] < Y || A[left] > X)
            continue;
        ll r0 = left, ng = N;
        while (abs(r0 - ng) > 1) {
            ll mid = (r0 + ng) / 2;
            ll min = segMin.get(left, mid);
            ll max = segMax.get(left, mid);
            if (min > Y || max < X)
                r0 = mid;
            else
                ng = mid;
        }

        ll r1 = N;
        ng = left - 1;
        while (abs(r1 - ng) > 1) {
            ll mid = (r1 + ng) / 2;
            ll min = segMin.get(left, mid);
            ll max = segMax.get(left, mid);
            if (min < Y || max > X)
                r1 = mid;
            else
                ng = mid;
        }

        //cout << left << ": " << r0 << "-" << r1 << endl;
        ans += std::max(0LL, r1 - 1 - (r0 + 1) + 1);
    }

    REP(i, N) {
        if (A[i] == X && A[i] == Y)
            ans++;
    }

    cout << ans << endl;
    return 0;
}