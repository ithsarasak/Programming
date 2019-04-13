#include<bits/stdc++.h>

using namespace std;
int n, ma, po[100100], po2[100100], cnt = 1, po3[100100];
long long m, supo;
int fw[100100];
void up( int idx )
{
    for( int i = idx ; i <= n ; i += ( i & -i ) ){
        fw[i]++;
    }
}
long long query( int idx )
{
    long long sum  = 0;
    for( int i = n ; i > 0 ; i -= ( i & -i ) ){
        sum += ( long long )fw[i];
    }
    //printf("sum : %lld idx : %d\n",sum,idx);
    for( int i = idx - 1 ; i > 0 ; i -= ( i & -i ) ){
        sum -= ( long long )fw[i];
    }
    //printf("sum : %lld idx : %d\n",sum,idx);
    return sum;
}
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&po[i]);
        po2[i+1] = po[i];
        ma = max( ma, po[i] );
    }
    if( m == 0 ){
        printf("0");
        return 0;
    }
    po2[0] = 0;
    sort( po2, po2 + n + 1 );
    for( int i = 0 ; i < n ; i++ ){
        po[i] = lower_bound( po2, po2 + n + 1, po[i] ) - po2;
    }
    /*for( int i = 0 ; i < n ; i++ ){
        printf("%d ",po[i]);
    }
    printf("\n");*/
    int l = 1, r = ma;
    while( l < r ){
        supo = 0;
        int mid = ( l + r ) / 2;
        //printf("mid : %d\n",mid);
        memset( fw, 0, sizeof fw );
        for( int i = 0 ; i < n ; i++ ){
            if( mid >= po2[po[i]] ){
                supo += query( po[i] );
                up( po[i] );
            }
        }
        if( supo >= m ){
            r = mid;
        }
        else l = mid + 1;
    }
    printf("%d",l);
    return 0;
}
