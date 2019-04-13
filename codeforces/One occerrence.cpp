#include <bits/stdc++.h>
#define pii pair<int,int>
#define x first 
#define y second
#define mp make_pair

using namespace std;

struct item{
	pii data;
	item* l;
	item* r;
	item() {}
	item( pii data, item* l, item* r ) : data(data), l(l), r(r) { } 
};
item* ver[500100];
item* cur;
int n, num[500100], leftt[500100], last[500100];
int inf = 1e9;
item* newleaf( int pos, int val )
{
	return new item( mp( val, pos ), nullptr, nullptr );
}
item* newpar( item* l, item* r )
{
	return new item( min( l->data, r->data ), l, r );
item* build( int l, int r )
{
	if( l == r )return newleaf( l, inf );
	int m = ( l + r ) >> 1;
	return newpar( build( l, m ), build( m+1, r ) );
}
item* update( item* p, int pos, int val, int l, int r )
{
	if( l == r )return newleaf( pos, val );
	int m = ( l + r ) >> 1;
	if( pos <= m )return newpar( update( p->l, pos, val, l, m ), p->r );
	else return newpar( p->l, update( p->r, pos, val, m+1, r ) );
}
pii query( item* p, int ll, int rr, int l, int r )
{
	//printf("%d %d\n",l,r);
	if( l > rr || r < ll || l > r )return mp( inf, 0 );
	if( l >= ll && r <= rr )return p->data;
	int m = ( l + r ) / 2;
	return min( query( p->l, ll, rr, l, m ), query( p->r, ll, rr, m+1, r ) );
}
int main()
{
	memset( last, -1, sizeof last );
	memset( leftt, -1, sizeof leftt );
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ){
		scanf("%d",&num[i]);
	}
	for( int i = 1 ; i <= n ; i++ ){
		if( last[num[i]] == -1 )leftt[i] = -1;
		else leftt[i] = last[num[i]];
		last[num[i]] = i;
	}
	ver[0] = build( 1, n );
	for( int i = 1 ; i <= n ; i++ ){
		cur = ver[i-1];
		if( leftt[i] != -1 )cur = update( cur, leftt[i], inf, 1, n );
		cur = update( cur, i, leftt[i], 1, n );
		ver[i] = cur;
	}
	int q;
    scanf("%d",&q);
    while( q-- ){
    	int l, r;
    	scanf("%d %d",&l,&r);
    	pii temp = query( ver[r], l, r, 1, n );
    	//printf("\n%d %d\n\n",temp.x,temp.y);
    	if( temp.x < l )printf("%d\n",num[temp.y]);
    	else printf("0\n");
    }
    return 0;
}