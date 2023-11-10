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

ll dfs(vector<ll> &A, ll left, ll right, ll value, bool used = false, ll ret = INF) {
    while (true) {
        if (ret == 0) {
            return INF;
        }
        if (left > right) {
            return ret;
        }
        if (left == right && !used) {
            return abs(value - A[right]);
        }
        if (A[right] + A[left] == value) {
            right--;
            left++;
            continue;
        }
        if (used) {
            return INF;
        }
        break;
    }
    ll a = dfs(A, left + 1, right, value, true, abs(value - A[left]));
    ll b = dfs(A, left, right - 1, value, true, abs(value - A[right]));
    return std::min(a, b);
}

ll solver(vector<ll> &A) {
    ll N = A.size();
    sort(A.begin(), A.end());
    if (N == 1) {
        return A[0];
    }
    ll a = dfs(A, 0, N - 1, A[0] + A[N - 1]);
    ll b = dfs(A, 1, N - 1, A[1] + A[N - 1], true, abs(A[1] + A[N - 1] - A[0]));
    ll c = dfs(A, 0, N - 2, A[0] + A[N - 2], true, abs(A[0] + A[N - 2] - A[N - 1]));
    ll ret = std::min({a, b, c});
    if (ret == INF)
        return -1;
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string inputFileName = "../FacebookHackerCup/2023/Practice/Input/C.txt";
    ifstream rs;
    rs.open(inputFileName);

    string outputFileName = "../FacebookHackerCup/2023/Practice/Output/C_out.txt";
    ofstream ws;
    ws.open(outputFileName, std::ios::out);

    ll T;
    rs >> T;
    REP(i, T) {
        ll N;
        rs >> N;
        vector<ll> A(2 * N - 1);
        REP(j, 2 * N - 1) {
            rs >> A[j];
        }
        ws << "Case #" << i + 1 << ": ";
        ws << solver(A) << endl;
    }
    return 0;
}