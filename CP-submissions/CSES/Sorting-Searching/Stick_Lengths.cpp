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
    int lengths[N];
    for(int i = 0; i<N; i++) cin>>lengths[i];
    sort(lengths, lengths + N);
    // optimal final_length will just be the median
    int final_length;
    if(N&1){
        final_length = lengths[(N - 1) / 2];
    }
    else{
        final_length = lengths[N  / 2 - 1];
    }
    ll ans = 0;
    for(int i = 0; i<N; i++) ans += abs(final_length - lengths[i]);
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