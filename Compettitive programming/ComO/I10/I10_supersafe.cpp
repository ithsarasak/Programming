#include<bits/stdc++.h>

using namespace std;
struct cc{
    long long t, v;
}car[500100];
long long n, s;
long long cal( long long s, long long v1, long long t1, long long t2 )
{
    if( s-(v1*(t2-t1)) <= 0 )return 1e9;
    return (s*v1)/(s-(v1*(t2-t1)));
}
int main()
{
    scanf("%lld %lld",&n,&s);
    scanf("%lld %lld",&car[0].t,&car[0].v);
    printf("0\n");
    for( int i = 1 ; i < n ; i++ ){
        scanf("%lld %lld",&car[i].t,&car[i].v);
        long long rev = cal( s, car[i-1].v, car[i-1].t, car[i].t );
        printf("%lld\n",max( (long long)0, car[i].v - rev ));
        car[i].v = min( car[i].v, rev );
    }
    return 0;
}
