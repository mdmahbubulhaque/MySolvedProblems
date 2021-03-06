#include <bits/stdc++.h>
using namespace std;

#define dist2D(x1,y1,x2,y2)         ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2)   ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define EPS                         1e-16
#define endl                        "\n"
#define FastIO                      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI                          freopen("in.txt","r",stdin)
#define FO                          freopen("out.txt","w",stdout)
#define fap(x)                      cout<<"WTH: "<<x<<endl
#define ff                          first
#define fof(i,x,y)                  for(int i=x;i<(int)y;i++)
#define fob(i,x,y)                  for(int i=x;i>=(int)y;i--)
#define INF              1000000000000000000
#define ld                          long double
#define ll                          long long
#define mem(x,y)                    memset(x,y,sizeof x)
#define mp                          make_pair
#define msi                         map<string,int>
#define mii                         map<int,int>
#define mis                         map<int,string>
#define MOD                         998244353
#define PI                          acos(-1.0)
#define PQ                          priority_queue
#define pb                          push_back
#define pib                         pair<int,bool>
#define pii                         pair<int,int>
#define pll                         pair<ll,ll>
#define sfi(x)                      scanf("%d",&x)
#define sfii(x,y)                   scanf("%d%d",&x,&y)
#define sfiii(x,y,z)                scanf("%d%d%d",&x,&y,&z)
#define siz(x)                      (int)x.size()
#define sortv(v)                    sort(v.begin(),v.end())
#define ss                          second
#define timeTaken                   endd=clock();cout<<(double)(endd-beginn)/CLOCKS_PER_SEC*1000<<endl
#define timeInit                    clock_t beginn=clock(),endd
#define ull                         unsigned long long
#define umsi                        unordered_map<string,int>
#define umii                        unordered_map<int,int>
#define umis                        unordered_map<int,string>
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
typedef tree<int,null_type,less<int>,rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;

//os.order_of_key(v): returns how many elements strictly less than v
//os.find_by_order(k-1): returns kth smallest element's iterator


template<class T> class compare{
public:
    bool operator()(pair<T,T> &x,pair<T,T> &y){
        if(x.first==y.first){
            return x.ss>y.ss;
        }
        return x.ff>y.ff;
    }
};

//template<class T> ostream& operator<<(ostream &os,const pair<T,T> &a) { os<<a.ff<<" "<<a.ss; }
ll power(ll a,int b) {
    ll po = 1;
    while (b) {
        if (b & 1)
            po *= a;
        a *= a;
        b >>= 1;
    }
    return po;
}

template<class T> pair<T,T> operator+(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff+b.ff,a.ss+b.ss}; }
template<class T> pair<T,T> operator-(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff-b.ff,a.ss-b.ss}; }
template<class T> pair<T,T> operator*(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff*b.ff,a.ss*b.ss}; }
template<class T> pair<T,T> operator%(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff%b.ff,a.ss%b.ss}; }
template<class T,class U> pair<T,T> operator+(const pair<T,T> &a,const U &b){ return { a.ff+b,a.ss+b}; }
template<class T,class U> pair<T,T> operator*(const pair<T,T> &a,const U &b){ return { a.ff*b,a.ss*b}; }

int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(int N,int pos){  return (bool) (N&(1<<pos));}

///=======================================template=======================================///
vpll st;

int left(int node){return (node<<1);}
int right(int node){ return (node<<1)+1;}

int mid(int l,int r){
    return (l+r)>>1;
}

void push(int node,int l,int r){
    if(st[node].ss){
        int m=mid(l,r);
        st[left(node)].ss+=st[node].ss;
        st[right(node)].ss+=st[node].ss;
        st[left(node)].ff+=(m-l+1)*st[node].ss;
        st[right(node)].ff+=(r-m)*st[node].ss;
        st[node].ss=0;
    }
}

void update(int node,int l,int r,int i,int j,int val){
    push(node,l,r);
    if(l>j or r<i)
        return;
    if(l>=i and r<=j){
        st[node].ff+=val*(r-l+1);
        st[node].ss=val;
        return;
    }
    int m=mid(l,r);
    update(left(node),l,m,i,j,val);
    update(right(node),m+1,r,i,j,val);
    st[node].ff=st[left(node)].ff+st[right(node)].ff;
}

ll sum(int node,int l,int r,int i,int j){
    push(node,l,r);
    if(j<l or i>r)
        return 0;
    if(l>=i and r<=j){
        return st[node].ff;
    }
    int m=mid(l,r);
    return sum(left(node),l,m,i,j)+sum(right(node),m+1,r,i,j);
}

int main()
{
    //FI;//FO;
    //FastIO;//timeInit;

    int t; //cin>>t;

    sfi(t);


    for(int cas=1;cas<=t;cas++){
        //cout<<"Case "<<cas<<":"<<endl;
        printf("Case %d:\n",cas);
        int n,q;//cin>>n>>q;
        sfii(n,q);

        st.assign(8*n,{0,0});

        while(q--){
            int type;//cin>>type;
            sfi(type);

            if(!type){
                int x,y,val;
                sfiii(x,y,val);
                //cin>>x>>y>>val;
                update(1,0,n-1,x,y,val);
            }
            else{
                int x,y;//cin>>x>>y;
                sfii(x,y);
                printf("%lld\n",sum(1,0,n-1,x,y));
                //cout<<sum(1,0,n-1,x,y)<<endl;
            }
        }

    }

    //timeTaken;
    return 0;
}
