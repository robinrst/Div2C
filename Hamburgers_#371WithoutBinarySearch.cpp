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

int n,m,k,q,S,B,C,s,b,c,ps,pb,pc,tt;
string str;

void go()
{
	cin>>str;

	int ans  = 0;
	bool bread = 0, sausage = 0, cheese = 0;

	fo(i,0,sz(str))
	{
		if( str[i] == 'S' ) S++ , sausage = 1 ;
		if( str[i] == 'B' ) B++ , bread = 1;
		if( str[i] == 'C' ) C++ , cheese = 1;
	}

	cin>>b>>s>>c;
	cin>>pb>>ps>>pc;
	cin>>tt;

	int bb = inf;
	int ss = inf;
	int cc = inf;
	int canMake = 0;

	while(1) 
	{
		if( B > 0) bb = b/B; 
		if( S > 0) ss = s/S;
		if( C > 0) cc = c/C;

		canMake = min( { bb, ss, cc } );
		
		ans += canMake;

		// db(canMake);

		b -= canMake*B;
		s -= canMake*S;
		c -= canMake*C;

		int costB = 0 , costS = 0, costC = 0;

		if( bread and sausage and cheese and b == 0 and c == 0 and s == 0)
		{
			ans += tt/(B * pb + S * ps + C * pc );
			break;
		}

		if( bread and sausage and !cheese and  b == 0 and s == 0)
		{
			ans += tt/(B * pb + S * ps );
			break;
		}

		if( bread and cheese and !sausage and b == 0 and c == 0 )
		{
			ans += tt/(B * pb + C * pc );
			break;
		}

		if( sausage and cheese and !bread and c == 0 and s == 0)
		{
			ans += tt/(S * ps + C * pc );
			break;
		}

		if( bread and b == 0 and !sausage and !cheese )
		{
			ans += tt/(B * pb);
			break;
		}

		if( cheese and c == 0 and !bread and !sausage )
		{
			ans += tt/(C * pc);
			break;
		}

		if( sausage and s == 0 and !bread and !cheese )
		{
			ans += tt/(S * ps);
			break;
		}

		if( b < B ) costB = ( B - b ) * pb , b += ( B - b );
		if( s < S ) costS = ( S - s ) * ps , s += ( S - s );
		if( c < C ) costC = ( C - c ) * pc , c += ( C - c );

		int tCost = costB + costS + costC;

		// db(tCost);

		if( tt < tCost ) break;
		else tt -= (tCost);
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