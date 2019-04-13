#include<bits/stdc++.h>
int n, s[100010], sum, now, mins, i, maxs = -9999999;
int main()
{
    scanf("%d",&n);
    for( i = 1 ; i <= n ; i++ ){
        scanf("%d",&s[i]);
        sum += s[i];
        if( s[i] > maxs ){
            maxs = s[i];
        }
    }
    if( maxs < 0 ){
        printf("%d",maxs);
        return 0;
    }
    for( i = 1 ; i <= n ; i++ ){
        if( now + s[i] <= 0 ){
            now += s[i];
            if( now <= mins ){
                mins = now;
            }
        }
        else{
            now = 0;
        }
    }
    printf("%d",sum - mins);
    return 0;
}
