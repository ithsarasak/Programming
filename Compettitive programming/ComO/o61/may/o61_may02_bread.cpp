#include <bits/stdc++.h>
#define pii pair<int ,int>
#define x first
#define y second
using namespace std;

const int N = 1e5+100;
int n, l[N], r[N];
pii seg[4*N];
long long ans;
vector<int> pos[N];

void up( int ll, int rr, int va, int l = 1, int r = n, int now = 1 ) {
	if( l > rr || r < ll || l > r ) return ;
	if( l >= ll && r <= rr ) {
		seg[now].y += va;
		if( seg[now].y > 0 ) seg[now].x = r - l + 1;
		else if( l == r ) seg[now].x = 0;
		else seg[now].x = seg[now<<1].x + seg[now<<1|1].x;
		return ; 
	}
	int mid = ( l + r ) >> 1;
	up( ll, rr, va, l, mid, now<<1 ), up( ll, rr, va, mid+1, r, now<<1|1 );
	if( seg[now].y > 0 ) seg[now].x = r - l + 1;
	else seg[now].x = seg[now<<1].x + seg[now<<1|1].x;
	return ;
}

int main()
{
	for( int i = 0 ; i < 1e5+10 ; i++ ) pos[i].emplace_back( 0 );
	scanf("%d",&n);
	for( int i = 1, bread ; i <= n ; i++ ) {
		scanf("%d",&bread);
		if( r[bread] - l[bread] + 1 == 6 ) {
			up( pos[bread][l[bread]]+1, pos[bread][l[bread]+1], -1 );
			l[bread]++;
		} 
		pos[bread].push_back( i );
		r[bread]++;
		if( r[bread] - l[bread] + 1 == 6 ) up( pos[bread][l[bread]]+1, pos[bread][l[bread]+1], 1 );
		ans += ( long long )seg[1].x;
	}
	printf("%lld",ans);
	return 0;
}