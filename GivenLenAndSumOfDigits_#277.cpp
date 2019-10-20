#include "bits/stdc++.h"

using namespace std;

#define  f first
#define  lgn 25
#define  endl '\n'
#define  sc second
#define  N (int)2e5+5
#define  sz(x) x.size()
#define  int long long int
#define  ld long double
#define  vi vector<int>
#define  vs vector<string>
#define  vc vector<char>
#define  mii map<int,int>
#define  pii pair<int,int>
#define  vpii vector<pii>
#define  test(x) while(x--)
#define  pb push_back
#define  eb emplace_back
#define  pq priority_queue
#define  mod 1000000007
#define  fo(i,a,n) for(int i=a;i<n;i++)
#define  rfo(i,n,a) for(int i=n;i>=a;i--)
#define  mst(a,v,n) fo(i,0,n) a[i]=v
#define  all(x) begin(x),end(x)
#define  allr(x) rbegin(x),rend(x)
#define  rev(x) reverse(begin(x),end(x))
#define  db(x) cout<<#x <<" : "<< x <<endl;
#define time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n"

const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,m,k,q;
string s;
vi adj[N];
int vis[N],par[N],a[N],sz[N],Q[N];

bool check( int x , int y)
{
	return y >= 0 and y <= 9*x;
}

void go()
{
	cin>>n>>m;
	int mm = m;
	string mx = "";
	string mn = "";


	if( n > 0 and m == 0)
	{
		if( n ==1 ) cout << 0 << ' ' << 0 << endl;
		else
		cout << -1 << ' ' << -1 << endl;
		return;
	}

	if( m > 9*n)
	{
		cout << -1 << ' ' << -1 << endl;
		return;
	}

	if( m <= 9 )
	{
		if(n==1)
		{
			cout << m << ' ' << m << endl;
			return;
		}
		mx += to_string(m);
		fo(i,1,n)
		{
			mx += "0";
			if( i!= n-1) mn += "0";
		}
		mn = "1" + mn;
		mn += to_string(m-1);

		cout << mn << ' ' << mx << endl;
		return;
	}

	fo(i,0,n)
	{
		rfo(j,9,0)
		{
			if( m - j >= 0) {mx += to_string(j) , m -= j; break;}

			if( m <= 0) break;
		}
	}

	if( sz(mx) < n )
	{
		int size = n - sz(mx);
		fo(i,0,size) mx += "0";
	}

	fo(i,0,n)
	{
		fo(j,0,10)
		{
			if( ( i > 0 or j > 0 )  and check( n - i - 1 , mm - j ) )
			{
				mn += to_string(j);
				mm -= j;
				break;
			}
		}
	}

	cout << mn << ' ' << mx << endl;

	

}

int32_t main()
{	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t=1; 

	// cin>>t;
	test(t) go();
}