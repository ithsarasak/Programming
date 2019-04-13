#include<bits/stdc++.h>

using namespace std;
int tree[5010], mic[5010], n, k;
int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&tree[i]);
    }
    memset( mic, 127, sizeof mic );
    mic[0] = 0;
    for( int i = 1 ; i <= n ; i++ ){
        int ma = -1e9;
        for( int j = 0 ; j < k && i - j > 0 ; j++ ){
            if( ma < tree[i - j] ){
                ma = tree[i - j];
            }
            mic[i] = min( mic[i], ma + mic[i - j - 1] );
        }
    }
    printf("%d",mic[n]);
    return 0;
}
