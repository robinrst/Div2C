#include "bits/stdc++.h"

using namespace std;

#define  f first
#define  lgn 25
#define  endl '\n'
#define  sc second
#define  N (int)2e5+5
#define  sz(x) x.size()
#define  int long long int
#define  ld long double
#define  vi vector<int>
#define  vs vector<string>
#define  vc vector<char>
#define  mii map<int,int>
#define  pii pair<int,int>
#define  vpii vector<pii>
#define  test(x) while(x--)
#define  pb push_back
#define  eb emplace_back
#define  pq priority_queue
#define  mod 1000000007
#define  fo(i,a,n) for(int i=a;i<n;i++)
#define  rfo(i,n,a) for(int i=n;i>=a;i--)
// #define fo(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define  mst(a,v,n) fo(i,0,n) a[i]=v
#define  all(x) begin(x),end(x)
#define  allr(x) rbegin(x),rend(x)
#define  rev(x) reverse(begin(x),end(x))
#define  db(x) cout<<#x <<" : "<< x <<endl;
#define time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n"

const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,m,k,d,q;
string s;
vi adj[N];
int vis[N],par[N],a[N],sz[N],Q[N];
int dp[N][2];

int ways(int sum ,int f ) // f -> whether the 'd' is encountered in the path or not
{
	if( sum > n) return 0;
	if( sum == n) return f;

	if( dp[sum][f] != -1 ) return dp[sum][f];

	int aa = 0;

	fo(j,1,k+1)
	{
		int nf = f;

		if( j >= d ) nf  = 1; 

		aa = (aa % mod + ways(sum + j, nf) % mod ) % mod;
		aa %= mod;
	}
	return dp[sum][f] = aa % mod;
}

void go()
{
	cin>>n>>k>>d;

	memset(dp,-1,sizeof dp);

	int ans = ways(0,0) % mod;

	cout << ans % mod << endl;

}

int32_t main()
{	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t=1; 
	// cin>>t;
	test(t) go();
}