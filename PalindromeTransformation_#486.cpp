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

inline void start()
{

#ifndef O_J
	freopen("input.txt","r",stdin);   
	freopen("output.txt","w",stdout);
#endif     
}

int n,m,k,q;
string s;
vi adj[N];
int vis[N],par[N],a[N],sz[N],Q[N];

int getChange(int i)
{
	char sm = s[i];
	char lr = s[n-i];

	if( sm > lr ) swap(sm,lr);

	int x = 'z' - lr ; // largest alphabet to z
	int y = sm - 'a' + 1;// a to smallest alphabet

	int z = lr - sm ; // between first alphabet and second alphabet

	return min( x+y , z);
}

void go()
{
	cin>>n>>m;
	cin>>s;
	s = " " + s;

	n = sz(s);
	int ans  = 0;

	int ls = 0 , rs = 0 , le = 0, re = 0;
	int i = 1;

	while( i < n - i)
	{
		if( s[i] != s[n-i] )
		{
			ans += getChange(i);
			if( ls == 0 ) ls = i;
			if(rs == 0 ) rs = n - i;
			le = i;
			re = n -i;
		}
		i++;
	}

	int aa = abs(ls - m) + abs( le - ls);
	int bb = abs(le - m) + abs( le - ls);
	int cc = abs(rs - m) + abs( re - rs);
	int dd = abs(re - m) + abs( re - rs);
	int add = min( {aa, bb, cc, dd} ) ;

	if( ls == 0 || rs == 0 ) add = 0;

	cout << ans + add << endl;


}

int32_t main()
{
// 	start();
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	int t=1; 
	// cin>>t;
	test(t) go();
}