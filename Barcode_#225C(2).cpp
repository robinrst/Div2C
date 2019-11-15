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
#define          N (int)1e3+5
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

int n,m,k,q,x,y;
string s;
int preDot[N],preHash[N],Dot[N];
int dp[2][N];

void go()
{

	cin>>n>>m>>x>>y;

	fo(i,1,n+1)
	{
		fo(j,1,m+1) 
		{
			char ch;
			cin>>ch;

			if( ch == '.' ) Dot[j]++;
		}
	}

	fo(j,1,m+1)
	{
		dp[0][j] = dp[1][j] = inf;
		preDot[j] = preDot[j - 1] + Dot[j];
		preHash[j] = preHash[j - 1] + n - Dot[j];
	}

	fo(i,1,m+1)
	{
		fo(j,x,y+1)
		{
			if( j > i) break;

			dp[0][i] = min( dp[0][i], dp[1][i-j] + (preDot[i] - preDot[i - j]) );
			dp[1][i] = min( dp[1][i], dp[0][i-j] + (preHash[i] - preHash[i - j]) );
		}
	}

	int ans = min( dp[0][m], dp[1][m] );

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