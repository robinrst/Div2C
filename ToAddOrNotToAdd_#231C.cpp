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

int n,m,k,q,val = inf, change;
string s;
int vis[N],pre[N],a[N];
	
void go()
{
	cin>>n>>k;

	fo(i,1,n+1) cin>>a[i];

	sort(a+1, a+n+1 );

	fo(i,1,n+1) pre[i] = pre[ i - 1 ] + a[ i ];

	int ans = 0, val = 0;

	fo(i,1,n+1)
	{
		int l = 1, r = i , mid, cnt = 0;

		while( l <= r )
		{
			int mid = l+r>>1;

			int len = i - mid + 1;

			if( a[i] * len - ( pre[i] - pre[mid - 1] ) <= k )
			{
				cnt = max( cnt, len);
				r = mid - 1;
			}
			else l = mid + 1;

			if( cnt > ans )
			{	
				ans = cnt;
				val = a[i];
			}
		}
	}
	
	cout << ans << ' ' << val << endl;
}

int32_t main()
{
	INP(); 
	FAST;	
	int t=1; 
	// cin>>t;
	test(t) go();
}