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
// #define SINGLE_TEST
#define MULTIPLE_TEST

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
    int N, M;
    cin >> N >> M;
    int color[N];
    for (int i = 0; i < N; i++)
        cin >> color[i];
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<int>> new_graph(N * N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int index = i * N + j;
            for (auto u : adj[i]) {
                for (auto v : adj[j]) {
                    if (color[u] == color[v])
                        continue;
                    else
                        new_graph[index].push_back(N * u + v);
                }
            }
        }
    }

    // find shortest distance from {0, N - 1} to {N - 1, 0}
    queue<pair<int, int>> q;
    vb vis(N * N, false);
    vi dist(N * N, 1e9);
    q.push({0, N - 1});
    vis[N - 1] = true;
    dist[N - 1] = 0;
    while (!q.empty()) {
        auto tp = q.front();
        q.pop();
        int index = tp.first * N + tp.second;
        for (auto elem : new_graph[index]) {
            if (!vis[elem]) {
                vis[elem] = true;
                q.push({elem / N, elem % N});
                dist[elem] = dist[index] + 1;
            }
        }
    }
    int req_index = N * (N - 1);
    if (!vis[req_index])
        cout << -1 << endl;
    else
        cout << dist[req_index] << endl;
}

int main() {
    fio;
    TEST_LOOP;
}