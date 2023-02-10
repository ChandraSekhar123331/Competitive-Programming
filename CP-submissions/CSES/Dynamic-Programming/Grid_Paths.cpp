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
    const ll MOD = 1e9 + 7;
    char status[N][N];
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++) cin>> status[i][j];
    }
    ll ct[N][N];
    std::fill(&ct[0][0], &ct[N - 1][N - 1], 0ll);
    ct[N - 1][N - 1] = 1;
    for(int i = N -1; i>=0; i--){
        for(int j = N - 1; j>=0; j--){
            if(status[i][j] == '*') ct[i][j] = 0;
            else{
                if(i + 1<N) ct[i][j] += ct[i + 1][j];
                if(j + 1<N) ct[i][j] += ct[i][j + 1];
                ct[i][j] %= MOD;
                // cout<<i << " "<<j<<" "<<ct[i][j]<<endl;
            }
        }
    }
    cout<<ct[0][0]<<endl;
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