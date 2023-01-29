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
    int N, X;
    cin>>N>>X;
    set<int> vals;
    map<int, int> posn;
    pair<int, int> ans = {-1, -1};
    for(int i = 0; i<N; i++){
        int num;
        cin>>num;
        ll req = X - num;
        if(vals.find(req) != vals.end()){
            ans = {i + 1, posn[req] + 1};
        }
        vals.insert(num);
        posn[num] = i;
    }

    if(ans == make_pair(-1, -1)){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<ans.first<<" "<<ans.second<<endl;
    }
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