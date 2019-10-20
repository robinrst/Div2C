#include "iostream"

using namespace std;

#define  f first
#define  lgn 25
#define  endl '\n'
#define  sc second
#define  N (int)3e3+5
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

struct B
{
	int cnt = 0 , ii = 0, jj = 0;
};

int n,m,k,q;
string s;
int mainD[5*N],sideD[5*N],a[N][N],cn[N][N];

void go()
{
	cin>>n;

	fo(i,1,n+1)
	{
		fo(j,1,n+1)
		{
			cin>>a[i][j];
			mainD[ i - j + n ] += a[i][j]; // filling main diagonal 
			sideD[ i + j ] += a[i][j]; // filling side diagonal
		}
	}

	B b[2];

	int mx = 0;

	fo(i,1,n+1)
	{
		fo(j,1,n+1)
		{
			cn[i][j] = mainD[ i - j + n ] + sideD[ i + j ] - a[i][j]; // making count of number of points a bishop can make at a[i][j].
			
			int pos = (i+j)&1;

			if( b[pos].cnt <= cn[i][j] ) // updating postion for maximum cn[i][j];
			{
				b[pos].cnt = cn[i][j];
				b[pos].ii = i;
				b[pos].jj = j;
			}
		}
	}

	int ans = b[0].cnt + b[1].cnt;
	cout << ans << endl;

	cout << b[0].ii << ' ' << b[0].jj << ' ' << b[1].ii << ' ' << b[1].jj << endl;

}

int32_t main()
{
// 	INP(); 
	FAST;	
	int t=1; 
	// cin>>t;
	test(t) go();
}