#include        "iostream"
#include        "algorithm"
#include        "vector"
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

inline void INP()
{
	#ifndef O_J
	    freopen("input.txt","r",stdin);   
	    freopen("output.txt","w",stdout);
	#endif 
}

const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,m,k,q;
string s;
vpii adj[N];
int sz[N], par[N];

mii mpx,mpy;


void build()
{
	fo(i,1,n+1) par[i] = i , sz[i] = 1;
}

int Root(int i)
{
	while( par[i] != i)
	{
		par[i] = par[ par[i] ];
		i = par[i];
	}

	return i;
}

void Union(int x, int y) // x is parent of y
{
	int xPar = Root(x);
	int yPar = Root(y);

	if( yPar == xPar ) return;

	if( sz[ xPar ] < sz[ yPar ]) 
		swap(sz[ xPar ] , sz[ yPar ]);

	par[ yPar ] = xPar;
	sz[ xPar ] += sz[ yPar ];

}

void go()
{
	cin>>n;

	int cn = 0;

	build();

	fo(i,1,n+1)
	{
		int u,v;
		cin>>u>>v;

		if( mpx.count(u) ) Union( i, mpx[u] );
		else mpx[u] = i;

		if( mpy.count(v) ) Union( i, mpy[v] );
		else mpy[v] = i;

	}

	fo(i,1,n+1)
	{
		fo(j,1,n+1)
		{
			if( i != j )
			{
				if (Root(i) != Root(j) ) Union( i, j) , cn++;
			}
		}
	}

	cout << cn << endl;
}

int32_t main()
{
// 	INP(); 
	FAST;	
	int t=1; 
	// cin>>t;
	test(t) go();
}