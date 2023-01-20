// Author: DCSekhara
// Date: 2023-01-15
// Time: 21:35:37.000-05:00


// Task: MinimizeTheMaximum.cpp
// Question: CP-submissions/Codechef/JAN231/MinimizeTheMaximum.cpp


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
    vector<int> arr(N);
    for(int i = 0; i<N; i++) cin>>arr[i];
    // Idea is to do binary search over the answer!
    ll lt = 1e9 + 10;
    ll rt = 0;
    for(ll elem: arr) {
        rt = max(rt, elem);
        lt = min(lt, elem);
    }
    ll ans = rt;
    while(lt<=rt){
        ll mid = lt + (rt - lt) / 2;
        vector<ll> temp(N);
        for(int i = 0; i<N; i++){temp[i] = arr[i];}
        for(int i = N - 1; i > 0; i--){
            if(temp[i] <= mid) continue;
            else if(temp[i] > mid) {
                ll extra = temp[i] - mid;
                temp[i] -= extra;
                temp[i-1] += extra;
            }
            // else if(temp[i] == mid) continue;
            // else{
            //     ll diff = mid - temp[i];
            //     ll avail = temp[i + 1];
            //     // We greedily transfer the required amount from temp[i+1] to temp[i]
            //     ll greedy_val = min(diff, avail);
            //     temp[i] += greedy_val;
            //     temp[i+1] -= greedy_val;
            // }
        }
        ll current_max = 0;
        for(ll elem: temp) current_max = max(current_max, elem);
        ans = min(ans, current_max);
        if(current_max < mid){
            rt = current_max - 1;
        }
        else if(current_max == mid){
            rt = current_max - 1;
        }
        else{
            lt = mid + 1;
        }
    }
    cout<<ans<<endl;
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