#include<bits/stdc++.h>

using namespace std;

char s1[1001], s2[1001], ans[1001];
int tarang[1001][1001], len1, len2, s;
int maxs( int a , int b )
{
    if( a  > b ){
        return a;
    }
    else{
        return b;
    }
}
int main()
{
    scanf("%s",s1);
    scanf("%s",s2);
    len1 = strlen( s1 );
    len2 = strlen( s2 );
    for( int j = 0 ; j <= len2 ; j++ ){
        tarang[0][j] = 0;
    }
    for( int i = 0 ; i <= len1 ; i++ ){
        tarang[i][0] = 0;
    }
    for( int i = 1 ; i <= len1 ; i++ ){
        for( int j = 1 ; j <= len2 ; j++ ){
            if( s1[i - 1] == s2[j - 1] ){
                tarang[i][j] = tarang[i - 1][j - 1] + 1;
            }
            else{
                tarang[i][j] = maxs( tarang[i - 1][j] , tarang[i][j - 1] );
            }
        }
    }
    printf("%d\n",tarang[len1][len2]);
    int posx = len1, posy = len2;
    /*for( int i = 1 ; i <= len1 ; i++ ){
        for( int j = 1 ; j <= len2 ; j++ ){
            printf("%d ",tarang[i][j]);
        }
        printf("\n");
    }*/
    while( tarang[posx][posy] != 0 ){
        //printf("%d %d\n",posx,posy);
        if( tarang[posx][posy] != tarang[posx][posy - 1] && tarang[posx][posy] != tarang[posx - 1][posy] ){
            ans[s] = s1[posx - 1];
            posx--;
            posy--;
            s++;
        }
        else{
            if( tarang[posx][posy] == tarang[posx][posy - 1] ){
                posy--;
            }
            else if( tarang[posx][posy] == tarang[posx - 1][posy] ){
                posx--;
            }
        }
    }
    printf("LCS : ");
    for( int i = s - 1 ; i >= 0 ; i-- ){
        printf("%c",ans[i]);
    }
    return 0;
}
