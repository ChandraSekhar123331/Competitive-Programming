#include <assert.h>
#include <bits/stdc++.h>

#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;

#define endl '\n'
#define fi first
#define sec second
#define pb push_back
#define fio                                                                    \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
#define sz(x) (int)x.size()

void solve() {
    fio;
    string S;
    cin >> S;
    const int N = sz(S);
    int diff = 0;
    for (int i = 0; i < N; i += 2) {
        if (S[i] == 'A') {
            diff += S[i + 1] - '0';
        } else {
            diff -= S[i + 1] - '0';
        }
    }
    if (diff > 0) {
        cout << "A" << endl;
    } else {
        cout << "B" << endl;
    }
}
int main() {
    fio;
    int test;
    // cin >> test;
    test = 1;
    for (int i = 1; i <= test; i++) {
        solve();
    }
    return 0;
}