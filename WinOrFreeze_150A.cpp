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

int n,m,k,q;
string s;
set<int> st;

bool isPrime(int nn)
{
	if( nn == 1 ) return 0;

	int i = 2;
	int j = 0;

	while( i*i <= nn )
	{
		if( (nn%i) == 0 ) return 0;

		++i;
	}

	return 1;
}

void go()
{
	cin>>n;
	st.clear();

	int i = 2;

	while( i*i <= n )
	{
		if ( (n%i) == 0 )
		{
			st.insert(i);
			st.insert(n/i);
		}
		i++;
	}

	for( auto j : st )
	{
		if( !isPrime(j))
		{
			cout << 1 << endl;
			cout << j << endl;
			return;
		}
	}

	if( sz(st) == 0 ) 
	{
		cout << 1 << endl;
		cout << 0 << endl;
	}
	else cout << 2 << endl;

}

int32_t main()
{
	INP(); 
	FAST;     
	int t=1; 
	// cin>>t;
	test(t) go();
}