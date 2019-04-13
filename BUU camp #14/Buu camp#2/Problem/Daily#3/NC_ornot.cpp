#include<bits/stdc++.h>
using namespace std;
int sum[1000010];
char s[1000010];
int n;
long long ans;
long long cal( long long nn )
{
    nn %= 10007;
    return  ( nn * ( nn + 1 ) ) / 2;
}
int main()
{
    scanf("%d",&n);
    scanf("%s",&s[1]);
    for( int i = 1 ; i <= n ; i++ ){
        if( s[i] == '1' ){
            sum[i] = sum[i - 1] + 1;
        }
        else{
            sum[i] = sum[i - 1] - 1;
        }
    }
    sort( sum + 1 , sum + n + 1 );
    int t = 0;
    sum[0] = -1e9;
    /*for( int i = 1 ; i <= n ; i++ ){
        printf("%d ",sum[i]);
    }
    printf("\n");*/
    for( int i = 1 ; i <= n ; i++ ){
        if( sum[i] == 0 ){
            ans++;
        }
        if( sum[i] != sum[t] ){
            t = i;
            int idx = upper_bound( sum + 1 , sum + n + 1, sum[i] ) - sum;
            //printf("%lld %d\n",ans,i);
            idx -= 1;
            //printf("%d\n",idx);
            ans += cal( ( long long )( idx - i ) );
            ans %= 10007;
        }
    }
    ans %= 10007;
    printf("%lld",ans);
    return 0;
}
