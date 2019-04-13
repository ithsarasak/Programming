#include <bits/stdc++.h>

#define pii pair<int, int>
#define iii tuple<int, int, int>
#define x first
#define y second
#define mp make_pair
#define mt make_tuple
#define m3( a, b, c ) max( a, max( b, c ) )

using namespace std;

struct item{
	iii data;
	item* l;
	item* r;
	item() {}
	item( iii data, item* l, item* r ) : data(data), l(l), r(r) { }	
};

iii merge( int l, int mid, int r, int al, int bl, int cl, int ar, int br, int cr ) {
	int are, bre, cre, le = mid - l + 1, le2 = r - mid;
	are = max( al, ( le == bl )*(le + ar) );
	cre = max( cr, ( le2 == br )*(cl + le2) );
	bre = m3( are, cre, m3( cl+ar, bl, br ) );
	return mt( are, bre, cre );
}

item* newleaf( int maxl, int maxc, int maxr ) {
	return new item( mt( maxl, maxc, maxr ), nullptr, nullptr ) ;
}

item* newpar( int L, int mid, int R, item* l, item* r ) {
	iii t1 = l->data, t2 = r->data;
	return new item( merge( L, mid, R, get<0>(t1), get<1>(t1), get<2>(t1), get<0>(t2), get<1>(t2), get<2>(t2) ), l, r );
}

const int N = 1e5+100;
int n, h[N], q;
vector<pii> coor;
iii no;
item* ver[N], cur;

item* build( int l = 1, int r = n ) {
	if( l == r ) return newleaf( 0, 0, 0 );
	int mid = ( l + r ) >> 1;
	return newpar( l, mid, r, build( l, mid ), build( mid + 1, r ) );
}

item* update( item* p, int idx, int va, int l = 1, int r = n ) {
	if( l == r )return newleaf( 1, 1, 1 );
	int mid = ( l + r ) >> 1;
	if( idx <= mid ) return newpar( l, mid, r, update( p->l, idx, va, l, mid ), p->r );
	else return newpar( l, mid, r, p->l, update( p->r, idx, va, mid + 1, r ) );
}

iii query( item* p, int ll , int rr, int l = 1, int r = n ) {
	if( l > rr || r < ll || l > r )return no;
	if( l >= ll && r <= rr )return p->data;
	int al, bl, cl, ar, br, cr, are, bre, cre; // a = maxl b = maxc c = maxr 
	int mid = ( l + r ) >> 1;
	tie( al, bl, cl ) = query( p->l, ll, rr, l, mid );
	tie( ar, br, cr ) = query( p->r, ll, rr, mid + 1, r );
	if( al == -1 )return mt( ar, br, cr );
	else if( ar == -1 )return mt( al, bl, cl );
	return merge( l, mid, r, al, bl, cl, ar, br, cr ); 
}

int check( int mid, int a, int b, int c ) {
	//printf("%d %d %d %d %d\n",mid, a, b, c, get<1>( query( ver[mid], a, b ) ) );
	if( get<1>( query( ver[mid], a, b ) ) >= c  )return 1;
	else return 0;
}

int main()
{
	no = mt( -1, -1, -1 );
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ){
		scanf("%d",h + i);
		coor.push_back( mp( h[i], i ) );
	}
	sort( coor.begin(), coor.end(), greater<pii>() );
	ver[0] = build();
	for( int i = 1 ; i <= n ; i++ )ver[i] = update( ver[i-1], coor[i-1].y, coor[i-1].x );
	scanf("%d",&q);
	for( int i = 0, a, b, c ; i < q ; i++ ){
		scanf("%d %d %d",&a,&b,&c);
		int l = 1, r = n;
		while( l < r ){
			int mid = ( l + r ) >> 1;
			if( check( mid, a, b, c ) )r = mid;
			else l = mid + 1;
		}
		printf("%d\n",coor[l-1]);
	}
	return 0;
}
