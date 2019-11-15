#include        "iostream"
#include        "algorithm"
#include		"numeric"
#include        "cstring"
#include        "math.h"
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
#define          PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286


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

int n,X1,X2,Y1,Y2;
string s;

queue< pii > q;
map< pii, int > valid;
map< pii , int > dist;

void go()
{
	cin>>X1>>Y1>>X2>>Y2;
	cin>>n;

	fo(i,0,n)
	{
		int a,b,row;
		cin>>row;
		cin>>a>>b;

		fo(j,a,b+1) valid[ { row, j } ] = 1;
	}

	q.push( { X1, Y1 } );
	dist.insert( { { X1, Y1 } , 0 } );

	while( !q.empty() )
	{
		auto point = q.front();
		q.pop();

		int x = point.f;
		int y = point.sc;

		fo(i,-1,2)
		{
			fo(j,-1,2)
			{
				int xx = x + i;
				int yy = y + j;

				if( valid.count( { xx, yy } ) and !dist.count( { xx,yy } ) )
				{
					dist[ { xx, yy } ] = dist[ { x, y } ] + 1;
					q.push( { xx, yy } );
				}
			}
		}
	} 

	if( dist[ { X2, Y2 } ] ) cout << dist[ { X2, Y2 } ] << endl;
	else cout << -1 << endl;
	
}

int32_t main()
{
	INP(); 
	FAST;     
	int t=1; 
	// cin>>t;
	test(t) go();
}