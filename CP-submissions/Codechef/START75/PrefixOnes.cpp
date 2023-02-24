// Author: DCSekhara
// Date: 2023-01-26
// Time: 20:06:37.000-05:00


// Task: PrefixOnes.cpp
// Question: CP-submissions/Codechef/START75/PrefixOnes.cpp


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


int get_max_substr(string &s){
    const int N = sz(s);
    if(N == 0) return 0;
    int dp[N + 1];
    dp[0] = 0;
    int ans = 0;
    for(int i = 1; i<=N; i++){
        if(s[i - 1] == '0') dp[i] = 0;
        else {
            dp[i] = 1 + dp[i - 1];
            ans = max(ans, dp[i]);
        }
    }
    return ans;
}

void solve()
{
    fio;
    int N;
    cin>>N;
    string S;
    cin>>S;
    reverse(S.begin(), S.end());
    int ans = 0;
    while(!S.empty()){
        if(S.back() == '1') {ans++; S.pop_back();}
        else break;
    }

    cout<<ans + get_max_substr(S)<<endl;

}
int main()
{
    fio;
    int test;
    cin>>test;
    // test = 1;
    for (int i = 1; i <= test; i++)
    {
        solve();
    }
    return 0;
}