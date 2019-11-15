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

int yh,ya,yd,ma,mh,md,h,a,d;
string s;

void go()
{
	cin>>yh>>ya>>yd;
	cin>>mh>>ma>>md;
	cin>>h>>a>>d;

	int ans = INF;

	fo(i,0,201)
	{
		int tcost = inf;
		
		fo(j,0,101)
		{
			int cost = 0;

			if( i <= md ) continue;

			int xx = ( i - ya );
			if( xx > 0 ) cost += xx*a;
			int yy = ( j - yd);
			if( yy > 0) cost += yy*d;

			if( i > md and ma <= j )
			{
				if( yh <= 0 ) cost += h;
				tcost = min( tcost , cost);
				continue;
			}

			int tyh = yh , tmh = mh;

			while( tmh > 0 )
			{
				tyh -= max( 0LL, ma - j);
				tmh -= max( 0LL, i - md);
			}

			if( tyh <= 0 ) cost += ( 0 - tyh + 1 )*h , tyh = 0 - tyh + 1;

			if( tyh > 0 and tmh <= 0 )
				tcost = min( tcost , cost);
		}

		ans = min( ans, tcost);
	}

	cout << ans << endl;

}

int32_t main()
{
	INP(); 
	FAST;     
	int t=1; 
	// cin>>t;
	test(t) go();
}