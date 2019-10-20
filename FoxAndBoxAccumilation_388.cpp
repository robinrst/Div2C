#include        "iostream"
#include        "algorithm"
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
	#ifndef O_J
	    freopen("input.txt","r",stdin);   
	    freopen("output.txt","w",stdout);
	#endif 
}

const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,m,k,q;
string s;
int vis[N],par[N],a[N];
vpii v;

void go()
{
	cin>>n;

	fo(i,0,n) cin>>a[i];

	sort(a, a + n);

 	v.pb( {1, a[0]} ); // smallest val element

 	int i = 1;
 	int piles = 1;

	while( i < n )
	{
		int ok = 0;

		fo(j,0,sz(v))
		{
			int h = v[j].f;
			int val = v[j].sc;

			if( a[i] != 0 and a[i] >= val and a[i] >= h ) // check whether can put that a[i] on top of pile value.
			{
				ok = 1;
				v[j] = { h+1 , a[i]}; //updating height and top value of that pile.
				break;
			}
		}

		if( !ok ) piles++ , v.pb({ 1, a[i] } ); // need of new pile.
		i++;
	}

	cout << piles << endl;

}

int32_t main()
{
// 	INP(); 
	FAST;	
	int t=1; 
	// cin>>t;
	test(t) go();
}