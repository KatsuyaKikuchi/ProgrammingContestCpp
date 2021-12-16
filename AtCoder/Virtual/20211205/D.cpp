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

ll N, K;
vector<ll> A, S;

bool check(ll m) {
    ll sum = 0;
    ll s = 0;
    SegmentTree<ll> seg([](ll a, ll b) { return a + b; }, 0);
    seg.init(S.size() + 5);
    ll z = lower_bound(S.begin(), S.end(), 0) - S.begin();
    seg.set(z, 1);
    REP(i, N) {
        s += A[i];
        ll b = s - m;
        ll t = s + m;
        auto bidx = upper_bound(S.begin(), S.end(), b) - S.begin();
        auto tidx = lower_bound(S.begin(), S.end(), t) - S.begin();
        sum += seg.get(bidx, tidx);
        ll index = lower_bound(S.begin(), S.end(), s) - S.begin();
        ll x = seg.get(index, index);
        seg.set(index, x + 1);
    }
    return sum <= K;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    A.resize(N);
    REP(i, N) {
        cin >> A[i];
    }
    ll s = 0;
    S.resize(1, 0);
    REP(i, N) {
        s += A[i];
        S.push_back(s);
    }
    sort(S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());

    ll ans = 0, ng = INF;
    while (abs(ans - ng) > 1) {
        ll mid = (ans + ng) / 2;
        if (check(mid))
            ans = mid;
        else
            ng = mid;
    }
    cout << ans << endl;
    return 0;
}