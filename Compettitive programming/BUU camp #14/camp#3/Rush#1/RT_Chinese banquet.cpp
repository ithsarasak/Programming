#include<bits/stdc++.h>

using namespace std;
int n, m, mark[1010],k;
char food[1010][20];
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%s",food[i]);
    }
    int now = 0;
    for( int i = 0 ; i < m ; i++ ){
        scanf("%d",&k);
        int co = 0;
        while( 1 ){
            if( !mark[now] ){
                co++;
                now++;
                now %= n;
                if( co == k ){
                    while( mark[now] ){
                        now++;
                        now%=n;
                    }
                    mark[now] = 1;
                    printf("%s\n",food[now]);
                    break;
                }
            }
            else{
                now++;
                now %= n;
            }
        }
    }
    return 0;
}
