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
#define INF                         100000
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
    for(int i=0;i<siz(vec);i++) cout<<vec[i]<<" ";cout<<endl;
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

///=======================================template=======================================///

string udlr="UDLR";
int dirx[]={0,0,-1,1};
int diry[]={1,-1,0,0};

int main()
{
    //FI;FO;
    FastIO;

    ll a,b; cin>>a>>b;
    string input; cin>>input;

    vii pos(siz(input)+1);
    pos[0]=mp(0,0);

    for(int i=0;i<siz(input);i++){
        char ch=input[i];
        fof(j,0,4){
            if(udlr[j]==ch){
                int xx=dirx[j];
                int yy=diry[j];

                pos[i+1].ff=pos[i].ff+xx;
                pos[i+1].ss=pos[i].ss+yy;
            }
        }
    }

    for(int i=0;i<=siz(input);i++){
        ll difx=a-pos[i].ff;
        ll dify=b-pos[i].ss;

        if(pos[siz(input)].ff==0 and pos[siz(input)].ss==0){
            if(difx==0 and dify==0){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
        else if(pos[siz(input)].ff==0){
            if(difx==0){
                ll muly = abs(dify / pos[siz(input)].ss);
                if (muly * pos[siz(input)].ss == dify) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
        else if(pos[siz(input)].ss==0)
        {
            if(dify==0){
                ll mulx = abs(difx / pos[siz(input)].ff);
                if (mulx * pos[siz(input)].ff == difx) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }

        }
        else {
            ll mulx = difx / pos[siz(input)].ff;
            ll muly = dify / pos[siz(input)].ss;
            mulx=abs(mulx);
            muly=abs(muly);

            if (mulx * pos[siz(input)].ff == difx and muly * pos[siz(input)].ss == dify and mulx == muly) {
                cout << "Yes" << endl;
                return 0;
            }

        }
    }

    cout<<"No"<<endl;

    return 0;
}
