// Author: DCSekhara
// Date: 2023-01-26
// Time: 20:01:18.000-05:00


// Task: ThreePowersofTwo.cpp
// Question: CP-submissions/Codechef/START75/ThreePowersofTwo.cpp


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
    string S;
    cin>>S;
    int ct = 0;
    for(int i = 0; i<N; i++) { ct += S[i] == '1';}
    if(ct == 2 || ct == 3){
        cout<<"YES"<<endl;
    }
    else if(ct == 1){
        if(N<2) {cout<<"NO"<<endl;}
        else if(S[N - 1] == '1' || S[N - 2] == '1') {cout<<"NO"<<endl;}
        else cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return;
    
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