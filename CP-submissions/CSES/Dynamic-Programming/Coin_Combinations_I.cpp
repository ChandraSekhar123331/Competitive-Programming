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
    int coin[N];
    for(int i = 0; i<N; i++) cin>>coin[i];
    const int MOD = 1e9 + 7;
    const int LIM = X + 5;
    ll ct[LIM];
    for(int i = 0; i<LIM; i++) ct[i] = 0;
    ct[0] = 1;
    for(int i = 1; i<LIM; i++){
        for(int j = 0; j<N; j++){
            if(i >= coin[j])ct[i] += ct[i - coin[j]];
            ct[i]%=MOD;
        }
    }
    cout<<ct[X]<<endl;


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