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
#define  mst(a,v,n) fo(i,0,n) a[i]=v
#define  all(x) begin(x),end(x)
#define  allr(x) rbegin(x),rend(x)
#define  rev(x) reverse(begin(x),end(x))
#define  db(x) cout<<#x <<" : "<< x <<endl;
#define time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n"

const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,m,k,q;
string s;
vi adj[N];
int vis[N],par[N],a[N];
vi v;

void go()
{
	cin>>n;

	fo(i,1,n+1) cin>>a[i], a[i] += a[i-1];

	if( a[n] % 3 != 0 ) 
	{
		cout << 0 << endl;
		return;
	}

	int sum = a[n]/3;
	int nSum = 2*sum; // for 2nd part with sum = a[n]/3;

	int cn = 0;
	int ans = 0;

	fo(i,1,n)
	{
		if( a[i] == nSum ) ans += cn;
		if( a[i] == sum ) cn++;
	}

	cout << ans << endl;



}

int32_t main()
{	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t=1; 
	// cin>>t;
	test(t) go();
}