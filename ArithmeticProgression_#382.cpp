#include "bits/stdc++.h"

using namespace std;

#define  f first
#define  lgn 25
#define  endl '\n'
#define  sc second
#define  N (int)1e5+5
#define  sz(x) x.size()
#define  ll long long int
#define  ld long double
#define  vi vector<int>
#define  vl vector<ll>
#define  vs vector<string>
#define  vc vector<char>
#define  mii map<int,int>
#define  mll map<ll,ll>
#define  pii pair<int,int>
#define  pll pair<ll,ll>
#define  vpll vector<pll>
#define  vpii vector<pii>
#define  test(x) while(x--)
#define  pb push_back
#define  mp make_pair 
#define  eb emplace_back
#define  pq priority_queue
#define  mod(x) x%1000000007
#define  fo(i,a,n) for(int i=a;i<n;i++)
#define  rfo(i,n,a) for(int i=n;i>=a;i--)
#define  mst(a,v,n) fo(i,0,n) a[i]=v
#define  all(x) sort(begin(x),end(x))
#define  allr(x) sort(rbegin(x),rend(x))
#define  rev(x) reverse(begin(x),end(x))
#define  db(x) cout<<#x <<" : "<< x <<endl;
#define  tie ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n,m,q,k;
int adj[N],vis[N],par[N],a[N];
string s;
mii mm,mm1;
vpii diff;
vi ans;

void go()
{   
	mm.clear();
	mm1.clear();

	set<int> st;
	cin>>n;

	int d;
	fo(i,0,n)
	{
		cin>>a[i];
	}
	sort(a,a+n);

	if (n == 1 ) { cout<<-1<<endl; return; }
	else if( n == 2 ) 
	{
		int d = a[1] - a[0]; 
		st.insert( a[0] - d );
		st.insert( a[1] + d );
		if( (d&1) == 0 ) st.insert(( a[0]+d/2 ));

		cout<< st.size() << endl;

		auto sit = st.begin();
		for(; sit != st.end() ; sit++) cout << (*sit) << " ";
		return;
	}
	if(n > 2)
	{
		fo(i,1,n)
		{
			int dd=a[i]-a[i-1];
			mm.insert({dd,i});
			mm1[dd]++;
		}
	}
	if(sz(mm) > 2)
	{
		cout << 0 << endl;
		return;
	}else if( sz(mm) == 1) 
	{   
		auto it=mm1.begin();
		int cd=it->f;
		if(cd == 0)
		{
			cout << 1 << endl;
			cout << a[0] ;
			return ;
		}
		cout<<2<<endl;
		cout<<a[0]-cd<<' '<<a[n-1]+cd<<endl;
		return ;
	}
	else
	{	
		auto it=mm1.begin();
		int cd=it->f;
		it++;
		int cd1 =it->f;
		// cout<<c
		if(cd1 != 2*cd  or mm1[cd1] >1){
			cout<< 0 <<endl;
			return ;
		}
		cout<<1<<endl;
		fo(i,1,n)
		{
			if(a[i] != a[i-1] +cd ){ cout << a[i-1] + cd << endl;  return;}
		}
	}
	return;
}

int32_t main()
{
	ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
	int tt=1; 
	// cin>>tt;
	test(tt)
	{
		go();
	}
}