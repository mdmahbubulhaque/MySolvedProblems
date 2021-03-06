#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define vpll vector<pll>
#define MOD 1000000007
#define EPS 1e-8
#define mem(x,y) memset(x,y,sizeof x)
#define INF 1e9
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define PI acos(-1.0)
//#define FIFO
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)
#define debug(x) cout<<"WTH: "<<x<<endl
#define fof(x,y) for(int i=x;i<(int)y;i++)
#define fob(x,y) for(int i=x;i>=(int)y;i--)

template<class T>
class compare{
public:
    bool operator()(pair<T,T> x,pair<T,T> y){
        if(x.second==y.second){
            return x.first<y.first;
        }
        return x.second<y.second;
    }
};

template<class T>
ostream& operator<<(ostream &os,const pair<T,T> &a){
    os<<a.ff<<" "<<a.ss;
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
#ifdef FIFO
    FI;
    FO;
#endif
    FASTIO;

    int n,k,m;
    cin>>n>>k>>m;

    ll ara[n+1];

    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }

    sort(ara+1,ara+n+1);

    if(n==1){
        ll x;
        
        if(m>=k) x=k;
        else x=m;
        cout<<fixed<<setprecision(15)<<(double)(ara[1]+x)<<endl;
        return 0;
    }

    int now=ara[1];
    int idx=1;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(now==ara[i]) {
            cnt++;
            continue;
        }
        else{

            if(m>=cnt){
                m-=cnt;
                idx=i;
                cnt=1;
                now=ara[i];
            }
            else{
                break;
            }

        }
    }

    double avg1=0,avg2=0;
    double sum1=0,sum2=0,sum=0;

    for(int i=idx;i<=n;i++){
        sum+=ara[i];
    }

    if(m>=(n-idx+1)*k){
        sum1=sum+(n-idx+1)*k;
    }
    else sum1=sum+m;

    avg1=sum1/(n-idx+1);

    if(m>=(n-idx+1)){

        double x;
        if((m-(n-idx))>=k) x=k;
        else x=m-(n-idx);

        sum2=ara[n]+x;

        avg2=sum2;
    }

double avg3=0;
sum=0;

for(int i=idx+m;i<=n;i++){
        sum+=ara[i];
    }

avg3=sum/(n-m-idx+1);

    cout<<fixed<<setprecision(15)<<max(avg3,max(avg1,avg2))<<endl;

    return 0;
}
