#include<bits/stdc++.h>

using namespace std;
int n, k, ma;
int sp[1010];
int check( int num )
{
    int sum = 0, co = 1;
    for( int i = 0 ; i < n ; i++ ){
        if( sum + sp[i] > num ){
            co++;
            sum = sp[i];
        }
        else sum += sp[i];
    }
    if( co <= k ) return 1;
    else return 0;
}
int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&sp[i]);
        ma = max( ma, sp[i] );
    }
    int l = ma, r = 2000000;
    while( l < r ){
        int m = ( l + r ) / 2;
        if ( check( m ) ){
            r = m;
        }
        else{
            l = m + 1;
        }
    }
    printf("%d",l);
    return 0;
}
