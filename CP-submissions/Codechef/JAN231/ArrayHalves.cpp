// Author: DCSekhara
// Date: 2023-01-15
// Time: 21:17:11.000-05:00


// Task: ArrayHalves.cpp
// Question: CP-submissions/Codechef/JAN231/ArrayHalves.cpp


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
    vector<int> arr( 2 * N);
    for(int i = 0; i < 2 * N; i++) cin>>arr[i];
    int left_ct = 0;
    int right_ct = 0;
    ll ans = 0;
    for(int i = N - 1; i>=0; i--){
        if(arr[i]>N){
            left_ct++;
            // move it from i to N - left_ct;
            ans += N - left_ct - i;
        }
    }
    for(int i = N; i<2*N; i++){
        if(arr[i]<=N){
            right_ct++;
            // move it from i to N - 1 + right_ct;
            ans += i - (N - 1 + right_ct);
        }
    }
    assert(left_ct == right_ct);
    // To swap the elements at the border
    ans += 1ll * left_ct * left_ct;
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