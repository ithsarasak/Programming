#include<bits/stdc++.h>

using namespace std;
char s[100010], w[10]={"codecube"};
int len, ans;
int main()
{
    scanf("%s",s);
    len = strlen( s );
    int pos = 0;
    for( int i = 0 ; i < len ; i++ ){
        while( w[pos] != s[i] ){
            //printf("pos : %d ans : %d\n",pos,ans);
            ans++;
            pos++;
            pos %= 8;
        }
        pos++;
        pos %= 8;
    }
    while( pos != 0 ){
        ans++;
        pos++;
        pos %= 8;
    }
    printf("%d",ans);
    return 0;
}
