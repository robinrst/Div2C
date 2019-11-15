#include        "iostream"
#include        "algorithm"
#include 		"cstring"
#include 		"string"
#include        "vector"
#include		"ctime"
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
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);   
	    freopen("output.txt","w",stdout);
	#endif 
}

const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,m,k,q;
string s;
int fr2[N],fr1[N];
pii a[N];
vpii ff,ss;


void go()
{
	cin>>n;

	int mx = 0, o = 0, e = 0;

	fo(i,1,n+1)
	{
		int x; 
		cin>>x;
		a[i] = { x, i };

		mx = max( mx , a[i].f );
	}

	sort(a, a+n );
	int sum1 = 0 , sum2 = 0;

	fo(i,1,n+1)
	{
		if( i&1 ) 
		{	
			sum1 += a[i].f;
			ff.pb( a[i] );
		}
		else
		{
			sum2 += a[i].f;
			ss.pb( a[i] );
		}
	}

	cout << sz(ff) << endl;

	fo(i,0,sz(ff))
	{
		cout << ff[i].sc << ' ';
	}
	cout << endl;

	cout << sz(ss) << endl;

	fo(i,0,sz(ss))
	{
		cout << ss[i].sc << ' ';
	}	
	cout << endl;
	
}

int32_t main()
{
	INP(); 
	FAST;	
	int t=1; 
	// cin>>t;
	test(t) go();
}