#include        "iostream"
#include        "algorithm"
#include        "vector"
#include 		"ctime"
#include        "queue"
#include        "stack"
#include        "map"
#include        "set"

using namespace std;

#define          f first
#define          lgn 25
#define          endl '\n'
#define          sc second
#define          N (int)1e7+ 5
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

int n,m,k;
string s;
int a[(int)1e6 + 3];
int lp[N+1];
vi prime;
mii mp;
int v[N];


struct Q
{
	int l , r;

}q[(int)5e4 + 20];

void linearSieve()
{
	for(int i = 1 ; i <=N ; i++) lp[i] = i;
	for(int i = 2; i <= N; i++ )
	{
		if( lp[i] == i )
		{
			// lp[i] = i;
			prime.pb(i);
		}

		for(int j = 0; j < (int)sz(prime) and prime[j] <= lp[i] and i*prime[j] <= N ; j++)
		{
			lp[ i * prime[j] ] = prime[j];
		}
	}
}

void pre(int i )
{	
	int pp = -1;

	set<int> st;

	if( lp[i] == i )
	{
		++v[ lp[i] ]; 
		return;
	}

	while( i > 1 )
	{
		if( st.find( lp[i] ) == st.end())
		{
			++v[ lp[i] ];
		}
		st.insert(lp[i]);
		i /= lp[i];
	}
}

void go()
{
	cin>>n;

	fo(i,0,n) cin>>a[i] , pre(a[i]) ;

	cin>>m;

	int mx = 0;

	fo(i,0,m)
	{
		int ll,rr;
		cin>>ll>>rr;

		q[i] = { ll, rr };

		mx = max( mx, rr);
	}

	mx = min( mx, (int) 1e7 );


	fo(i,2,mx+1)
	{
		v[i] += v[i-1];
	}

	fo(i,0,m)
	{
		int xx = q[i].l;
		int yy = q[i].r;

		if( yy > (int)1e7 ) yy = (int)1e7;
		if( xx > (int)1e7 ) xx = (int)1e7;

		cout<< v[ yy ] - v[ xx - 1 ] << endl;
	}
}

int32_t main()
{
// 	INP(); 
	FAST;	
	int t=1; 
	linearSieve();
	
	test(t) go();
	time();
}