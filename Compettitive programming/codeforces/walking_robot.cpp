#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;
int n, b, a, fa, dis = 2, cell[N];
int main()
{
    scanf("%d %d %d",&n,&b,&fa);
    a = fa;
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&cell[i]);
    a--;
    while( dis <= n && ( a > 0 || b > 0 ) ) {
        if( cell[dis] ) {
            if( b && a != fa ) b--, a++;
            else a--;
        }
        else {
            if( a ) a--;
            else b--;
        }
        dis++;
    }
    printf("%d",dis-1);
    return 0;
}