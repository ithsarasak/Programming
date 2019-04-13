#include<bits/stdc++.h>

using namespace std;
char num[200010];
int q, ans[5];
int main()
{
    scanf("%d",&q);
    ans[0] = 4;
    ans[1] = 0;
    ans[2] = 0;
    ans[3] = 0;
    while( q-- ){
        scanf("%s",num);
        int len = strlen( num );
        int nu;
        if( len <= 1 ){
            nu = num[0] - '0';
        }
        else nu = 10 * ( num[len-2] - '0' ) + ( num[len-1] - '0' );
        printf("%d\n",ans[nu%4]);
    }
    return 0;
}
