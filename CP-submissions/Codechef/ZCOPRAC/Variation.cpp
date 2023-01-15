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
    int N, K;
    cin>>N>>K;
    vector<int> arr(N);
    for(int i = 0; i<N; i++) cin>>arr[i];
    sort(arr.begin(), arr.end());
    ll ans = 0;
    for(int i = 0; i<N; i++){
        int target = arr[i] - K;
        auto it = lower_bound(arr.begin(), arr.end(), target + 1);
        assert(it!=arr.end());
        int index = it - arr.begin();
        ans += index;
    }
    cout<<ans<<endl;
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