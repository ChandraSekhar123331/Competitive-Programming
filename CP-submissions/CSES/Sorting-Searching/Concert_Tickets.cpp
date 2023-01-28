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
    int N, M;
    cin>>N>>M;
    map<int, int> ticket_cost;
    for(int i = 0; i<N; i++){
        int price;
        cin>>price;
        ticket_cost[price]++;
    }

    for(int i = 0; i<M; i++){
        int demand;
        cin>>demand;
        auto it = ticket_cost.lower_bound(demand + 1);
        if(it == ticket_cost.begin()){cout<<-1<<endl; continue;}
        else{
            it = prev(it);
            cout<<it->first<<endl;
            it->second--;
            if(it->second == 0){
                ticket_cost.erase(it->first);
            }
        }
    }


    return;
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