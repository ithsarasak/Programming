#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

struct node{
    long long diff, k;
    bool operator<( const node &p )const{
        if( p.diff == diff ){
            return ( p.k > k );
        }
        return p.diff > diff;
    }
}sum[1000010];
long long i, n, k, sumr[1000001], sumo[1000001], realmax = 0;
char dat[1000001];
int main()
{
    for( i = 0 ; i < 1000002 ; i++ ){
        sum[i].diff = 9999999;
    }
    scanf("%lld %lld",&n,&k);
    scanf("%s",dat);

    int len = strlen( dat );
    for( i = 0 ; i < len ; i++ ){
        if( i != 0 ){
            sumr[i] = sumr[i - 1];
            sumo[i] = sumo[i - 1];
        }
        if( dat[i] == 'R' ){
            sumr[i] += 1;
        }
        else if( dat[i] == 'O' ){
            sumo[i] += 1;
        }
        sum[i].diff = sumo[i] - ( k * sumr[i] );
        sum[i].k = i;
    }
    sort( sum , sum + n );
    long long t = 0, mins, maxs;
    /*for( i = 0 ; i < n ; i++ ){
        printf("%lld %lld ",sum[i].diff,sum[i].k);
    }
    printf("\n");*/
   for( i = 0 ; i <= n ; i++ ){
        if( sum[i].diff == 0 ){
            if( realmax < sum[i].k + 1 ){
                realmax = sum[i].k + 1;
            }
        }
        if( sum[i].diff != sum[t].diff ){
            mins = sum[t].k;
            maxs = sum[ i - 1 ].k;
            t = i;
            if( realmax < maxs - mins ){
                realmax = maxs - mins;
            }
        }
   }
    printf("%lld",realmax);
    return 0;
}
