#include<bits/stdc++.h>

using namespace std;
char w1[110], w2[110], te1[110], te2[110];
int q, s1, s2;
int main()
{
    scanf("%d",&q);
    scanf("%s",w1);
    int l1 = strlen( w1 ), i = 0;
    while( w1[i] != '*' ){
        te1[s1] = w1[i];
        s1++;
        i++;
    }
    i++;
    while( w1[i] != '\0' ){
        te2[s2] = w1[i];
        s2++;
        i++;
    }
    //printf("%s %s\n",te1,te2);
    while( q-- ){
        scanf("%s",w2);
        int ch = 0;
        int lq = strlen( w2 ), now = 0;
        if( l1 - lq > 1 ){
            printf("No\n");
        }
        else if( l1 - lq == 1 ){
            for( int i = 0 ; i < s1 ; i++ ){
                if( te1[i] != w2[now] ){
                    ch = 1;
                    break;
                }
                now++;
            }
            for( int i = 0 ; i < s2 && !ch ; i++ ){
                if( te2[i] != w2[now] ){
                    ch = 1;
                    break;
                }
                now++;
            }
            if( ch )printf("No\n");
            else printf("Yes\n");
        }
        else{
            for( int i = 0 ; i < s1 ; i++ ){
                if( te1[i] != w2[i] ){
                    ch = 1;
                    break;
                }
            }
            now = lq - 1;
            for( int i = s2-1 ; i >= 0 && !ch ; i-- ){
                if( te2[i] != w2[now] ){
                    ch = 1;
                    break;
                }
                now--;
            }
            if( ch )printf("No\n");
            else printf("Yes\n");
        }
    }
}
