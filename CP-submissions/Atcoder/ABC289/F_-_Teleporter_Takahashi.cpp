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

#define FIO
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
    pair<ll, ll> s, t;
    cin >> s.first >> s.second;
    cin >> t.first >> t.second;
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    const ll LIM = 1000000;
    {
        // check for the case after even number of steps.
        pair<ll, ll> diff;
        diff.first = t.first - s.first;
        diff.second = t.second - s.second;
        if (abs(diff.first) % 2 == 0 && abs(diff.second) % 2 == 0) {
            pair<ll, ll> xlims = {-1ll * (LIM) / 2 * (b - a),
                                  1ll * (LIM) / 2 * (b - a)};
            pair<ll, ll> ylims = {-1ll * (LIM) / 2 * (d - c),
                                  1ll * (LIM) / 2 * (d - c)};

            pair<ll, ll> req = {diff.first / 2, diff.second / 2};
            if (req.first >= xlims.first && req.first <= xlims.second &&
                req.second >= ylims.first && req.second <= ylims.second) {
                cout << "Yes" << endl;
                while (req.first != 0 || req.second != 0) {
                    pair<ll, ll> xs;
                    pair<ll, ll> ys;
                    ll val = req.first;
                    if (abs(val) >= b - a) {
                        if (val >= 0) {
                            xs.first = a;
                            xs.second = b;
                        } else {
                            xs.first = b;
                            xs.second = a;
                        }
                    } else {
                        if (val >= 0) {
                            xs.first = a;
                            xs.second = xs.first + val;
                        } else {
                            xs.second = a;
                            xs.first = xs.second - val;
                        }
                    }
                    req.first -= xs.second - xs.first;

                    val = req.second;
                    if (abs(val) >= d - c) {
                        if (val >= 0) {
                            ys.first = c;
                            ys.second = d;
                        } else {
                            ys.first = d;
                            ys.second = c;
                        }
                    } else {
                        if (val >= 0) {
                            ys.first = c;
                            ys.second = ys.first + val;
                        } else {
                            ys.second = c;
                            ys.first = ys.second - val;
                        }
                    }
                    req.second -= ys.second - ys.first;

                    cout << xs.first << " " << ys.first << endl;
                    cout << xs.second << " " << ys.second << endl;
                }
                return;
            }
        }
    }

    {
        pair<ll, ll> diff;
        diff.first = t.first + s.first;
        diff.second = t.second + s.second;
        if (abs(diff.first) % 2 == 0 && abs(diff.second) % 2 == 0) {
            pair<ll, ll> xlims = {-1ll * (LIM - 1) / 2 * (b - a) + a,
                                  1ll * (LIM - 1) / 2 * (b - a) + b};
            pair<ll, ll> ylims = {-1ll * (LIM - 1) / 2 * (d - c) + c,
                                  1ll * (LIM - 1) / 2 * (d - c) + d};

            pair<ll, ll> req = {diff.first / 2, diff.second / 2};
            if (req.first >= xlims.first && req.first <= xlims.second &&
                req.second >= ylims.first && req.second <= ylims.second) {
                cout << "Yes" << endl;
                req.first -= a;
                req.second -= c;
                pair<ll, ll> pt;
                if (req.first <= 1ll * (LIM - 1) / 2 * (b - a)) {
                    pt.first = a;
                } else {
                    pt.first = a + req.first - 1ll * (LIM - 1) / 2 * (b - a);
                }

                if (req.second <= 1ll * (LIM - 1) / 2 * (d - c)) {
                    pt.second = c;
                } else {
                    pt.second = c + req.second - 1ll * (LIM - 1) / 2 * (d - c);
                }

                cout << pt.first << " " << pt.second << endl;

                req.first += a;
                req.second += c;
                req.first -= pt.first;
                req.second -= pt.second;

                while (req.first != 0 || req.second != 0) {
                    pair<ll, ll> xs;
                    pair<ll, ll> ys;
                    ll val = req.first;
                    if (abs(val) >= b - a) {
                        if (val >= 0) {
                            xs.first = a;
                            xs.second = b;
                        } else {
                            xs.first = b;
                            xs.second = a;
                        }
                    } else {
                        if (val >= 0) {
                            xs.first = a;
                            xs.second = xs.first + val;
                        } else {
                            xs.second = a;
                            xs.first = xs.second - val;
                        }
                    }
                    req.first -= xs.second - xs.first;

                    val = req.second;
                    if (abs(val) >= d - c) {
                        if (val >= 0) {
                            ys.first = c;
                            ys.second = d;
                        } else {
                            ys.first = d;
                            ys.second = c;
                        }
                    } else {
                        if (val >= 0) {
                            ys.first = c;
                            ys.second = ys.first + val;
                        } else {
                            ys.second = c;
                            ys.first = ys.second - val;
                        }
                    }
                    req.second -= ys.second - ys.first;

                    cout << xs.first << " " << ys.first << endl;
                    cout << xs.second << " " << ys.second << endl;
                }
                return;
            }
        }
    }
    cout << "No" << endl;
    return;
}

int main() {
    fio;
    TEST_LOOP;
}