#include <bits/stdc++.h>
using namespace std;
 
#define dist2D(x1, y1, x2, y2)            ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
#define dist3D(x1, y1, z1, x2, y2, z2)    ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2))
#define EPS                         1e-16
#define endl                        "\n"
#define FastIO                      ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI                          freopen("in.txt", "r", stdin)
#define FO                          freopen("out.txt", "w", stdout)
#define fap(x)                      cout << "WTH: " << x << endl
#define ff                          first
#define INF              1000000000000000000
#define ld                          long double
#define ll                          long long
#define mem(x,y)                    memset(x, y, sizeof x)
#define mp                          make_pair
#define msi                         map<string, int>
#define mii                         map<int, int>
#define mis                         map<int, string>
#define MOD                         1000000007
#define PI                          acos(-1.0)
#define PQ                          priority_queue
#define pb                          push_back
#define pib                         pair<int, bool>
#define pii                         pair<int, int>
#define pll                         pair<ll, ll>
#define sfi(x)                      scanf("%d", &x)
#define sfii(x,y)                   scanf("%d %d", &x, &y)
#define sfiii(x,y,z)                scanf("%d %d %d", &x, &y, &z)
#define siz(x)                      (int)x.size()
#define sortv(v)                    sort(v.begin(), v.end())
#define ss                          second
#define timeTaken                   endd = clock(); cout << (double) (endd - beginn) / CLOCKS_PER_SEC * 1000 << endl
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
 
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
typedef tree<int,null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;
 
//os.order_of_key(v): returns how many elements strictly less than v
//os.find_by_order(k - 1): returns kth smallest element's iterator
 
 
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
 
ll Set(ll N, int pos) { return N = N | (1LL << pos); }
int reset(int N, int pos){ return N = N & ~ (1 << pos); }
bool check(ll N, int pos){ return (bool) (N & (1LL << pos)); }
 
///=======================================template=======================================///
 
int main() {
    //FI;FO;
    FastIO;//timeInit;
 
    int n;
    cin >> n;
    int ara[ 3 * n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> ara[i];
        ara[n + i] = ara[i];
        ara[2 * n + i] = ara[i];
    }
 
    int maxi = 0;
 
    int i = 1;
    multiset<pii> mset;
 
    int ans[ 3 * n + 1];
    int last = 0;
    int lastt = 0;
 
    while (true) {
        int x = ara[i];
        vii er;
        if (!mset.empty()) {
            auto it = mset.end();
            it--;
            for (;it!= mset.begin();it--) {
                if ((*it).ss <= lastt) {
                    er.pb(*it);
                } else break;
            }
            if (it == mset.begin())  {
                if ((*it).ss <= lastt) {
                    er.pb(*it);
                }
            }
 
            for (auto v : er) {
                auto itt = mset.find(v);
                if (itt != mset.end())
                    mset.erase(itt);
            }
        }
        if (mset.empty()) {
            mset.insert({ara[i], i});
        }
        else {
            auto it = mset.end();
            it--;
            pii now = *it;
 
            //cout << i << " " << x << " " << now.ff << endl;
 
            if (x * 2 < now.ff) {
                for (int ii = lastt + 1; ii <= now.ss; ii++) {
                    ans[ii] = i - ii;
                }
                lastt = now.ss;
                goto loop;
            }
 
            mset.insert({ara[i], i});
 
        }
        i++;
        if (i > 3 * n) {
            for (int ii = lastt + 1 ; ii <= n; ii++)
                ans[ii] = -1;
            break;
        }
        loop:;
 
    }
 
    for (i = 1; i<=n;i++) {
        cout << ans[i] << " ";
    }
 
    //timeTaken;
    return 0;
}
