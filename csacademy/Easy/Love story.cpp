#include<bits/stdc++.h>

using namespace std;
int n, m;
double le[110];
double mid;
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= m ; i++ ){
        scanf("%lf",&le[i]);
        le[i] += le[i-1];
    }
    mid = 1.0*n / 2.0;
    int idx = lower_bound( le + 1, le + 1 + m, mid ) - le;
    if( le[idx] == mid ){
        printf("-1");
    }
    else printf("%d",idx);
    return 0;
}
