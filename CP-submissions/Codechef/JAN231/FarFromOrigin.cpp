// Author: DCSekhara
// Date: 2023-01-15
// Time: 21:08:28.000-05:00


// Task: FarFromOrigin.cpp
// Question: CP-submissions/Codechef/JAN231/FarFromOrigin.cpp


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
    int d[2];
    for(int i = 0; i<2; i++){
        int X, Y;
        cin>>X>>Y;
        d[i] = X * X + Y * Y;
    }
    if(d[0] > d[1]){cout<<"ALEX"<<endl;return;}
    else if(d[0] < d[1]){cout<<"BOB"<<endl; return;}
    else cout<<"EQUAL"<<endl;
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