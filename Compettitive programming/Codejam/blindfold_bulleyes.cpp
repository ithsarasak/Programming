#include <bits/stdc++.h>

using namespace std;

int x = 500000000, inf = 1e9;
int firx[9] = { -x, 0, x, -x, 0, x, -x, 0, x };
int firy[9] = { x, x, x, 0, 0, 0, -x, -x, -x };
int sx, sy, lbx, rbx, lby, rby, t, a, b;
int ask( int x, int y ) {
    char s[10];
    printf("%d %d\n",x,y), fflush( stdout );
    scanf(" %s",s);
    if( s[0] == 'M' ) return 0;
    if( s[0] == 'H' ) return 1;
    else return 2;
}

int main()
{
    scanf("%d %d %d",&t,&a,&b);
    while( t-- ) {
        int chk = 0;
        for( int i = 0 ; i < 9 ; i++) {
            int temp = ask( firx[i], firy[i] );
            if( temp == 2 ) {
                chk = 1;
                break;
            }
            if( temp == 1 ) { sx = firx[i], sy = firy[i]; break; }
        }
        if( chk ) continue ;
        int l = sx, r = inf;
        while( l <= r ) {
            int mid = ( l + r ) / 2 ;
            int temp = ask( mid, sy );
            if( temp == 2 ) {
                chk = 1;
                break;
            }
            if( temp == 1 ) rbx = mid, l = mid + 1;
            else r = mid - 1;
        }
        if( chk ) continue ;
        l = -inf, r = sx;
        while( l <= r ) {
            int mid = ( l + r ) / 2;
            int temp = ask( mid, sy );
            if( temp == 2 ) {
                chk = 1;
                break;
            }
            if( temp == 1 ) lbx = mid, r = mid - 1;
            else l = mid + 1;
        }
        if( chk ) continue ;
        l = sy, r = inf;
        while( l <= r ) {
            int mid = ( l + r ) / 2;
            int temp = ask( sx, mid );
            if( temp == 2 ) {
                chk = 1;
                break;
            }
            if( temp == 1 ) rby = mid, l = mid + 1;
            else r = mid - 1;
        }
        if( chk ) continue ;
        l = -inf, r = sy;
        while( l <= r ) {
            int mid = ( l + r ) / 2;
            int temp = ask( sx, mid );
            if( temp == 2 ) {
                chk = 1;
                break;
            }
            if( temp == 1 ) lby = mid, r = mid - 1;
            else l = mid + 1;
        }
        if( chk ) continue ;
        ask( ( rbx + lbx ) / 2 , ( rby + lby ) / 2 );
    }
}