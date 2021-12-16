#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>
#include <map>
#include <set>

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
    ll N;
    cin >> N;
    vector<pll> A(N);
    REP(i, N) {
        cin >> A[i].first;
    }
    REP(i, N) {
        cin >> A[i].second;
    }
    sort(A.begin(), A.end(), [](pll a, pll b) {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second > b.second;
    });
    vector<ll> v;
    REP(i, N) {
        v.push_back(A[i].second);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    SegmentTree<ll> seg([](ll a, ll b) { return a + b; }, 0);
    seg.init(v.size() + 5);
    ll ans = 0;

    std::map<ll, ll> mp;
    ll prev = 0;

    REP(i, N) {
        if (prev != A[i].first) {
            prev = A[i].first;
            for (auto n: mp) {
                ans += (n.second - 1) * n.second / 2;
            }
            mp.clear();
        }
        mp[A[i].second]++;
        ll index = lower_bound(v.begin(), v.end(), A[i].second) - v.begin();
        ll t = seg.get(index, index);
        seg.set(index, t + 1);
        ans += seg.get(index , v.size());
    }
    for (auto n: mp) {
        ans += (n.second - 1) * n.second / 2;
    }

    cout << ans << endl;
    return 0;
}