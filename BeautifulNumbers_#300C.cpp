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
#define          N (int)1e6+5
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

int n,m,k,q,a,b;
string s;
int vis[N],par[N],fact[N],invFact[N];

int FastExpo(int x, int n )
{
	int ans = 1;

	while(n)
	{
		if( n&1 ) ans = ( ans%mod * x%mod )%mod;
		x = ( x%mod * x%mod )%mod;
		n >>= 1;
	}

	return ans;
}

void FACT()
{
	fact[0] = invFact[0] = 1;

	fo(i,1,N)
	{
		fact[i] = (1LL * fact[ i - 1 ] * i )%mod;
		invFact[i] = FastExpo( fact[i] , mod - 2 );
	}
}

bool check( int no )
{
	while( no )
	{
		int rem = no%10;

		if( rem != a and rem != b ) return 0;

		no /= 10;
	}

	return 1;
}

void go()
{
	cin>>a>>b>>n;

	int l = 1, r = n - 1;

	int ans = 0;

	while( l <= r )
	{
		int x = l*a;
		int y = r*b;		
		int w = l*b;
		int z = r*a;

		int no = x + y;
		if( check( no ) )
		{
			int add = (fact[n]%mod * invFact[l]%mod * invFact[r]%mod )%mod;
			ans += add;
			ans %= mod;
		}

		no = w + z;
		if( check( no ) )
		{
			int add = (fact[n]%mod * invFact[l]%mod * invFact[r]%mod )%mod;
			ans += add;
			ans %= mod;
		}
		l++;
		r--;
	}

	int xx = n*a;
	int yy = n*b;

	if( check(xx) ) ans++;
	if( check(yy) ) ans++;

	ans %= mod;

	cout << ans << endl;
	// time();
	
}

int32_t main()
{
	INP(); 
	FAST;     
	int t=1; 
	FACT();
	// cin>>t;
	test(t) go();
}