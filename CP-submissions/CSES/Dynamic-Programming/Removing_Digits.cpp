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
#include<cstring>
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


vector<int> get_dig(int num){
    vector<int> ans;
    while(num!=0) {ans.push_back(num%10); num/=10;}
    return ans;
}


void solve()
{
    fio;
    int N;
    cin>>N;
    const int LIM = N + 5;
    int dp[LIM];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    for(int i = 1; i<LIM; i++){
        dp[i] = i;
        for(auto &dig: get_dig(i)){
            dp[i] = min(dp[i], 1 + dp[i - dig]);
        }
    }

    cout<<dp[N]<<endl;

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