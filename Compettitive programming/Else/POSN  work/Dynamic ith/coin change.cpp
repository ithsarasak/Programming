#include<bits/stdc++.h>

int coin[1000], n, allcoin[1000], price, path[1000];
int main()
{
    path[0] = -1;
    for( int i = 1 ; i < 1000 ; i++ ){
        coin[i] = 9999999;
        path[i] = -1;
    }
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&allcoin[i]);
    }
    scanf("%d",&price);
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 1 ; j <= price ; j++ ){
            if( j >= allcoin[i] ){
                if( coin[j - allcoin[i]] + 1 < coin[j] ){
                    coin[j] = coin[j - allcoin[i]] + 1;
                    path[j] = i;
                }
            }
        }
    }
    printf("%d\nchosen coin : ",coin[price]);
    int pos = price;

    while( path[pos] != -1 ){
        printf("%d ",allcoin[path[pos]] );
        pos -= allcoin[path[pos]];
    }
    return 0;
}
