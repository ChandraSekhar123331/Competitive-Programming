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
    int price[N];
    int pages[N];
    for(int i = 0; i<N; i++) cin>>price[i];
    for(int i = 0; i<N; i++) cin>>pages[i];
    const int LIM = X + 5;
    ll dp[LIM];
    std::fill(&dp[0], &dp[LIM -1], 0ll);
    for(int i = 0; i<N; i++){
        for(int j = LIM - 1; j>=0; j--){
            if(j + price[i] < LIM && dp[j] != -1) dp[j + price[i]] = max(dp[j + price[i]], dp[j] + pages[i]);
        }
    }
    if(dp[X] != -1){
        cout<<dp[X]<<endl;
    }
    else{
        cout<<0<<endl;
    }
    

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