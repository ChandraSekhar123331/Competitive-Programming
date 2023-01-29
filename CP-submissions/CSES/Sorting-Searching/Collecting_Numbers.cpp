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
    int arr[N];
    for(int i = 0; i<N; i++) cin>>arr[i];
    int pos[N];
    for(int i = 0; i<N; i++){
        pos[arr[i] - 1] = i;
    }
    ll ans = 0;
    for(int i = 0; i + 1<N; i++){
        ans += pos[i + 1] < pos[i];
    }
    cout<<ans + 1<<endl;
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