#include "iostream"
#include "vector"

using namespace std;

#define  f first
#define  lgn 25
#define  endl '\n'
#define  sc second
#define  N (int)2e6+5
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
#define  FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  rev(x) reverse(begin(x),end(x))
#define  db(x) cout<<#x <<" : "<< x <<endl;
#define  time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n"
inline void INP()
{
	#ifndef O_J
	    freopen("input.txt","r",stdin);   
	    freopen("output.txt","w",stdout);
	#endif 
}

const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,m,k,q,a,b,v;
string s;
int aa[N],bb[N];

void go()
{
	cin>>s;
	cin>>a>>b;
	n = sz(s);

	int lno = 0 , rno = 0;
	int l = 0, r = n - 1 , po = 1;

	while( l < n and r >= 0 )
	{
		int dl = s[l] - '0';
		int dr = s[r] - '0';

		lno = (lno*10 + dl) % a; // making number from start and taking modulo with 'a' at every step.
		rno = (dr*po + rno) % b;// making number from end and taking modulo with 'b' at every step.
		po = (po % b * 10 % b) % b; // power can be large that's whyu aking its modulo too.

		if( lno == 0 ) aa[l] = 1;
		if( rno == 0 ) bb[r] = 1;

		l++; r--;
	}

	rfo(i,n-1,1)
	{
		if( bb[i] and aa[i-1] and s[i] != '0')
		{
			cout <<"YES\n";

			fo(j,0,i) cout << s[j];

			cout << '\n';

			fo(j,i,n) cout <<s[j];
			return;
		}
	}

	cout <<"NO\n";
}

int32_t main()
{
	// INP(); 
	FAST;	
	int t=1; 
	// cin>>t;
	test(t) go();
}