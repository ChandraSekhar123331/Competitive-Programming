#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <algorithm>
#include <assert.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define fi first
#define sec second
#define pb push_back
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define sz(x) (int)x.size()

void solve()
{
    fio;
    int N, X;
    cin>>N>>X;
    int coins[N];
    for(int i = 0; i<N; i++) cin>>coins[i];
    const int LIM = X + 5;

    const ll MOD = 1e9 + 7;
    ll dp[LIM];
    for(int i= 0; i<LIM; i++) dp[i] = 0;
    dp[0] = 1;
    for(int i = 0; i<N; i++){
        for(int j = coins[i]; j<LIM; j++){
            dp[j] += dp[j - coins[i]];
            dp[j] %= MOD;
        }
    }
    cout<<dp[X]<<endl;

}
int main()
{
    fio;
    int test;
    // cin>>test;
    test = 1;
    for (int i = 1; i <= test; i++)
    {
        solve();
    }
    return 0;
}