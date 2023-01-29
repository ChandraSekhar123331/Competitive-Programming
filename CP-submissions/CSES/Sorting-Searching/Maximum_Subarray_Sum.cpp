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
    int N;
    cin>>N;
    ll vals[N];
    for(int i = 0; i<N; i++) cin>>vals[i];
    ll cumm_sum = 0;
    ll curr_min = 0;
    ll max_sub = -1e18;
    for(int i = 0; i<N; i++){
        cumm_sum += vals[i];
        max_sub = max(max_sub, cumm_sum - curr_min);
        curr_min = min(curr_min, cumm_sum);
    }
    cout<<max_sub<<endl;
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