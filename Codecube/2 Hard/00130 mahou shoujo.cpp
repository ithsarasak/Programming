#include <bits/stdc++.h>

using namespace std;
struct ss{
	int va, pos;
};
int n, k;
int num[100100], seg[400100], mic[100100], far[100100];
deque<ss> q;
void build( int l, int r, int now )
{
	if( l == r ){
		seg[now] = num[l];
		return ;
	}
	int mid = ( l + r ) / 2;
	build( l, mid, now * 2 );
	build( mid + 1, r, now * 2 + 1 );
	seg[now] = max( seg[now*2], seg[now*2+1] );
	return ;
}
int query( int l, int r, int ll, int rr, int now )
{
	if( l > rr || r < ll || l > r )return -1e9;
	if( l >= ll && r <= rr )return seg[now];
	int mid = ( l + r ) / 2;
	return max( query( l, mid, ll, rr, now * 2 ), query( mid + 1, r, ll, rr, now * 2 + 1 ) );
}
int main()
{
	scanf("%d %d",&n,&k);
	for( int i = 1 ; i <= n ; i++ ){
		scanf("%d",&num[i]);
		int am = 1;
		while( !q.empty() && q.back().va <= num[i] ) {
         	q.pop_back();
      	}
      	if( q.empty() )far[i] = min( k, i );
      	else far[i] = min( k, i - q.back().pos );
      	q.push_back({ num[i], i });
	}
	build( 1, n, 1 );
	mic[1] = num[1];
	for( int i = 2 ; i <= n ; i++ ){
		int ma = query( 1, n, max( 1, i - k + 1 ), i, 1 );
		mic[i] = min( mic[max( 0 , i - k )] + ma, num[i] + mic[i-far[i]] );
	}
	printf("%d",mic[n]);
	return 0;
}