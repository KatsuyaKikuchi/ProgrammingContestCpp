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

struct Data {
    ll origin_index;
    ll value;
    ll color;
};

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
    ll N;
    cin >> N;
    vector<Data> C(N);
    vector<ll> v;
    REP(i, N) {
        cin >> C[i].color;
        v.push_back(C[i].color);
    }
    vector<ll> X(N);
    REP(i, N) {
        cin >> C[i].value;
        C[i].origin_index = i;
    }

    ll ans = 0;
    {
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        vector<vector<ll>> V(v.size());
        REP(i, N) {
            ll index = lower_bound(v.begin(), v.end(), C[i].color) - v.begin();
            V[index].push_back(C[i].value);
        }

        REP(i, V.size()) {
            SegmentTree<ll> seg([](ll a, ll b) { return a + b; }, 0);
            ll n = V[i].size() + 3;
            seg.init(n);

            vector<ll> t;
            REP(j, V[i].size()) {
                t.push_back(V[i][j]);
            }
            sort(t.begin(), t.end());
            t.erase(unique(t.begin(), t.end()), t.end());

            REP(j, V[i].size()) {
                ll index = lower_bound(t.begin(), t.end(), V[i][j]) - t.begin();
                ans -= seg.get(index + 1, n - 1);
                ll x = seg.get(index, index);
                seg.set(index, x + 1);
            }

        }
    }

    {
        sort(C.begin(), C.end(), [](Data a, Data b) {
            if (a.value == b.value) {
                return a.origin_index < b.origin_index;
            }
            return a.value < b.value;
        });

        SegmentTree<ll> seg([](ll a, ll b) { return a + b; }, 0);
        seg.init(N + 5);

        REP(i, N) {
            ll c = seg.get(0, C[i].origin_index);
            ans += C[i].origin_index - c;
            seg.set(C[i].origin_index, 1);
        }
    }

    cout << ans << endl;

    return 0;
}