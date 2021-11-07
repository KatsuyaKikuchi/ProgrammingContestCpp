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
const ll INF = (ll) 1e18;
const long double PI = 3.1415926535897932384626433832795028841971;

ll test(vector<ll> A, ll K) {
    ll ret = 0;
    REP(k, K + 1) {
        ll s = 0;
        REP(i, A.size()) {
            s += (A[i] ^ k);
        }
        ret = std::max(ret, s);
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

#if true
    {
        ll N, K;
        cin >> N >> K;
        vector<ll> A(N);
        REP(i, N) {
            cin >> A[i];
        }
#else
        ll K = 0;
        while (true) {
            K++;
            ll N;
            N = 5;

            //cin >> N >> K;
            vector<ll> A(N);
            REP(i, N) {
                A[i] = i * i;
                //  cin >> A[i];
            }
#endif


        vector<ll> ans(2, 0);
        ans[1] = -INF;
        ll MAX = 60;
        REP(b, MAX + 1) {
            ll bit = (1LL << (MAX - b));
            vector<ll> tmp(2);
            vector<ll> sum(2, 0);
            REP(i, N) {
                if ((A[i] & bit) > 0) {
                    sum[0] += bit;
                } else {
                    sum[1] += bit;
                }
            }

            if (K < bit) {
                sum[1] = 0;
            }
            if ((K & bit) > 0) {
                tmp[0] = ans[0] + sum[1];
                tmp[1] = std::max(ans[1] + std::max(sum[0], sum[1]), ans[0] + sum[0]);
            } else {
                tmp[0] = ans[0] + sum[0];
                tmp[1] = ans[1] + std::max(sum[0], sum[1]);
            }
            swap(ans, tmp);
        }

        ll ret = std::max(ans[0], ans[1]);
#if false
        if (ret != test(A, K)) {
            REP(i, N) {
                cout << A[i] << " ";
            }
            cout << endl;
            cout << K << endl;
            cout << ret << " " << test(A, K) << endl;
            break;
        }
#else
        cout << ret << endl;
#endif
    }

    return 0;
}