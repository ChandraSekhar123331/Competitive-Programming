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
    vector<pair<int, int>> intervals(N);
    for(int i = 0; i<N; i++){
        // Since we need to sort by increasing order of end-time
        // and then do greedy.
        cin>>intervals[i].second>>intervals[i].first;
    }
    sort(intervals.begin(), intervals.end());
    int ans = 0;
    int curr_end = -1;
    for(int i = 0; i<N; i++){
        if(intervals[i].second >= curr_end){
            ans++;
            curr_end = intervals[i].first;
        }
        else{
            continue;
        }
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