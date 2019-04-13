#include<bits/stdc++.h>
struct node{
    int x, y;
}all[5010];
int n, m, i, j, re[1010][1010], ans1, ans2;
int main()
{
    scanf("%d %d",&n,&m);
    for( i = 0 ; i < m ; i++ ){
        int a, b;
        scanf("%d %d",&a,&b);
        all[i].x = a;
        all[i].y = b;
        re[a][b] = 1;
        re[b][a] = 1;
    }
    for( i = 0 ; i < m ; i++ ){
        for( j = i + 1 ; j < m ; j++ ){
            if( all[i].x != all[i].y && all[i].x != all[j].x && all[i].x != all[j].y && all[i].y != all[j].x && all[i].y != all[j].y && all[j].x != all[j].y ){
                int counts = 0;
                if( re[all[i].x][all[j].x] == 0 ){
                    counts++;
                }
                if( re[all[i].x][all[j].y] == 0 ){
                    counts++;
                }
                if( re[all[i].y][all[j].x] == 0 ){
                    counts++;
                }
                if( re[all[i].y][all[j].y] == 0 ){
                    counts++;
                }
                if( counts == 1 ){
                    ans1++;
                }
                else if( counts == 0 ){
                    ans2++;
                }
            }
        }
    }
    printf("%d",( ans1 / 2 ) + ( ans2 / 3 ));
    return 0;
}

