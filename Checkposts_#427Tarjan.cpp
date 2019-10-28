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
#define          N (int)3e5+5
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
int cost[N];

int cnt,scc;
vi adj[N],comp[N];
int vis[N],low[N],inStack[N],id[N];
stack<int> stk;

void dfs(int at)
{
	int xx;
	stk.push(at);
	vis[ at ] = low[ at ] = ++cnt;
	inStack[ at ] = 1;

	for( auto to : adj[ at ] )
	{
		if( !vis[ to ] )
		{
			dfs(to);
			low[ at ] = min( low[ to ], low[ at ] );
		}
		else if ( inStack[ to ] )
		{
			low[ at ] = min( low[ at ], vis[ to ] );
		}
	}

	if( low[ at ] == vis[ at ] )
	{
		scc++;
		do
		{
			xx = stk.top();
			stk.pop();
			inStack[ xx ] = 0;
			comp[scc].pb(xx);

		}while( xx != at );
	}
}


void go()
{
	cin>>n;

	fo(i,1,n+1) cin>>cost[i];

	cin>>m;

	fo(i,0,m)
	{
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
	}	

	scc = 0, cnt = 0;

	fo(i,1,n+1)
	{
		if( !vis[i] ) 
		{
			dfs(i);
		}
	}

	int ans = 0, ways = 1;

	fo(i,1,scc+1)
	{
		int count = 0, mn = inf;

		fo(j,0,sz(comp[i])) mn = min( mn , cost[ comp[i][j] ] );
		fo(j,0,sz(comp[i]))
		{
			if( cost[ comp[i][j] ] == mn ) count++;
		}

		ans += mn;
		ways *= count;
		ways %= mod;
	}

	cout << ans <<' ' << ways << endl;
}

int32_t main()
{
	INP(); 
	FAST;	
	int t=1; 
	// cin>>t;
	test(t) go();
}