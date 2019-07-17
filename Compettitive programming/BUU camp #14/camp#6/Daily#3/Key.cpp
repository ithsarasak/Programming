#include<bits/stdc++.h>

using namespace std;
char w1[1010], w2[1010], wq[2010];
int l1, l2, mic[1010][1010], q;
int main()
{
    scanf("%s",&w1[1]);
    scanf("%s",&w2[1]);
    scanf("%d",&q);
    l1 = strlen( &w1[1] );
    l2 = strlen( &w2[1] );
    while( q-- ){
        scanf("%s",&wq[1]);
        memset( mic, 0, sizeof mic );
        for( int i = 0 ; i <= l1 ; i++ ){
            for( int j = 0 ; j <= l2 ; j++ ){
                if( i == 0 && j == 0 ){
                    mic[i][j] = 1;
                }
                else if( i == 0 ){
                    if( w2[j] == wq[j] && mic[i][j-1] == 1 ){
                        mic[i][j] = 1;
                    }
                }
                else if( j == 0 ){
                    if( w1[i] == wq[i] && mic[i-1][j] == 1 ){
                        mic[i][j] = 1;
                    }
                }
                else{
                    if( (w1[i] == wq[i+j] && mic[i-1][j] == 1 )|| (w2[j] == wq[i+j] && mic[i][j-1] == 1 ) ){
                        mic[i][j] = 1;
                    }
                }
            }
        }
        if( mic[l1][l2] )printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
