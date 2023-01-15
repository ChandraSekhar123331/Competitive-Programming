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
    int N, H;
    cin>>N>>H;
    ll arr[N];
    for(int i = 0; i<N; i++) cin>>arr[i];
    bool loaded = false;
    int curr_ind = 0;
    while(true){
        int code;
        cin>>code;
        if(code == 0) break;
        if(code == 1 && curr_ind > 0)curr_ind --;
        else if(code == 2 && curr_ind != N - 1) curr_ind++;
        else if(code == 3 && !loaded && arr[curr_ind] > 0){loaded = true; arr[curr_ind]--;}
        else if(code == 4 && loaded && arr[curr_ind] <H){loaded = false; arr[curr_ind]++;}
    }
    for(int i = 0; i<N; i++) cout<<arr[i]<<" ";
    cout<<endl;
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