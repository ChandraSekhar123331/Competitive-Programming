#include <assert.h>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using ll = long long;
using db = double;
using str = string;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<db, db>;

#define mp make_pair
#define MP make_pair
#define mt make_tuple
#define MT make_tuple

using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vd = vector<db>;
using vstr = vector<str>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdd = vector<pdd>;

#define sz(x) (int)x.size()
#define len(x) (int)x.size()
#define deb(x) cout << "DEBUG: " << #x << " " << x << endl;
#define debvec(x)                                                              \
    cout << "DEBUG: " << #x << endl;                                           \
    for (ll i = 0; i < sz(x); i++)                                             \
        cout << "Index: " << i << " " << x[i] << endl;

#define debarr(x, n)                                                           \
    cout << "DEBUG: " << #x << endl;                                           \
    for (ll i = 0; i < n; i++)                                                 \
        cout << "Index: " << i << " " << x[i] << endl;

#define debmap(x)                                                              \
    cout << "DEBUG: " << #x << endl;                                           \
    for (auto &elem : x)                                                       \
        cout << "Key: " << elem.first << ": \t Value = " << elem.second << endl;

#define debset(x)                                                              \
    cout << "DEBUG: " << #x << endl;                                           \
    for (auto &elem : x)                                                       \
        cout << elem << endl;

#define fi first
#define sec second
#define ins insert

// #define FIO
#define SINGLE_TEST
// #define MULTIPLE_TEST

#define INTERACTIVE

// #define GCJ_TEST

#ifdef FIO
#define fio                                                                    \
    cin.tie(NULL);                                                             \
    ios::sync_with_stdio(false);                                               \
    cout.tie(NULL);
#define endl '\n'
#define ENDL '\n'
#define Endl '\n'
#elif defined(INTERACTIVE)
#define fio cin.tie(NULL);
#else
#define fio 0;
#endif

#ifdef MULTIPLE_TEST
#define TEST_LOOP                                                              \
    int test;                                                                  \
    cin >> test;                                                               \
    for (int i = 0; i < test; i++) {                                           \
        solve();                                                               \
    }
#elif defined(SINGLE_TEST)
#define TEST_LOOP                                                              \
    int test = 1;                                                              \
    for (int i = 0; i < test; i++) {                                           \
        solve();                                                               \
    }
#elif defined(GCJ_TEST)
#define TEST_LOOP                                                              \
    int test;                                                                  \
    cin >> test;                                                               \
    for (int i = 1; i <= test; i++) {                                          \
        cout << "Case #" << i << ": ";                                         \
        solve();                                                               \
    }
#else
#define TEST_LOOP 0;
#endif

void solve() {
    string S;
    cin >> S;
    ll ans = 0;
    for (int i = 0; i < len(S); i++) {
        ans *= 26;
        ans += S[i] - 'A' + 1;
    }
    cout << ans << endl;
}

int main() {
    fio;
    TEST_LOOP;
}