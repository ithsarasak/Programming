#include<bits/stdc++.h>

using namespace std;
struct ss{
    int no, score;
}seg[4000100], zero;
int n, l, r, mark[1000100];
void build( int l, int r, int now )
{
    if( l == r ){
        seg[now].no = l;
        seg[now].score = 0;
        return ;
    }
    int mid = ( l + r ) / 2;
    build( l, mid, now * 2 );
    build( mid + 1, r, now * 2 + 1 );
    if( seg[now*2+1].score > seg[now*2].score ) seg[now].score = seg[now*2+1].score, seg[now].no = seg[now*2+1].no;
    else if( seg[now*2].score > seg[now*2+1].score )seg[now].score = seg[now*2].score, seg[now].no = seg[now*2].no;
    else seg[now].score = seg[now*2+1].score, seg[now].no = max( seg[now*2].no, seg[now*2+1].no );
    return ;
}
void up( int l, int r, int idx, int now, int va )
{
    if( l > idx || r < idx || l > r )return ;
    if( l == r ){
        seg[now].score += va;
        return ;
    }
    int mid = ( l + r ) / 2;
    up( l, mid, idx, now * 2, va );
    up( mid + 1, r, idx, now * 2 + 1, va );
    if( seg[now*2+1].score > seg[now*2].score ) seg[now].score = seg[now*2+1].score, seg[now].no = seg[now*2+1].no;
    else if( seg[now*2].score > seg[now*2+1].score )seg[now].score = seg[now*2].score, seg[now].no = seg[now*2].no;
    else seg[now].score = seg[now*2+1].score, seg[now].no = max( seg[now*2].no, seg[now*2+1].no );
    return ;
}
ss query( int l, int r, int ll, int rr, int now )
{
    if( l > rr || r < ll || l > r )return zero;
    if( l >= ll && r <= rr )return seg[now];
    int mid = ( l+ r ) / 2;
    ss le = query( l, mid, ll, rr, now * 2 );
    ss ri = query( mid + 1, r, ll, rr, now * 2 + 1 );
    ss temp;
    if( ri.score > le.score ) temp.score = ri.score, temp.no = ri.no;
    else if( le.score > ri.score )temp.score = le.score, temp.no = le.no;
    else temp.score = ri.score, temp.no = max( le.no, ri.no );
    return temp;
}
int main()
{
    zero.score = -1e9;
    scanf("%d %d %d",&n,&l,&r);
    build( 1, n, 1 );
    for( int z = 0 ; z < l + r ; z++ ){
        char ch;
        scanf(" %c",&ch);
        if( ch == 'L' ){
            int x, y;
            scanf("%d %d",&x,&y);
            if( !mark[y] )up( 1, n, y, 1, 1 );
        }
        else if( ch == 'C' ){
            int x, y;
            scanf("%d %d",&x,&y);
            if( !mark[y] )up( 1, n, y, 1, 3 );
        }
        else if( ch == 'D' ){
            mark[seg[1].no] = 1;
            up( 1, n, seg[1].no, 1, -1e9 );
        }
        else{
            printf("%d\n",seg[1].no);
        }
    }
    return 0;
}
