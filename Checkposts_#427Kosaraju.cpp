#include        "iostream"
#include        "algorithm"
#include        "vector"
#include        "queue"
#include        "stack"
#include 		"cstring"
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
vi adj[N],radj[N];
int vis[N],par[N],a[N];
vi v,components;

void dfs(int i)
{
	vis[i] = 1;

	for(auto j : adj[i] )
	{
		if( !vis[j] ) dfs(j);
	}
	v.pb(i);
}

void dfs1(int i)
{
	vis[i] = 1;

	components.pb(i);

	for( auto j : radj[i] )
	{
		if( !vis[j] ) dfs1(j);
	}
}

void go()
{
	cin>>n;

	fo(i,1,n+1) cin>>a[i];

	cin>>m;

	fo(i,0,m) 
	{
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		radj[v].pb(u);
	}

	fo(i,1,n+1)
	{
		if( !vis[i] ) dfs(i);
	}

	memset( vis,0, sizeof (vis));

	int cost = 0;
	int ways = 1;

	rfo(i,sz(v)-1,0)
	{

		if( !vis[ v[i] ] ) 
		{
			dfs1( v[i] );

			int mn = INF;
			int cn = 0;

			fo(j,0,sz(components))
			{
				if( a[ components[j] ] < mn )
				{
					cn = 1;
					mn = a[ components[j] ];
				}
				else if ( a[ components[j] ] == mn ) ++cn;
			}

			cost += mn;
			ways *= cn;
			ways %= mod;
			components.clear();
		}
	}

	cout << cost << ' ' << ways << endl;
}

int32_t main()
{
	INP(); 
	FAST;	
	int t=1; 
	// cin>>t;
	test(t) go();
}