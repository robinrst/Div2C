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

int n,m,k,q,_0,_1;
string s;
vi adj[N];
int vis[N],par[N],a[N],sz[N],Q[N];

void go()
{
	cin >> _0 >> _1;

	string ans = "";

	if( (_1 < _0 - 1) or (_1 > 2*( _0 + 1 )) )
	{
		cout << -1 << endl;
		return;
	}
	else
	{
		if( _1 <= _0 + 1)
		{
			if( _1 == _0 + 1) ans += "1";
			int cn = 0;
			int rest = _1;
			fo(i,0,_0)
			{
				ans += "0";
				if( cn < rest) ans += "1" , ++cn;
			}

			cout << ans << endl;
		}
		else
		{
			fo(i,0,_0)
			{
				ans += "01";
			}
			_1 -= _0;

			if( _1 == 1 ) ans = "1" + ans , cout <<ans;
			else if( _1 == 2) ans = "11" + ans , cout << ans;
			else if( _1 > 2 )
			{
				ans = "11" + ans;
				_1 -= 2;
				int i = 0;
				while( i < sz(ans) )
				{
					if( _1 > 0  and ans[i] == '0' )
					{
						cout << ans[i] <<"1";
						i++;
						--_1;
					}
					else
					{
						cout << ans[i];
						i++;
					}
				}
			}
		}
	}

	

}

int32_t main()
{	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t=1; 
	// cin>>t;
	test(t) go();
}