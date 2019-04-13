#include<bits/stdc++.h>

using namespace std;
struct au{
    int a, b;
}coas[200200];
struct dq{
    int pos, en;
};
int qe, n, ans, c;
int need[200200];
deque<dq> q;
int main()
{
    scanf("%d",&qe);
    while( qe-- ){
        memset( need, 0, sizeof need );
        scanf("%d %d",&n,&c);
        for( int i = 0 ; i < n ; i++ ){
            scanf("%d",&coas[i].a);
        }
        for( int i = 0 ; i < n ; i++ ){
            scanf("%d",&coas[i].b);
            coas[i+n] = coas[i];
        }
        int sum = 0, start = -1;
        for( int i = 0 ; i < 2*n ; i++ ){
            if( sum + coas[i].a - coas[i].b < 0 ){
                sum = 0;
                start = -1;
                continue;
            }
            else{
                sum += coas[i].a-coas[i].b;
                if( sum > c )sum = c;
                if( start == -1 ){
                    start = i;
                }
                else{
                    if( i % n == start ){
                        break;
                    }
                }
            }
        }
        if( start == -1 ){
            printf("-1\n");
            continue;
        }
        int i = start - 1;
        i += n;
        i %= n;
        ans = 1;
        while( i != start ){
            need[i] = max( 0, coas[i].b-min( coas[i].a, c ) + need[i + 1] );
            if( need[i] == 0 ){
                ans++;
            }
            i--;
            if( i < 0 ) i += n;
        }
        printf("%d\n",ans);
    }
    return 0;
}
