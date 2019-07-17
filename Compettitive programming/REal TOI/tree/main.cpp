#include<bits/stdc++.h>

using namespace std ;

int i, j, k, n, check;
struct point{
    int x, y;
    bool operator<( const point &k )const{
        if( x != k.x ){
            return x < k.x;
        }
        else{
            return y < k.y;
        }
    }
}a[100010], b[100010];
int main()
{
    for( k = 0 ; k < 5 ; k++ ){
            check = 0;
        scanf("%d",&n);
        for( i = 0 ; i < n - 1 ; i++ ){
            int t1, t2;
            scanf("%d %d",&t1,&t2);
            if( t1 > t2 ){
                a[i].x = t2;
                a[i].y = t1;
            }
            else{
                a[i].x = t1;
                a[i].y = t2;
            }
        }
        sort( a , a + n - 1 );
        for( i = 0 ; i < n - 1 ; i++ ){
            int t1, t2;
            scanf("%d %d",&t1,&t2);
            if( t1 > t2 ){
                b[i].x = t2;
                b[i].y = t1;
            }
            else{
                b[i].x = t1;
                b[i].y = t2;
            }
        }
        sort( b , b + n - 1 );
        for( i = 0 ; i < n - 1 ; i++ ){
            if( a[i].x != b[i].x || a[i].y != b[i].y ){
                check = 1;
            }
        }
        if( check ){
            printf("N\n");
        }
        else{
            printf("Y\n");
        }
    }
    return 0;
}
