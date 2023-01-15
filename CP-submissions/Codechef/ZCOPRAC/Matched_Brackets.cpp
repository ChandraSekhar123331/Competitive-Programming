// Author: DCSekhara
// Date: 2023-01-14
// Time: 17:55:22.000-05:00


// Task: Matched_Brackets.cpp
// Question: CP-submissions/Codechef/ZCOPRAC/Matched_Brackets.cpp


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

// #define endl '\n'
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
    for(int i = 0; i<N; i++){
        int code;
        cin>>code;
        if(code == 1) S.push_back('(');
        else S.push_back(')');
    }
    // cout<<S<<endl;
    int max_depth = 0;
    int max_depth_ind = -1;
    int max_diff = 0;
    int max_diff_ind = -1;
    vector<int> inds;
    int curr_depth = 0;
    for(int i = 0; i<N; i++){
        if(S[i] == '('){
            curr_depth++;
            if(curr_depth > max_depth) {max_depth = curr_depth; max_depth_ind = i;}
            inds.push_back(i);
        }
        else{
            curr_depth--;
            assert(!inds.empty());
            int curr_diff = i - inds.back();
            if(curr_diff > max_diff){
                max_diff = curr_diff;
                max_diff_ind = inds.back();
            }
            inds.pop_back();
        }
    }
    cout<<max_depth<<" "<<1 + max_depth_ind<<" "<<max_diff + 1<<" "<< 1 + max_diff_ind <<endl;   
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