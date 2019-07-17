#include <bits/stdc++.h>
#define pli pair<long long, int>
#define w first
#define i second

using namespace std;

const int N = 1e5 +10;
struct e{
	int a, b;
	long long w;
	int i;
	bool operator<( const e &k ) const {
		return w > k.w;
	}
};
vector<e> edge;
vector<int> ee;
vector<pli> trash;
long long ans;
int n, m, cnt, t, par[N];

int findroot( int num ) {
	if( num == par[num] ) return num;
	else return par[num] = findroot( par[num] );
}
int main()
{
	scanf("%d %d",&n,&m);
	for( int i = 1 ; i <= n ; i++ ) par[i] = i;
	for( int i = 1, a, b ; i <= m ; i++ ) {
		long long w;
		//printf("%d %d\n",i,m);
		scanf("%d %d %lld",&a,&b,&w);
		edge.push_back({ a, b, w, i });
	}
	sort( edge.begin(), edge.end() );
	for( int i = 0 ; i < ( int )edge.size() ; i++ ) {
		int a = findroot( edge[i].a ), b = findroot( edge[i].b );
		if( a != b ) {
			ans += edge[i].w;
			par[a] = b;
			ee.emplace_back( edge[i].i );
		}
		else trash.emplace_back( pli( edge[i].w, edge[i].i ) );
	}
	scanf("%d",&t);
	for( int i = 1 ; i <= n ; i++ ) par[i] = findroot( i );
	for( int i = 2 ; i <= n ; i++ ) if( par[i] != par[1] ) {
		printf("-1");
		return 0;
	}
    if( trash.size() == 0 ) {
        printf("-1");
        return 0;
    }
    sort( trash.begin(), trash.end(), greater<pli>() );
	ans += trash[0].w;
    ee.emplace_back( trash[0].i );
	printf("%lld",ans);
	printf("\n");
	if( t == 2 ) for( int i : ee ) printf("%d ",i);
	return 0;
}