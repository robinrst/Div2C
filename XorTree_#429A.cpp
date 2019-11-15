#include        "iostream"
#include        "algorithm"
#include        "cstring"
#include        "string"
#include        "vector"
#include        "ctime"
#include        "queue"
#include        "stack"
#include        "map"
#include        "set"

using namespace std;

#define          f first
#define          lgn 25
#define          endl '\n'
#define          sc second
#define          N (int)2e5+5
#define          pb push_back
#define          mod 1000000007
#define          sz(x) x.size()
#define          ld long double
#define          vi vector<int>
#define          eb emplace_back
#define          vc vector<char>
#define          vpii vector<pii>
#define          mii map<int,int>
#define          int long long int
#define          pii pair<int,int>
#define          vs vector<string>
#define          pq priority_queue
#define          test(x) while(x--)
#define          all(x) begin(x),end(x)
#define          allr(x) rbegin(x),rend(x)
#define          mst(a,v,n) fo(i,0,n) a[i]=v
#define          fo(i,a,n) for(int i=a;i<n;i++)
#define          rfo(i,n,a) for(int i=n;i>=a;i--)
#define          rev(x) reverse(begin(x),end(x))
#define          db(x) cout<<#x <<" : "<< x <<endl;
#define          FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define          time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n"

inline void printA( int _a[] , int _to, int _from = 0 )
{
	for( int _i = _from; _i < _to; _i++ ) cout << _a[ _i ] << ' ';
	cout << endl;
}

inline void printV( vi _a , int _to, int _from = 0)
{
	for( int _i = _from; _i < _to; _i++ ) cout << _a[ _i ] << ' ';
	cout << endl;
}

inline void INP()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);   
	    freopen("output.txt","w",stdout);
	#endif 
}

const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,m,k,q;
string s;
vi adj[N],ans;
int vis[N],par[N],a[N],b[N];

void dfs( int i, int p = 0, int level = 0, int even = 0, int odd = 0)
{
	vis[i] = 1;
	int o = 0, e = 0;

	a[i] += (level&1 ? odd : even );
	a[i] %= 2;

	if( a[i] != b[i] )
	{
		ans.pb(i);
		b[i] = a[i];
		(level&1) ? o++ : e++;
	} 	

	for( auto j : adj[i] )
	{
		if( !vis[j] ) 
		{
			dfs(j, i, level + 1, even + e, odd + o );
		}
	}
}

void go()
{
	cin>>n;

	ans.clear();

	fo(i,0,n-1)
	{
		int u,v;
		cin>>u>>v;

		adj[u].pb(v);
		adj[v].pb(u);
	}

	fo(i,1,n+1) cin>>a[i];
	fo(i,1,n+1) cin>>b[i];

	dfs(1);
	
	cout << sz( ans ) << endl;
	for( auto i : ans ) cout << i << endl;
}

int32_t main()
{
	INP(); 
	FAST;     
	int t=1; 
	// cin>>t;
	test(t) go();
}