#include<bits/stdc++.h>
char code[10000], ans[100000];
int i , len, j, s;
int main()
{
    scanf("%s",code);
    len = strlen( code );
    for( i = 0 ; i < len ; i++ ){
        if( code[ i + 1 ] < 'A' ){
            for( j = 0 ; j < code[i + 1] - '0' ; j++ ){
                ans[s] = code[i];
                s++;
            }
            i++;
        }
        else{
            ans[s] = code[i];
            s++;
        }
    }
    for( i = 0 ; i < s ; i++ ){
        printf("%c",ans[i]);
    }
    return 0;
}
