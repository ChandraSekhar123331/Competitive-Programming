// Author: DCSekhara
// Date: 2023-01-26
// Time: 20:18:52.000-05:00


// Task: EqualHammingDistance.cpp
// Question: CP-submissions/Codechef/START75/EqualHammingDistance.cpp


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


const ll LIM = 2e5 + 100;
ll fact[LIM];
const ll MOD = 1e9 + 7;

void fill_fact(){
    fact[0] = 1;
    for(int i = 1; i<LIM; i++){
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
    return;
}



ll power(ll base, ll exp){
    if(exp == 0) return 1;
    if(exp == 1) return base % MOD;

    ll ans = power(base, exp>>1);
    ans *= ans;
    ans %= MOD;
    if(exp & 1) ans *= base;
    ans %= MOD;
    return ans;
}


ll inverse(ll base){
    return power(base, MOD - 2);
}

ll choose(ll a, ll b){
    if(a == 0) return 1;
    assert(a%2 == 0);
    assert(2 *b == a);
    ll answer = fact[a];
    answer *= inverse(fact[b]);
    answer %= MOD;
    answer *= inverse(fact[b]);
    answer %= MOD;
    return answer;

}

void solve()
{
    fio;
    int N;
    cin>>N;
    string A, B;
    cin>>A>>B;
    int common = 0;
    for(int i = 0; i<N; i++){
        common += A[i] == B[i];
    }
    int diff = N - common;
    if(diff & 1){
        cout<<0<<endl;
        return;
    }

    ll answer = power(2, common);
    answer *= choose(diff, diff / 2);

    answer %= MOD;
    cout<<answer<<endl;
    return;


}
int main()
{
    fio;

    int test;
    cin>>test;
    fill_fact();
    // test = 1;
    for (int i = 1; i <= test; i++)
    {
        solve();
    }
    return 0;
}