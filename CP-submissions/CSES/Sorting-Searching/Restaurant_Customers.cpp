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
    vector<pair<int, int>> event_list;
    for(int i = 0; i<N; i++){
        int start, end;
        cin>>start>>end;
        event_list.push_back({start, 1});
        event_list.push_back({end, -1});
    }
    sort(event_list.begin(), event_list.end());
    int cumm_sum = 0;
    int max_cumm_sum = 0;
    for(auto &event: event_list){
        cumm_sum += event.second;
        max_cumm_sum = max(max_cumm_sum, cumm_sum);
    }
    cout<<max_cumm_sum<<endl;
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