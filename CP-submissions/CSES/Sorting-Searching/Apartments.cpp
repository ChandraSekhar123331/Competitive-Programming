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
    int n, m, k;
    cin>>n>>m>>k;
    int desired_ht[n];
    for(int i = 0; i<n; i++) cin>>desired_ht[i];
    int hts[m];
    for(int i = 0; i<m; i++) cin>>hts[i];


    sort(desired_ht, desired_ht + n);
    sort(hts, hts + m);

    //
    int num_alloc = 0;
    int building_ptr = 0;
    for(int i = 0; i<n && building_ptr < m; i++){
        if(hts[building_ptr]>= desired_ht[i] - k && hts[building_ptr] <= desired_ht[i] + k){
            num_alloc++;
            building_ptr++;
        }
        else if(hts[building_ptr] < desired_ht[i] - k){building_ptr++; i--; continue;}
        else{
            continue;
        }
    }

    cout<<num_alloc<<endl;

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