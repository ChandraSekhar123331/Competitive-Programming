// Author: DCSekhara
// Date: 2023-01-15
// Time: 21:06:04.000-05:00


// Task: NegativeProduct.cpp
// Question: CP-submissions/Codechef/JAN231/NegativeProduct.cpp


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
    int A, B, C;
    cin>>A>>B>>C;
    if(A * B < 0){cout<<"YES"<<endl; return;}
    if(B * C < 0){cout<<"YES"<<endl; return;}
    if(C * A < 0){cout<<"YES"<<endl; return;}
    cout<<"NO"<<endl;
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