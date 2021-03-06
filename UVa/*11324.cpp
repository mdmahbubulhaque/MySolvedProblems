#include <bits/stdc++.h>
using namespace std;

#define all(v)                      v.begin(), v.end()
#define Chrono                      chrono::steady_clock::now().time_since_epoch().count()
#define dist2D(x1, y1, x2, y2)            ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
#define dist3D(x1, y1, z1, x2, y2, z2)    ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2))
#define EPS                         1e-15
#define eb                          emplace_back
#define endl                        "\n"
#define FastIO                      ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI                          freopen("in.txt", "r", stdin)
#define FO                          freopen("out.txt", "w", stdout)
#define ff                          first
#define gt(i, x)                    get<i>(x)
#define INF              1000000000000000000
#define ld                          long double
#define ll                          long long
#define mem(x,y)                    memset(x, y, sizeof x)
#define mp                          make_pair
#define mt                          make_tuple
#define msi                         map<string, int>
#define mii                         map<int, int>
#define mis                         map<int, string>
#define MOD                         1000000007
#define PI                          acos(-1.0)
#define PQ                          priority_queue
#define pb                          push_back
#define pib                         pair<int, bool>
#define pii                         pair<int, int>
#define iii                         pair<int, pii>
#define iiii                        pair<pii, pii>
#define pll                         pair<ll, ll>
#define present(c, x)               ((c).find(x) != (c).end())
#define sfi(x)                      scanf("%d", &x)
#define sfii(x,y)                   scanf("%d %d", &x, &y)
#define sfiii(x,y,z)                scanf("%d %d %d", &x, &y, &z)
#define siz(x)                      (int)x.size()
#define ss                          second
#define tii                         tuple<int, int>
#define tiii                        tuple<int, int, int>
#define tiiii                       tuple<int, int, int, int>
#define timeTaken                   endd = clock(); cerr << (double) (endd - beginn) / CLOCKS_PER_SEC * 1000 << endl
#define timeInit                    clock_t beginn = clock(), endd
#define ull                         unsigned long long
#define umsi                        unordered_map<string, int>
#define umii                        unordered_map<int, int>
#define umis                        unordered_map<int, string>
#define vb                          vector<bool>
#define vi                          vector<int>
#define vvi                         vector<vi>
#define vii                         vector<pii>
#define vvii                        vector<vii>
#define vll                         vector<ll>
#define vvll                        vector<vll>
#define vpll                        vector<pll>
#define bug(...)                    cerr << __LINE__ << " : (" << #__VA_ARGS__ << ") = ("; _Print(__VA_ARGS__);
template<class T> void _Print(T &&x) { cerr << x << ")" << endl; }
template<class T, class ...S> void _Print(T &&x, S &&...y) { cerr << x << ", "; _Print(y...); }

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
typedef tree<int,null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;

//os.order_of_key(v): returns how many elements strictly less than v
//os.find_by_order(k - 1): returns kth smallest element's iterator
*/

template<class T> class compare {
public:
    bool operator() (pair<T, T> &x, pair<T, T> &y) {
        if (x.first == y.first) {
            return x.ss > y.ss;
        }
        return x.ff > y.ff;
    }
};

template<class T> ostream &operator<<(ostream &os, const pair<T, T> &a) { return os << a.ff << " " << a.ss; }
ll power(ll a, int b) {
    ll po = 1;
    while (b) {
        if (b & 1)
            po *= a;
        a *= a;
        b >>= 1;
    }
    return po;
}

template<class T> pair<T, T> operator+(const pair<T, T> &a, const pair<T, T> &b) { return {a.ff + b.ff, a.ss + b.ss}; }
template<class T> pair<T, T> operator-(const pair<T, T> &a, const pair<T, T> &b) { return {a.ff - b.ff, a.ss - b.ss}; }
template<class T> pair<T, T> operator*(const pair<T, T> &a, const pair<T, T> &b) { return {a.ff * b.ff, a.ss * b.ss}; }
template<class T> pair<T, T> operator%(const pair<T, T> &a, const pair<T, T> &b) { return {a.ff % b.ff, a.ss % b.ss}; }
template<class T, class U> pair<T, T> operator+(const pair<T, T> &a, const U &b) { return {a.ff + b, a.ss + b}; }
template<class T, class U> pair<T, T> operator*(const pair<T, T> &a, const U &b) { return {a.ff * b, a.ss * b}; }

int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos){ return N = N & ~ (1 << pos); }
bool check(int N, int pos){ return (bool) (N & (1 << pos)); }

///=======================================template=======================================///
const int maxn = 1001;
vi g[maxn], g1[maxn], Stack, topsort;
vvi SCC;
int dfs_num[maxn], dfs_low[maxn], dfs_times, numOfSCC, inWhichSCC[maxn], vis[maxn], sz;

void tarjan_SCC(int u) {
    dfs_num[u] = dfs_low[u] = ++dfs_times;
    Stack.eb(u);
    vis[u] = 1;
    for (auto &v : g[u]) {
        if (dfs_num[v] == -1)
            tarjan_SCC(v);
        if (vis[v] == 1) {
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
    }

    if (dfs_num[u] == dfs_low[u]) {
        vi temp;
        int v;
        do {
            v = Stack.back();
            vis[v] = -1;
            Stack.pop_back();
            temp.pb(v);
            inWhichSCC[v] = numOfSCC;
        } while (v != u);
        SCC.eb(temp);
        numOfSCC++;
    }
}

void dfs1(int u) {
    vis[u] = 1;
    for (auto &v : g1[u]) {
        if (!vis[v])
            dfs1(v);
    }
    topsort.eb(u);
}

void dfs(int u, int val, int p) {
    vis[u] = 1;
    sz = max(sz, val);
    for (auto &v : g1[u]) {
        if (v != p)
            dfs(v, val + siz(SCC[v]), u);
    }
}

int main() {
    //FI;FO;
    FastIO; //timeInit;

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            dfs_num[i] = dfs_low[i] = vis[i] = inWhichSCC[i] = -1;
        }
        Stack.clear();
        SCC.clear();
        topsort.clear();
        dfs_times = numOfSCC = 0;

        while (m--) {
            int u, v;
            cin >> u >> v;
            g[u].pb(v);
        }

        for (int i = 1; i <= n; i++) {
            if (dfs_num[i] == -1)
                tarjan_SCC(i);
        }

        for (int i = 0; i < numOfSCC; i++)
            g1[i].clear();

        map<pii, bool> taken;
        for (int i = 1; i <= n; i++) {
            for (auto &v : g[i]) {
                if (inWhichSCC[i] != inWhichSCC[v]) {
                    if (taken[{inWhichSCC[i], inWhichSCC[v]}])
                        continue;
                    g1[inWhichSCC[i]].eb(inWhichSCC[v]);
                    taken[{inWhichSCC[i], inWhichSCC[v]}] = true;
                }
            }
        }
        for (int i = 0; i < numOfSCC; i++)
            vis[i] = 0;
        for (int i = 0; i < numOfSCC; i++) {
            if (!vis[i])
                dfs1(i);
        }

        reverse(all(topsort));

        for (int i = 0; i < numOfSCC; i++)
            vis[i] = 0;

        int mx = 0;

        for (int i = 0; i < numOfSCC; i++) {
            if (!vis[topsort[i]]) {
                sz = 0;
                dfs(topsort[i], siz(SCC[topsort[i]]), -1);
                mx = max(mx, sz);
            }
        }

        cout << mx << endl;
    }

    //timeTaken;
    return 0;
}
