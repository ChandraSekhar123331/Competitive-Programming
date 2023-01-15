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
// #define fio                           \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL);                    \
//     cout.tie(NULL);
#define sz(x) (int)x.size()

void solve()
{
    // fio;
    int N;
    cin>>N;
    vector<int> arr(N);
    for(int i = 0; i<N; i++){
        cin>>arr[i];
    }
    ll ans = 0;
    sort(arr.begin(), arr.end());
    for(int i = N - 1; i>=0; i--){
        ans = max(ans, 1ll * arr[i] * (N - i));
    }
    cout<<ans<<endl;

    
}
int main()
{
    // fio;
    int test;
    // cin>>test;
    test = 1;
    for (int i = 1; i <= test; i++)
    {
        solve();
    }
    return 0;
}