// Author: DCSekhara
// Date: 2023-01-20
// Time: 20:26:21.000-05:00


// Task: EvenDigits.cpp
// Question: CP-submissions/Google/2018/KickStart/Round-A/EvenDigits.cpp


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
    string S;
    cin>>S;
    const int N = sz(S);
    ll ans = 0;
    int pos = -1;
    for(int i = 0; i<N; i++){
        int dig = S[i] - '0';
        if(dig & 1){pos=i;break;}
    }
    if(pos == -1){ cout<<0<<endl; return;}
    ll dist = 1e18;
    if(S[pos]!='9') {
        string cand = S;
        cand[pos] = S[pos] + 1;
        for(int i = pos + 1; i<N; i++){
            cand[i] = '0';
        }
        dist = min(dist, abs(stoll(cand) - stoll(S)));
    }

    {
        string cand = S;
        cand[pos] = S[pos] - 1;
        for(int i = pos + 1; i<N; i++){
            cand[i] = '8';
        }
        dist = min(dist, abs(stoll(cand) - stoll(S)));
    }
    cout<<dist<<endl;



    
}
int main()
{
    fio;
    int test;
    cin>>test;
    // test = 1;
    for (int i = 1; i <= test; i++)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}