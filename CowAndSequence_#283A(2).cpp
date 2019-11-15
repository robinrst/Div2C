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
int vis[N],D[N],a[N];



class Fenwick
{
public:
    vi BIT;

    void init() 
    {
        int nn = n + 10;
        BIT.clear();
        BIT.resize(nn, 0);
    }

    void update(int i,int val)
    {
        for( ; i <= n ; i += ( i&(-i) ) ) BIT[i] += val;
    }
    
    int query(int i)
    {
        int sum = 0;
        for ( ; i > 0 ; i -= ( i&(-i) ) ) sum += BIT[i];
        return sum;
    }

}fn;
// first initialise every element in BIT array to zero
// 1-based indexing
//query(r) gives [0.....r] sum
//update(i,val) -> update every interval in which val exist 
// at index which is power of 2 stores sum from [0 ......... 2^k]
// at odd index, it store that element as in array
// at even index, not power of 2, sum stores in interal in which bit is 1 in binary.



void go()
{
	cin>>n;

	int size = 1 , sum = 0;

	Fenwick bit;

	bit.init();

	fo(i,0,n)
	{
		int x;
		cin>>x;

		if( x == 1 )
		{
			int ai,xi;
			cin>>ai>>xi;

			bit.update(1,xi);
			bit.update(ai+1,-xi);

			sum += ai*xi;
		}
		if( x == 2 )
		{
			int xi;
			cin>>xi;
			sum += xi;
			bit.update(size+1,xi);
			bit.update(size+2,-xi);
			size++;
		}
		if( x == 3 )
		{
			int xx = bit.query(size);
			sum -= xx;
			bit.update(size,-xx);
			bit.update(size+1,xx);
			size--;
		}

		double avg = double(sum)/size;

		printf("%.9lf\n" , avg);
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