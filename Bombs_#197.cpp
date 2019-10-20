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

int n,m,k,q,cn;
string s;
vpii bomb;

bool comp(pii a, pii b)
{
	return abs(a.f) + abs(a.sc) < abs(b.f) + abs(b.sc); 
}

void print(int quad , int xx , int yy )
{
	char aa, bb, cc, dd;

	if( quad == 1 ) aa = 'R', bb = 'U', cc = 'L' , dd = 'D';
	if( quad == 2 ) aa = 'L', bb = 'U', cc = 'R' , dd = 'D';
	if( quad == 3 ) aa = 'L', bb = 'D', cc = 'R' , dd = 'U';
	if( quad == 4 ) aa = 'R', bb = 'D', cc = 'L' , dd = 'U';

	if( xx != 0 ) 
	{
		cout << "1 ";
		cout << xx << ' ' << aa << endl;
	}
	if( yy != 0 )
	{
		cout << "1 ";
		cout << yy <<' ' << bb << endl;
	}

	cout <<"2\n";

	if( yy != 0 )
	{
		cout << "1 ";
		cout << yy << ' ' << dd << endl;
	} 
	if( xx != 0 )
	{
		cout << "1 ";
		cout << xx << ' ' << cc << endl;
	}

	cout << "3\n";
}

void go()
{
	cin>>n; // bombs

	fo(i,0,n)
	{
		int x,y;
		cin>>x>>y;
		bomb.pb( { x, y } );
		if( x ) cn += 2;
		if( y ) cn += 2;
		cn += 2;
	}

	sort( all(bomb) , comp );

	cout << cn << endl;

	for(auto i : bomb )
	{
		int x = i.f;
		int y = i.sc;

		if( x >= 0 and y >= 0 ) print( 1, x, y );
		else if( x <= 0 and y >= 0 ) print( 2, abs(x), y );
		else if( x <= 0 and y <= 0 ) print( 3, abs(x), abs(y) );
		else if( x >= 0 and y <= 0 ) print( 4, x, abs(y) );
	}
}

int32_t main()
{
	INP(); 
	FAST;	
	int t=1; 
	// cin>>t;
	test(t) go();
}