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

struct Query {
    pll t;
    ll index;
};

template<typename T>
struct SegmentTree {
    using F = function<T(T, T)>;

    SegmentTree(F func, T id)
            : merge(func), identity(id) {}

    void init(ll n) {
        offset = 1;
        while (offset < n)
            offset <<= 1;
        node.assign(offset << 1, identity);
    }

    void build(const vector<T> &v) {
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
    vector<T> node;
    int offset;
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    vector<ll> C(N);
    REP(i, N) {
        cin >> C[i];
        C[i]--;
    }
    vector<Query> A(Q);
    REP(i, Q) {
        cin >> A[i].t.first >> A[i].t.second;
        A[i].index = i;
        A[i].t.first--;
        A[i].t.second--;
    }
    sort(A.begin(), A.end(), [](Query a, Query b) {
        if (a.t.second == b.t.second)
            return a.t.first < b.t.first;
        return a.t.second < b.t.second;
    });

    SegmentTree<ll> seg([](ll a, ll b) { return a + b; }, 0);
    seg.init(N + 10);

    vector<ll> ans(Q);
    ll index = 0;
    ll count = 0;
    vector<ll> U(N, -1);
    REP(i, N) {
        if (U[C[i]] == -1) {
            count++;
        } else {
            ll n = U[C[i]];
            ll t = seg.get(n, n);
            seg.set(n, t - 1);
        }
        U[C[i]] = i;
        {
            ll n = U[C[i]];
            ll t = seg.get(n, n);
            seg.set(n, t + 1);
        }
        while (index < Q && A[index].t.second == i) {
            ans[A[index].index] = count - seg.get(0, A[index].t.first - 1);
            index++;
        }
    }
    REP(i, Q) {
        cout << ans[i] << endl;
    }
    return 0;
}