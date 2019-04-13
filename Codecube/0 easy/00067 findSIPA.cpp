#include<bits/stdc++.h>

using namespace std;
char w[1010], sipa[5] = {"sipa"};
int pr[10010], c, ans;
int len, now2, ppost;
int main()
{
    scanf("%s",w);
    len = strlen( w );
    for( int i = 0 ; i < len ; i++ ){
        if( w[i] != sipa[now2] && w[i] != sipa[now2] - 32 ){
            now2 = 0;
        }
        //printf("%d %d %c\n",i,now2,sipa[now2]);
        if( w[i] == sipa[now2] || w[i] == sipa[now2] - 32 ){
            now2++;
            //printf("%d %d\n",i,now2);
            if( now2 == 4 ){
                pr[c] = i - 3;
                c++;
                pr[c] = i + 1;
                c++;
                now2 = 0;
                ans++;
            }
        }
    }
    for( int i = 0 ; i < len ; i++ ){
        if( ppost < c ){
            while( i == pr[ppost] ){
                printf("%c",34);
                ppost++;
            }
        }
        printf("%c",w[i]);
    }
    if( ppost != c ){
        printf("%c",34);
    }
    printf("\n");
    printf("%d",ans);
    return 0;
}
