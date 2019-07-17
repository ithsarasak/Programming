#include<bits/stdc++.h>

using namespace std;
int p, m, mi = 1e9, pos, k, m1, m2;
int mic[1000100], coin[15], coi[1000100], ans[15], ans2[15];
int main()
{
    scanf("%d %d %d",&p,&m,&k);
    for( int i = 1 ; i <= k ; i++ ){
        scanf("%d",&coin[i]);
    }
    mic[0] = 0;
    coi[0] = -1;
    for( int i = 1 ; i <= m ; i++ ){
        mic[i] = 1e9;
        coi[i] = -1;
    }
    for( int i = 1 ; i <= k ; i++ ){
        if( coin[i] > m )continue;
        for( int j = coin[i] ; j <= m ; j++ ){
            if( mic[j] > mic[j-coin[i]] + 1 ){
                coi[j] = i;
                mic[j] = mic[j-coin[i]] + 1;
            }
        }
    }
    for( int i = p ; i <= m ; i++ ){
        if( mi > mic[i] + mic[i-p] ){
            mi = mic[i] + mic[i-p];
            m1 = mic[i];
            m2 = mic[i-p];
            pos = i;
        }
    }
    /*for( int i = 1 ; i <= m ; i++ ){
        printf("%d ",mic[i]);
    }
    printf("\n");
    for( int i = 1 ; i <= m ; i++ ){
        printf("%d ",coi[i]);
    }*/
    int x = pos;
    while( coi[x] != -1 ){
        ans[coi[x]]++;
        x -= coin[coi[x]];
    }
    x = pos - p;
    while( coi[x] != -1 ){
        ans2[coi[x]]++;
        x -= coin[coi[x]];
    }
    printf("%d %d\n",m1,m2);
    for( int i = 1 ; i <= k ; i++ ){
        printf("%d ",ans[i]);
    }
    printf("\n");
    for( int i = 1 ; i <= k ; i++ ){
        printf("%d ",ans2[i]);
    }
    return 0;
}
