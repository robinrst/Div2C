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
int vis[N],par[N],a[N];

void go()
{
	cin>>n>>k;

	if( n == 1 and k >= 0 )
	{
		if( k == 0 ) 
		{
			cout << n << endl;
		}
		else cout << -1 << endl;
		return;
	}

	int xx;

	if( n&1) m = (n - 1)/2 , xx = k - m + 1 ;
	else m = n/2 , xx = k - m + 1;

	if( k < m ) 
	{
		cout << -1 << endl;
		return;
	}

 	if( n == 2 )
 	{
 		cout << k << ' ' << 2*k << endl;
 	}
 	else if( xx == 0)
 	{
 		fo(i,1,2*m + 2) cout << i << ' ';
 		cout << endl;
 	}
 	else
 	{
 		if( n == 3 )
 		{
 			cout << k << ' ' << 2*k << ' ' << 2*k +1 << endl;
 		}
 		else
 		{
 			cout << xx << ' ' << 2*xx <<' ';

 			n -= 2;

 			int cn = 0;

 			int j = 1;

 			while( cn < n )
 			{
 				if( j != xx and j != 2*xx )
 				{
 					cn++;
 					cout << j <<' ';
 				}
 				j++;
 			}

 			cout << endl;
 		}
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