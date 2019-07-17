#include<bits/stdc++.h>

using namespace std;
long long q, n, fw[1000100], num[100100], fw2[1000100];
long long ans;
void up2( long long idx )
{
    for( long long i = idx ; i <= 1000000 ; i += ( i & -i ) ){
        fw2[i] += 1;
    }
}
void up( long long idx ,long long val )
{
    for( long long i = idx ; i <= 1000000 ; i += ( i & -i ) ){
        fw[i] += val;
    }
}
long long sum( long long idx )
{
    long long re = 0;
    for( long long i = idx ; i > 0 ; i -= ( i & -i ) ){
        re += fw[i];
    }
    return re;
}
long long sum2( long long idx )
{
    long long re = 0;
    for( long long i = idx ; i > 0 ; i -= ( i & -i ) ){
        re += fw2[i];
    }
    return re;
}
int main()
{
    scanf("%d",&q);
    while( q-- ){
        ans = 0;
        memset( fw, 0, sizeof fw );
        memset( fw2, 0, sizeof fw2 );
        scanf("%d",&n);
        for( long long i = 1 ; i <= n ; i++ ){
            scanf("%d",&num[i]);
        }
        for( long long i = n ; i >= 1 ; i-- ){
            ans += sum( num[i] - 1 );
            ans += ( sum2( num[i] - 1 ) * num[i] );
            //prlong longf("%d %d\n",sum( num[i] - 1 ),( sum2( num[i] - 1 ) * num[i] ));
            up( num[i] , num[i] );
            up2( num[i] );
        }
        printf("%lld\n",ans);
    }
    return 0;
}
