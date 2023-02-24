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

// #define INTERACTIVE

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

int dfs(pair<int, int> head, vector<vector<int>> &arr,
        vector<vector<bool>> &vis, vector<vector<int>> &comp, int comp_num) {
    int comp_sz = 1;
    vis[head.first][head.second] = true;
    comp[head.first][head.second] = comp_num;
    const int N = sz(arr);
    const int M = sz(arr[0]);
    vector<pair<int, int>> delta = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
    for (auto del : delta) {
        int new_x = del.first + head.first;
        int new_y = del.second + head.second;
        if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < M &&
            !vis[new_x][new_y] &&
            arr[new_x][new_y] == arr[head.first][head.second])
            comp_sz += dfs({new_x, new_y}, arr, vis, comp, comp_num);
    }

    return comp_sz;
}

void solve() {
    int N, M, T;
    cin >> N >> M >> T;
    vector<vector<int>> arr(N, vector<int>(M, -1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char temp;
            cin >> temp;
            arr[i][j] = temp - '0';
        }
    }
    int num_comp = 0;
    vector<vector<int>> comp(N, vector<int>(M, -1));
    vector<vector<bool>> vis(N, vector<bool>(M, false));
    vector<int> comp_sz;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!vis[i][j]) {
                comp_sz.push_back(dfs({i, j}, arr, vis, comp, num_comp));
                num_comp++;
            }
        }
    }
    vector<vector<int>> dist(N, vector<int>(M, -1));
    queue<pair<int, int>> q;
    vis = vector<vector<bool>>(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            assert(comp[i][j] != -1);
            assert(comp_sz[comp[i][j]] >= 1);
            if (comp_sz[comp[i][j]] > 1) {
                q.push({i, j});
                vis[i][j] = true;
                dist[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        auto tp = q.front();
        q.pop();
        vector<pair<int, int>> delta = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
        for (auto del : delta) {
            int new_x = del.first + tp.first;
            int new_y = del.second + tp.second;
            if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < M &&
                !vis[new_x][new_y] && comp_sz[comp[new_x][new_y]] == 1) {
                q.push({new_x, new_y});
                vis[new_x][new_y] = true;
                dist[new_x][new_y] = dist[tp.first][tp.second] + 1;
            }
        }
    }
    for (int i = 0; i < T; i++) {
        pair<int, int> pos;
        cin >> pos.first >> pos.second;
        --pos.first;
        --pos.second;
        ll time;
        cin >> time;
        if (comp_sz[comp[pos.first][pos.second]] > 1) {
            if (time & 1) {
                cout << (1 ^ arr[pos.first][pos.second]) << endl;
            } else {
                cout << arr[pos.first][pos.second] << endl;
            }
        } else {
            if (dist[pos.first][pos.second] == -1) {
                cout << arr[pos.first][pos.second] << endl;
            } else {
                if (time <= dist[pos.first][pos.second])
                    cout << arr[pos.first][pos.second] << endl;
                else {
                    int diff = time - dist[pos.first][pos.second];
                    if (diff & 1) {
                        cout << (1 ^ arr[pos.first][pos.second]) << endl;
                    } else {
                        cout << arr[pos.first][pos.second] << endl;
                    }
                }
            }
        }
    }
}

int main() {
    fio;
    TEST_LOOP;
}