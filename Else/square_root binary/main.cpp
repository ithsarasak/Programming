#include<stdio.h>

int k;
int square_root( int k )
{
    int start = 0;
    int end = k;

    while( start <= end ){
        int m = ( start + end ) / 2;
        if( m * m > k ){
            end = m - 1;
        }
        else if( m * m < k ){
            start = m + 1;
        }
        else{
            return m;
        }
    }
    return end;
}
double square_root_double( double k )
{
    double l = 0, r = k, d = 1e-6;
    while( r - l > d ){
        double m = ( l + r + d ) / 2;
        if( m * m < k ){
            l = m;
        }
        else if( m * m > k ){
            r = m - d;
        }
        else{
            return m;
        }
    }
    return l;
}
int main()
{
    for( int i = 1 ; i <= 100 ; i++ ){
        int ans = square_root( i );
        printf("%d sqrt = %d\n",i,ans);
    }
    for( double i = 1 ; i <= 100 ; i++  ){
        double ans = square_root_double( i );
        printf("%.6f sqrt = %.6f\n",i,ans);
    }
    //scanf("%d",&k);
    return 0;
}
