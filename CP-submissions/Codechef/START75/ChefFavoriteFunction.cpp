// Author: DCSekhara
// Date: 2023-01-26
// Time: 20:36:08.000-05:00


// Task: ChefFavoriteFunction.cpp
// Question: CP-submissions/Codechef/START75/ChefFavoriteFunction.cpp


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

int sign_dig(ll num){
    assert(num != 0); 
    for(int i = 30; i>=0; i--){
        if ((num >> i) & 1 ) return i;
    }
    assert(false);
}


ll get_f(ll num){
    ll ans = 0;
    for(int i = sign_dig(num); i>=0; i--){
        if((num>>i) & 1) continue;
        else ans++;
    }
    return ans;
}

ll get_g(ll num){
    ll dig = sign_dig(num);
    ll ans = 1ll << dig;
    for(int i = dig - 1; i>=0; i--){
        if((num>>i) &1 ) continue;
        else ans += 1ll<<i;
        
    }
    return ans;
}


void solve()
{
    // cout<<get_g(1)<<endl;
    // cout<<get_g(2)<<endl;
    // cout<<get_g(3)<<endl;
    // cout<<get_g(4)<<endl;
    fio;
    ll L, R;
    cin>>L>>R;

    ll ans = 0;

    if(sign_dig(L) != sign_dig(R)){
        ans = sign_dig(R);
        ans += (1ll<<(sign_dig(R) + 1)) - 1;
        cout<<ans<<endl;
        return;
    }
    else{
        for(int i = L; i<= L  + 30 && i<=R; i++){
            ans = max(ans, get_f(i) + get_g(i));
        }
        cout<<ans<<endl;
        return;
    }

    // for(int i = 30; i>=0; i--){
    //     ll den = 1ll << i;
    //     ll left = (L + den - 1) / den;
    //     ll right = (R) / den;
    //     if(left%2 == 0) left++;
    //     if(right%2 == 0) right--;
    //     if(left  > right) continue;
    //     // if(left == right && left%2 == 0) continue;
    //     else{
    //         ll fval = i;
    //         ll gval;
    //         // cout<<left<<" "<<right<<endl;
    //         if(sign_dig(left) == sign_dig(right)){
    //             assert(left & 1);
    //             gval = get_g(left * den);

    //         }
    //         else{
    //             gval = get_g(((1ll<<(sign_dig(right))) + 1) * den);
    //         }

    //         ans = max(ans, gval + fval);
    //         // cout<<i<<" "<<fval<<" "<<gval<<" "<<fval + gval <<endl;
    //     }
    // }
    // cout<<ans<<endl;

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