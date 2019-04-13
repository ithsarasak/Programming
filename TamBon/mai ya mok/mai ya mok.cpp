#include<bits/stdc++.h>
int i, len;
long long ans = 1, counts = 1;
char s[110];
int main()
{
    scanf("%s",s);
    len = strlen( s );
    for( i = len - 1 ; i >= 0 ; i-- ){
        if( s[i] == 'i' ){
            counts++ ;
        }
        else if( s[i] == ')' ){
            ans *= counts;
            counts = 1;
        }
        else if( s[i] == 'a' ){
            ans *= counts;
            break;
        }
    }
    printf("%lld",ans);
    return 0;
}
