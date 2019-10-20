#include        "iostream"
#include        "algorithm"
#include        "cstring"
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
	#ifndef O_J
	    freopen("input.txt","r",stdin);   
	    freopen("output.txt","w",stdout);
	#endif 
}

const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,m,k,q;
string s;
char a[N][N];
int vis[N][N];
vpii walls;
int dx[4] = { 0 , 0, 1, -1 };
int dy[4] = { 1 , -1, 0, 0 };

void dfs(int i, int j)
{
	if( i < 0 || j < 0 || i > n || j > m || a[i][j] == '#' ) return ;

	vis[i][j] = 1;

	fo(kk,0,4)
	{
		int xx = i + dx[kk];
		int yy = j + dy[kk];

		if( xx >= 0 and xx < n and yy >= 0 and yy < m and !vis[xx][yy] )
			dfs(xx,yy);
	}

	if( k > 0 )
	{
		a[i][j] = 'X';
		k--;
	}
}

void go()
{
	cin>>n>>m>>k;

	int ok = 0;
	int ii = 0;
	int jj = 0;

	fo(i,0,n)
	{
		fo(j,0,m)
		{
			cin>>a[i][j];
			if( ok == 0 and a[i][j] == '.' ) ii = i, jj = j , ok = 1;
		}
	}
	dfs(ii,jj);

	fo(i,0,n)
	{
		fo(j,0,m) cout << a[i][j];
		cout << endl;
	}
}

int32_t main()
{
// 	INP(); 
	FAST;	
	int t=1; 
	// cin>>t;
	test(t) go();
}