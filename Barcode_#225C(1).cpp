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
int dp[N][2];

int fun( int i , int type )
{
	int &ans = dp[i][type];

	if( ans != -1 ) return dp[i][type];

	if( i <= 0 ) return ans = 0;

	ans = inf;

	for( int j = x; j <= y ; j++ )
	{
		if( j > i ) break;

		if( type == 0 ) ans = min( ans, preDot[i] - preDot[i - j] + fun( i - j , type^1) );
		else  ans = min( ans, preHash[i] - preHash[i - j] + fun( i - j , type^1) );
	}

	return ans;
}

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
		preDot[j] = preDot[j - 1] + Dot[j];
		preHash[j] = preHash[j - 1] + n - Dot[j];
	}

	memset( dp, -1 , sizeof dp);
	int ans =  min( fun(m,0) , fun(m,1) );

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