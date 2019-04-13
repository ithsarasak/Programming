#include<bits/stdc++.h>

using namespace std;
int n, k, all[5000010], ans1[3000010], ans2[3000010],s, s2;
int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&all[i]);
    }
    for( int i = 1 ; i <= n ; i++ ){
        if( all[i] > all[i-1] && all[i] > all[i+1] ){
            ans1[s] = all[i];
            s++;
        }
    }
    sort( ans1, ans1 + s , greater<int>() );
    for( int i = 0 ; i < s && s2 < k ; i++ ){
        if( ans1[i] != ans1[i+1] ){
            ans2[s2] = ans1[i];
            s2++;
        }
    }
    if( s2 == 0 ){
        printf("-1");
        return 0;
    }
    if( s2 < k ){
        sort( ans2, ans2 + s2 );
    }
    for( int i = 0 ; i < s2 ; i++ ){
        printf("%d\n",ans2[i]);
    }
    return 0;
}
