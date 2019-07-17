#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;
vector<int> base = { 4, 8, 15, 16, 23, 42 };
int ans[10], mark[50];

int main() 
{
    printf("? 1 2\n");
    fflush( stdout );
    scanf("%d",&a);
    printf("? 1 3\n");
    fflush( stdout );
    scanf("%d",&b);
    printf("? 1 4\n");
    fflush( stdout );
    scanf("%d",&c);
    printf("? 1 5\n");
    fflush( stdout );
    scanf("%d",&d);
    ans[1] = __gcd( a, __gcd( b, __gcd( c, d ) ) );
    //printf("%d\n",ans[1]);
    ans[2] = a / ans[1];
    ans[3] = b / ans[1];
    ans[4] = c / ans[1];
    ans[5] = d / ans[1];
    for( int i = 1 ; i <= 5 ; i++ ) mark[ans[i]]++;
    for( int i = 0 ; i < base.size() ; i++ ) if( !mark[base[i]] ) {
        ans[6] = base[i];
        break;
    }
    printf("! ");
    for( int i = 1 ; i <= 6 ; i++ ) printf("%d ", ans[i]);
    printf("\n");
    fflush(stdout);
    return 0;
}