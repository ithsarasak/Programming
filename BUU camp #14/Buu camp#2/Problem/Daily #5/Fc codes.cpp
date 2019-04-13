#include<bits/stdc++.h>

using namespace std;
int q;
int mic[1000010];
char w[1000010], w2[1000010], ans[1000010];
int main()
{
    scanf("%d",&q);
    while( q-- ){
        memset( mic, 0, sizeof mic );
        scanf("%s",&w[1]);
        scanf("%s",&w2[1]);
        int len = strlen( &w[1] ), len2 = strlen( &w2[1] ), now = 1;
        for( int i = 1 ; i <= len ; i++ ){
            if( w2[now] == w[i] ){
                mic[i] = now;
                now++;
            }
            else{
                now = 1;
                if( w2[now] == w[i] ){
                    mic[i] = now;
                    now++;
                }
                else
                    mic[i] = 0;
            }
            if( now - 1 == len2 ){
                int temp = i;
                temp -= len2;
                while( mic[temp-len2] == len2 ){
                    temp -= len2;
                }
                now = mic[temp] + 1;
            }
        }
        /*for( int i = 1 ; i <= len ; i++ ){
            printf("%d ",mic[i]);
        }
        printf("\n");*/
        int s = 0, st = 0;
        for( int i = len ; i >= 1 ; i-- ){
           // printf("i : %d\n",i);
            if( mic[i] == len2 ){
                st++;
            }
            if( st == 0 ){
                //printf("i : %d\n",i);
                ans[s] = w[i];
                s++;
            }
            if( mic[i] == 1 ){
                if( st > 0 ){
                    st--;
                }
            }
        }
        //printf("S : %d",s);
        if( s == 0 ){
            printf("No COI Secret Code");
        }
        for( int i = s - 1 ; i >= 0 ; i-- ){
            printf("%c",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
