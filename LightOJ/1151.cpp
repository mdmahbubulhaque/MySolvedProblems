#include <bits/stdc++.h>
using namespace std;

#define dist2D(x1,y1,x2,y2)         ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2)   ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define EPS                         1e-12
#define FastIO                      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI                          freopen("in.txt","r",stdin)
#define FO                          freopen("out.txt","w",stdout)
#define fap(x)                      cout<<"WTH: "<<x<<endl
#define ff                          first
#define fof(i,x,y)                  for(int i=x;i<(int)y;i++)
#define fob(i,x,y)                  for(int i=x;i>=(int)y;i--)
#define INF                         1000000000
#define ld                          long double
#define ll                          long long
#define mem(x,y)                    memset(x,y,sizeof x)
#define mp                          make_pair
#define msi                         map<string,int>
#define mii                         map<int,int>
#define mis                         map<int,string>
#define MOD                         1000000007
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
#define vpll                        vector<pll>

template<class T> class compare{
public:
    bool operator()(pair<T,T> &x,pair<T,T> &y){
        if(x.first==y.first){
            return x.ss>y.ss;
        }
        return x.ff>y.ff;
    }
};

template<class T> ostream& operator<<(ostream &os,const pair<T,T> &a) { os<<a.ff<<" "<<a.ss; }
template<class T> void print(vector<T> &vec){
    for(int i=1;i<siz(vec);i++) cout<<vec[i]<<" ";cout<<endl;
}
template<class T> void print(set<T> &s) {
    for(auto it: s) cout<<it<<" "; cout<<endl;
}
template<class T> void print(list<T> &lst) {
    for(auto it: lst) cout<<it<<" "; cout<<endl;
}
template<class T> ll power(T a,int b){
    ll po=1; while(b--) po*=a; return po;
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

///=======================================template=======================================//

int to[101];

int gauss(vector< vector<double> > &a, vector<double> &ans){
    int n=siz(a);
    int m=siz(a[0])-1;

    vi where(m,-1);

    for(int col=0,row=0; col<m and row<n; ++col){
        int sel=row;
        for(int i=row;i<n;i++){
            if(abs(a[i][col])>abs(a[sel][col]))
                sel=i;
        }

        if(abs(a[sel][col])<EPS)
            continue;

        for(int i=col;i<=m;i++){
            swap(a[sel][i],a[row][i]);
        }
        where[col]=row;

        for(int i=0;i<n;i++){
            if(i!=row){
                double c=a[i][col]/a[row][col];
                for(int j=col;j<=m;j++){
                    a[i][j]-=a[row][j]*c;
                }
            }
        }
        ++row;
    }

    ans.assign(m,0);
    for(int i=0;i<m;i++){
        if(where[i]!=-1){
            ans[i]=a[where[i]][m]/a[where[i]][i];
        }
    }
    for(int i=0;i<n;i++){
        double sum=0;
        for(int j=0;j<m;j++){
            sum+=ans[j]*a[i][j];
        }
        if(abs(sum-a[i][m])>EPS)
            return 0;
    }
    for(int i=0;i<m;i++){
        if(where[i]==-1)
            return INF;
    }
    return 1;
}

int main()
{
    //FI;FO;
    FastIO;

    int t; cin>>t;

    for(int cas=1;cas<=t;cas++){
        cout<<"Case "<<cas<<": ";
        for(int i=0;i<=100;i++) to[i]=i;
        int n; cin>>n;

        for(int i=0;i<n;i++){
            int a,b; cin>>a>>b;
            a--,b--;
            to[a]=b;
        }

        vector<double> ans;
        double pos=1.0/6;

        vector<vector<double> > mat(100,vector<double>(101,0));
        for(int i=0;i<99;i++) mat[i][100]=1;
        mat[99][100]=0;
        for(int i=0;i<100;i++){
            mat[i][i]=1;

            for(int j=1;j<=6;j++){
                if(i+j<=99) mat[i][to[i+j]]-=pos;
                else mat[i][i]-=pos;
            }

        }

        gauss(mat,ans);

        cout<<fixed<<setprecision(10)<<ans[0]<<endl;

    }

    return 0;
}
