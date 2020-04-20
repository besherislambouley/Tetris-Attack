/*
 * We can process the elements from bottom up. The first time we reach a number, we add it to a stack.
 * The second time we reach a number, we must "remove" it from the stack by swapping it with every number on top
 * of it in the stack until it's the top element in the stack, then we pop it out. Each swap = one action.
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
int n ;
vi ans;
int a[100009] , in[100009] ;
stack<int>st;
int main () {
	scanf("%d",&n);
	for ( int i = 0 ; i < n*2 ; i ++ ) scanf("%d",&a[i]) ;
	for ( int i = 0 ; i < n*2 ; i ++ ) {
		if ( !in [a[i]] ) {
			st.push ( a[i] ) ;
			in [a[i]] = 1 ;
			C ;
		}
		vi ret ;
		while ( st.top() != a[i] ) {
			ret.pb ( st.top() ) ;
			ans.pb ( st.size()) ;
			st .pop () ;
		}
		st .pop();
		for ( int i = ret.size()-1 ; i >=0 ; i -- ) st.push ( ret[i] ) ;
	}
	printf("%d\n",(int)ans.size());
	for ( auto  u : ans ) printf("%d\n",u); 
}
