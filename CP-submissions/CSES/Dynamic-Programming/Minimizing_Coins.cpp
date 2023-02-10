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
    int n, x;
    cin>>n>>x;
    int coin[n];
    for(int i = 0; i<n; i++) cin>>coin[i];
    const int LIM = 1e6 + 5;
    vector<int> reqd(LIM, 1e9 + 5);
    reqd[0] = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<LIM; j++){
            if(j + coin[i] < LIM) reqd[j + coin[i]] = min(reqd[j + coin[i]], 1 + reqd[j]);
        }      
    }

    if(reqd[x] < 1e9){
        cout<<reqd[x]<<endl;
    }
    else{
        cout<<-1<<endl;
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