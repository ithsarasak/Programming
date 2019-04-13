#include<bits/stdc++.h>

using namespace std;
int n;
int num[1000100], num2[1000100];
long long fw[1000100];
long long te[1000100];
long long sum;
long long query( long long num )
{
    long long t = 0;
    for( int i = num ; i > 0 ; i -= i & -i ){
        t += fw[i];
    }
    return t;
}
long long query2( long long num )
{
    long long t = 0, t2 = 0;
    for( int i = num - 1 ; i > 0 ; i -= i & -i ){
        t += fw[i];
    }
    for( int i = n ; i > 0 ; i -= i & -i ){
        t2 += fw[i];
    }
    return t2 - t;
}
void up( long long idx )
{
    for( long long i = idx ; i <= n ; i += i & -i ){
        fw[i] += 1;
    }
}
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&num[i]);
        num2[i] = num[i];
    }
    sort( num2 + 1, num2 + n + 1 );
    for( int i = 1 ; i <= n ; i++ ){
        num[i] = lower_bound( num2 + 1, num2 + n + 1, num[i] ) - num2;
    }
    for( int i = n ; i >= 1 ; i-- ){
        te[i] = query( num[i] );
        up( num[i] );
    }
    memset( fw, 0, sizeof fw );
    for( int i = 1 ; i <= n ; i++ ){
        sum += te[i] * query2( num[i] );
        up( num[i] );
    }
    printf("%lld",sum);
    return 0;
}
