// Author: DCSekhara
// Date: 2023-01-15
// Time: 21:13:37.000-05:00


// Task: AsymmetricSwaps.cpp
// Question: CP-submissions/Codechef/JAN231/AsymmetricSwaps.cpp


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
    vector<int> arr(2 * N);
    for(int i = 0; i< 2 *N; i++){
        int num;
        cin>>num;
        arr[i] = num;
    }
    sort(arr.begin(), arr.end());
    int ans = INT32_MAX;
    for(int i = 0; i<=N; i++){
        ans = min(ans, arr[i + N -1] - arr[i]);
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