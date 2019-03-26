#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<<"WTH: "<<x<<endl
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define EPS 1e-12
#define FastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)
#define ff first
#define fof(i,x,y) for(int i=x;i<(int)y;i++)
#define fob(i,x,y) for(int i=x;i>=(int)y;i--)
#define INF 100000
#define ld long double
#define ll long long
#define mem(x,y) memset(x,y,sizeof x)
#define mp make_pair
#define MOD 1000000007
#define PI acos(-1.0)
#define PQ priority_queue
#define pb push_back
#define pib pair<int,bool>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sfi(x) scanf("%d",&x)
#define sfii(x,y) scanf("%d%d",&x,&y)
#define sfiii(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define siz(x) (int)x.size()
#define sortv(v) sort(v.begin(),v.end())
#define ss second
#define vb vector<bool>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define vpll vector<pll>

template<class T>
class compare{
public:
    bool operator()(pair<T,T> &x,pair<T,T> &y){
        if(x.first==y.first){
            return x.ss>y.ss;
        }
        return x.ff>y.ff;
    }
};

template<class T>
ostream& operator<<(ostream &os,const pair<T,T> &a){
    os<<a.ff<<" "<<a.ss;
}
template<class T>
void print(vector<T> &vec){
    fof(i,0,vec.size()) cout<<vec[i]<<endl;
}
template<class T>
void print(set<T> &s){
    for(auto it: s) cout<<it<<" "; cout<<endl;
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

int main()
{
    //FI;FO;
    //FastIO;

    int t; sfi(t);
    int cas=1;

    while(t--){
        int n; sfi(n);

        int pref[2*n+1][n+1];

        vb candid(n+1,false);
        vi compani(n+1,-1);

        for(int i=1;i<=2*n;i++){
            for(int j=1;j<=n;j++){
                sfi(pref[i][j]);
            }
        }

        while(true){

            int m1=-1;
            for(int i=1;i<=n;i++){
                if(!candid[i]) {
                    m1=i;
                    break;
                }
            }

            if(m1==-1) break;

            for(int i=1;i<=n;i++){
                if(compani[pref[m1][i]-n]==-1){
                    candid[m1]=true;
                    compani[pref[m1][i]-n]=m1;
                    break;
                }
                else{
                    int m=compani[pref[m1][i]-n];

                    int sel;
                    int id=pref[m1][i];

                    for(int j=1;j<=n;j++){
                        if(pref[id][j]==m){
                            sel=m;
                            break;
                        }
                        else if(pref[id][j]==m1){
                            sel=m1;
                            break;
                        }
                    }

                    if(sel==m1){
                        compani[pref[m1][i]-n]=m1;
                        candid[m1]=true;
                        candid[m]=false;
                        break;
                    }
                }
            }

        }

        vii ans;

        for(int i=1;i<=n;i++){
            ans.pb(mp(i+n,compani[i]));
        }

        printf("Case %d:",cas++);

        for(int i=0;i<ans.size();i++){
            printf(" (%d %d)",ans[i].ss,ans[i].ff);
        }
        printf("\n");
    }


    return 0;
}