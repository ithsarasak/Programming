#include<bits/stdc++.h>

using namespace std;
int n, k, num[50010];
int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&num[i]);
    }
    sort( num + 1 , num + n + 1 );
    for( int i = 1 ; i <= n ; i++ ){
        if( k == 1 ){
            printf("%d",num[i]+num[i]);
            return 0;
        }
        else if( k == n - i + 1 + n - i ){
            printf("%d",num[i] + num[n]);
            return 0;
        }
        else if( k > n - i + 1 + n - i ){
            k -= n - i + 1 + n - i;
        }
        else{
            k--;
            for( int j = i + 1 ; j <= n ; j++ ){
                k--;
                if( k == 0 ){
                    printf("%d",num[i] + num[j]);
                    return 0;
                }
                 k--;
                if( k == 0 ){
                    printf("%d",num[i] + num[j]);
                    return 0;
                }
            }
        }
    }
    return 0;
}
