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
    ll arr[N];
    for(int i = 0; i<N; i++) cin >> arr[i];
    sort(arr, arr + N);
    ll left = 0;
    ll right = 0;
    for(int i = 0; i<N; i++){
        ll new_left = left + arr[i];
        if(new_left <= right + 1){
            right = right + arr[i];
            continue;
        }
        else{
            cout<<right + 1<<endl;
            return;
        }
    }
    cout<<right + 1<<endl;

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