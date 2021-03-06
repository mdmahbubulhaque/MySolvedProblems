#include <bits/stdc++.h>
using namespace std;

#define all(v)                      v.begin(), v.end()
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

vll primes;
vb isPrime;

void sieve() {
    isPrime.assign(1005, true);
    int lim = sqrt(1000) + 1;
    primes.pb(2);
    for (int i = 3; i <= 1000; i += 2) {
        if (isPrime[i]) {
            primes.pb(i);
            if (i <= lim) {
                for (int j = i * i; j <= 1000; j += 2 * i) {
                    isPrime[j] = false;
                }
            }
        }
    }
}

map<vii, int > cnt;
vi ara;
ll n, k;

vii divs(ll n) {
    vii res;
    ll pcnt = 0, pf = primes[pcnt];
    while (pf * pf <= n) {
        if (n % pf == 0) {
            int cntt = 0;
            while (n % pf == 0) {
                n /= pf;
                cntt++;
            }
            if (cntt % k != 0)
                res.pb({pf, cntt % k});
        }
        pf = primes[++pcnt];
    }
    if (n != 1)
        res.pb({n, 1});
    if (siz(res) == 0) {
        res.pb({-1, 0});
    }
    return res;
}

int main() {
    //FI;FO;
    FastIO;//timeInit;
    sieve();

    cin >> n >> k;
    ara.resize(n + 1);
    vvii vec(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ara[i];
        vec[i] = divs(ara[i]);
        cnt[vec[i]]++;
    }

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        if (vec[i][0].ff == -1) {
            ans += cnt[vec[i]] - 1;
            cnt[vec[i]]--;
        }
        else {
            vii temp;
            temp.resize(siz(vec[i]));
            bool ok = true;
            for (int j = 0; j < siz(vec[i]); j++) {
                temp[j] = {vec[i][j].ff, k - vec[i][j].ss};
                if (vec[i][j].ss != temp[j].ss)
                    ok = false;
            }

            ans += cnt[temp] - (ok ? 1 : 0);
            cnt[vec[i]]--;
        }
    }

    cout << ans << endl;

    //timeTaken;
    return 0;
}
