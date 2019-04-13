#include<bits/stdc++.h>

using namespace std;
int fen[100100], mu[100100], md[100100];
int n, m;
int query( int idx, int ty )
{
    int sum = 0;
    if( ty == 1 )for( int i = idx ; i > 0 ; i -= ( i & -i ) )sum += fen[i];
    else if( ty == 2 )for( int i = idx ; i > 0 ; i -= ( i & -i ) )sum += mu[i];
    else for( int i = idx ; i > 0 ; i -= ( i & -i ) )sum += md[i];
    return sum;
}
void up( int idx, int va, int ty )
{
    if( ty == 1 )for( int i = idx ; i <= n ; i += ( i & -i ) )fen[i] += va;
    else if( ty == 2 )for( int i = idx ; i <= n ; i += ( i & -i ) )mu[i] += va;
    else for( int i = idx ; i <= n ; i += ( i & -i ) ) md[i] += va;
    return ;
}
int main()
{
    scanf("%d %d",&n,&m);
    while( m-- ){
        int c, f, t;
        scanf("%d %d %d",&c,&f,&t);
        if( c == 1 ){
            up( f, 1, 1 ), up( t + 1, -1, 1 );
            int r = query( f, 1 ), l = query( f - 1, 1 );
            if( r == l )up( f, -1, 3 );
            else if( r > l ){
                if( query( f, 2 ) - query( f-1, 2 ) == 0 )up( f, 1, 2 );
            }
            r = query( t + 1, 1 ), l = query( t, 1 );
            if( l == r )up( t + 1, -1, 2 );
            else if( l > r ){
                if( query( t + 1, 3 ) - query( t, 3 ) == 0 )up( t+1, 1, 3 );
            }
        }
        else if( c == 2 ){
            printf("%d %d\n",query( f, 1 ),query( t, 1 ));
        }
        else{
            printf("%d %d ",query( f, 1 ),query( t, 1 ));
            if( f == t )printf("0 0\n");
            else printf("%d %d\n",query( t, 2 ) - query( f, 2 ), query( t, 3 )- query( f, 3 ));
        }
    }
    return 0;
}

