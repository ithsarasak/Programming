#include<bits/stdc++.h>

using namespace std;

int n, m, i;
struct de{
    int p, c;
    bool operator<( const de &k )const{
        return p < k.p;
    }
}detect[100010];
long long sum;
int main()
{
    scanf("%d %d",&n,&m);
    for( i = 0 ; i < n ; i++ ){
        scanf("%d %d",&detect[i].p,&detect[i].c);
    }
    sort( detect , detect + n );
    sum += ( long long )detect[0].c;
    for( i = 1 ; i < n ; i++ ){
        if( detect[i].c > detect[i - 1].c ){
            sum += ( long long )( detect[i].c - detect[i - 1].c );
        }
    }
    printf("%lld",sum);
    return 0;
}
