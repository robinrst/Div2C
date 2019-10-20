#include "iostream"
#include "set"

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
#define  FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  rev(x) reverse(begin(x),end(x))
#define  db(x) cout<<#x <<" : "<< x <<endl;
#define  time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n"
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
string s[N];
set<char> st[N];

void go()
{
	cin>>n>>m;

	fo(i,0,n)
	{
		cin>>s[i];
		fo(j,0,m) st[j].insert(s[i][j]); // taking count of different letter at every row's jth column.
	}
	int ans =  1;

	fo(i,0,m)
	{
		ans = (ans % mod * sz(st[i]) % mod) % mod;
	}

	cout << ans << endl;
		
}

int32_t main()
{
// 	INP();
	FAST;	
	int t=1; 
	// cin>>t;
	test(t) go();
}