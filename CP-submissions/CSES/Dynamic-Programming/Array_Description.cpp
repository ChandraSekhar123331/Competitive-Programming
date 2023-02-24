#include <algorithm>
#include <assert.h>
#include <bitset>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;

#define endl '\n'
#define fi first
#define sec second
#define pb push_back
#define fio                                                                    \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
#define sz(x) (int)x.size()

void solve() {
    fio;
    int N, M;
    cin >> N >> M;
    const ll MOD = 1e9 + 7;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    ll dp[N][M];
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < M; j++) {
            // dp[i][j] = 0;
            if (arr[i] != 0) {
                dp[i][j] = 0;
                if (arr[i] == j + 1) {
                    if (i + 1 < N) {
                        dp[i][j] += dp[i + 1][j];
                        if (j + 1 < M)
                            dp[i][j] += dp[i + 1][j + 1];
                        if (j - 1 >= 0)
                            dp[i][j] += dp[i + 1][j - 1];
                    } else
                        dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
            } else {
                dp[i][j] = 0;
                if (i + 1 == N) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] += dp[i + 1][j];
                    if (j + 1 < M) {
                        dp[i][j] += dp[i + 1][j + 1];
                    }
                    if (j - 1 >= 0) {
                        dp[i][j] += dp[i + 1][j - 1];
                    }
                }
            }
            dp[i][j] %= MOD;
        }
    }

    ll ans = 0;
    for (int j = 0; j < M; j++)
        ans += dp[0][j];
    ans %= MOD;
    cout << ans << endl;
}
int main() {
    fio;
    int test;
    // cin >> test;
    test = 1;
    for (int i = 1; i <= test; i++) {
        solve();
    }
    return 0;
}