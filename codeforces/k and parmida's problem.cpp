#include<bits/stdc++.h>

using namespace std;
int n;
long long ans;
int cnt[1000100], cnt2[1000100], num[1000100], key[1000100], mark[1000100], fen[1000100];
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&num[i]);
        key[i] = num[i];
    }
    sort( key + 1, key + 1 + n );
    for( int i = 1 ; i <= n ; i++ ){
        int idx = lower_bound( key + 1, key + 1 + n, num[i] ) - key;
        num[i] = idx;
    }
    for( int i = 1 ; i <= n ; i++ ){
        mark[num[i]]++;
        cnt[i] = mark[num[i]];
    }
    memset( mark, 0, sizeof mark );
    for( int i = n ; i >= 1 ; i-- ){
        mark[num[i]]++;
        cnt2[i] = mark[num[i]];
    }
    /*for( int i = 1 ; i <= n ; i++ ){
        printf("%d ",cnt[i]);
    }
    printf("\n");
    for( int i = 1 ; i <= n ; i++ ){
        printf("%d ",cnt2[i]);
    }
    printf("\n");*/
    for( int i = n ; i >= 1 ; i-- ){
        int sum = 0;
        for( int j = cnt[i] - 1 ; j > 0 ; j -= ( j & -j ) ){
            ans += ( long long )fen[j];
        }
        for( int j = cnt2[i] ; j <= n ; j += ( j & -j ) ){
            fen[j] += 1;
        }

        //printf("%d\n",sum);
    }
    printf("%lld",ans);
    return 0;
}
