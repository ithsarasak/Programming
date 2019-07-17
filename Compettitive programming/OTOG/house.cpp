#include<bits/stdc++.h>

using namespace std;
struct st{
    int sum, maxl, maxr, maxc;
}seg[800100], zero;
int num[200100];
int n, m;
void build( int idx, int l, int r )
{
    if( l == r ){
        //printf("%d %d %d\n",idx,l,r);
        seg[idx].sum = num[l];
        seg[idx].maxl = max( 0, num[l] );
        seg[idx].maxr = max( 0, num[l] );
        seg[idx].maxc = max( 0, num[l] );
        return ;
    }
    int mid = ( l + r ) / 2;
    build( 2*idx, l, mid );
    build( 2*idx + 1, mid + 1, r );
    st left = seg[2*idx];
    st right = seg[2*idx+1];
    seg[idx].sum = left.sum+right.sum;
    seg[idx].maxl = max( left.maxl, left.sum + right.maxl );
    seg[idx].maxr = max( right.maxr, right.sum + left.maxr );
    seg[idx].maxc = max( right.maxc, max( left.maxc, left.maxr + right.maxl ) );
    return ;
}
st query( int idx, int l, int r, int ll, int rr )
{
    if( l > rr || r < ll || l > r )return zero;
    if( l >= ll && l <= rr && r >= ll && r <= rr ) return seg[idx];
    int mid = ( l + r ) / 2;
    st left = query( idx * 2, l, mid, ll, rr );
    st right = query( idx * 2 + 1, mid + 1, r, ll, rr );
    st temp;
    temp.sum = left.sum + right.sum;
    temp.maxl = max( left.maxl, left.sum + right.maxl );
    temp.maxr = max( right.maxr , right.sum + left.maxr );
    temp.maxc = max( right.maxc, max( left.maxc, left.maxr+right.maxl ) );
    return temp;
}
int main()
{
    zero.sum = 0;
    zero.maxl = -1e9;
    zero.maxr = -1e9;
    zero.maxc = -1e9;
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&num[i]);
    }
    build( 1, 1, n );
    for( int i = 0 ; i < m ; i++ ){
        int f, t;
        scanf("%d %d",&f,&t);
        f++,t++;
        st temp = query( 1, 1, n, f, t );
        printf("%d\n",temp.maxc );
    }
    return 0;
}

