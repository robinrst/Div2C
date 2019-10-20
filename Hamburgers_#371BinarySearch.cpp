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

int n,m,k,q,S,B,C,s,b,c,ps,pb,pc,tt;
string str;

bool canMake(int mid )
{
	int bread = max( 1LL*mid*B - b , 0LL ) * pb;
	int sausage = max( 1LL*mid*S - s, 0LL ) * ps;
	int cheese = max( 1LL*mid*C - c, 0LL ) * pc;

	// db(bread);
	// db(sausage);
	// db(cheese);

	return (bread + sausage + cheese ) <= tt;
}

void go()
{
	cin>>str;

	int ans  = 0;

	fo(i,0,sz(str))
	{
		if( str[i] == 'S' ) S++;
		if( str[i] == 'B' ) B++;
		if( str[i] == 'C' ) C++; 
	}

	cin>>b>>s>>c;
	cin>>pb>>ps>>pc;
	cin>>tt;

	int l = 0, r = 1e14;

	while( l <= r )
	{
		int mid = ( l + r )/2;

		if( canMake(mid) ) 
		{
		 	ans = mid , l = mid + 1;
		}
		else r = mid - 1;
	}

	cout << ans << endl;

}

int32_t main()
{
// 	INP(); 
	FAST;	
	int t=1; 
	// cin>>t;
	test(t) go();
}