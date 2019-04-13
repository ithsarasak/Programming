#include<bits/stdc++.h>

using namespace std;
char s1[1000010], s2[1000010];
int len1, len2, lps[1000010];
int main()
{
    scanf("%s",s1);
    scanf("%s",s2);
    len1 = strlen( s1 );
    len2 = strlen( s2 );
    int now = 1, len = 0;
    lps[0] = 0;
    while( now < len2 ){
        if( s2[now] == s2[len] ){
            len++;
            lps[now] = len;
            now++;
        }
        else{
            if( len != 0 )len = lps[len-1];
            else lps[now] = 0, now++;
        }
    }
    int i = 0, j = 0;
    while( i < len1 ){
        if( s1[i] == s2[j] )i++,j++;
        if( j == len2 ){
            printf("Lucky\n");
            j = lps[j-1];
            return 0;
        }
        else if( i < len1 && s1[i] != s2[j] ){
            if( j != 0 )j = lps[j-1];
            else i++;
        }
    }
    printf("Unlucky");
    return 0;
}
