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

inline void start()
{

	#ifndef O_J
	   	freopen("input.txt","r",stdin);   
	   	freopen("output.txt","w",stdout);
	#endif 
}

int n,m,k,q;
string s;
vi adj[N];
int a[N];
vpii v;

void go()
{
	cin>>s;

	n = sz(s);

	for(int i = 0; i < n; )
	{
		int j = i;
		int cn = 0;

		while( j < n and s[j] == s[i] ) j++, cn++;

		v.pb({cn,i}); // count of consective similar 

		i = j;
	}	

	int pre = 0; // to check whether previous have count of 2 or not

	fo(i,0,sz(v))
	{
		if( v[i].f > 2 )
		{
			if( pre ) cout << s[ v[i].sc ], pre = 0;
			else cout << s[ v[i].sc] << s[ v[i].sc ] , pre = 1;
		}
		else if( v[i].f == 2 )
		{
			if( i == 0 ) cout << s[ v[i].sc ] << s[ v[i].sc ] , pre = 1;
			else 
			{
				if( pre ) cout << s[v[i].sc] , pre = 0;
				else cout << s[ v[i].sc ] << s[ v[i].sc ] , pre = 1;

			}
		}
		else cout << s[ v[i].sc ], pre = 0;
	}
	cout <<endl;
}

int32_t main()
{
// 	start();	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t=1; 
	// cin>>t;
	test(t) go();
}