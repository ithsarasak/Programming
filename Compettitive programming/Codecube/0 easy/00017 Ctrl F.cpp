#include<bits/stdc++.h>

using namespace std;
char w[1010], f[1010];
int c, ans;
int now2, ppost, n, m;
int main()
{
    scanf("%d %d",&n,&m);
    scanf("%s",w);
    scanf("%s",f);
    for( int i = 0 ; i < n ; i++ ){
        if( w[i] != f[now2] ){
            now2 = 0;
        }
        //printf("%d %d %c\n",i,now2,sipa[now2]);
        if( w[i] == f[now2] ){
            now2++;
            //printf("%d %d\n",i,now2);
            if( now2 == m ){
                now2 = 0;
                ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
