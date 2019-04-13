#include<bits/stdc++.h>

using namespace std;

struct put{
    int wh, va;
    bool operator<( const put &k )const{
        return wh < k.wh;
    }
}swift2[200100], swift3[200100], swift5[200100], swift7[200100];
int m, n, c2, c3, c5, c7, now2, now3, now5, now7, pos2, pos3, pos5, pos7, maxs = -1;
int main()
{
    scanf("%d %d",&m,&n);
    for( int i = 0 ; i < m ; i++ ){
        int xi, si, ti;
        scanf("%d %d %d",&xi,&si,&ti);
        if( xi == 2 ){
            swift2[c2].wh = si;
            swift2[c2].va += 1;
            c2++;
            swift2[c2].wh = ti + 1;
            swift2[c2].va -= 1;
            c2++;
        }
        else if( xi == 3 ){
            swift3[c3].wh = si;
            swift3[c3].va += 1;
            c3++;
            swift3[c3].wh = ti + 1;
            swift3[c3].va -= 1;
            c3++;
        }
        else if( xi == 4 ){
            swift2[c2].wh = si;
            swift2[c2].va += 2;
            c2++;
            swift2[c2].wh = ti + 1;
            swift2[c2].va -= 2;
            c2++;
        }
        else if( xi == 5 ){
            swift5[c5].wh = si;
            swift5[c5].va += 1;
            c5++;
            swift5[c5].wh = ti + 1;
            swift5[c5].va -= 1;
            c5++;
        }
        else if( xi == 6 ){
            swift2[c2].wh = si;
            swift2[c2].va += 1;
            c2++;
            swift2[c2].wh = ti + 1;
            swift2[c2].va -= 1;
            c2++;
            swift3[c3].wh = si;
            swift3[c3].va += 1;
            c3++;
            swift3[c3].wh = ti + 1;
            swift3[c3].va -= 1;
            c3++;
        }
        else if( xi == 7 ){
            swift7[c7].wh = si;
            swift7[c7].va += 1;
            c7++;
            swift7[c7].wh = ti + 1;
            swift7[c7].va -= 1;
            c7++;
        }
        else if( xi == 8 ){
            swift2[c2].wh = si;
            swift2[c2].va += 3;
            c2++;
            swift2[c2].wh = ti + 1;
            swift2[c2].va -= 3;
            c2++;
        }
        else if( xi == 9 ){
            swift3[c3].wh = si;
            swift3[c3].va += 2;
            c3++;
            swift3[c3].wh = ti + 1;
            swift2[c3].va -= 2;
            c3++;
        }
        else if( xi == 10 ){
            swift2[c2].wh = si;
            swift2[c2].va += 1;
            c2++;
            swift2[c2].wh = ti + 1;
            swift2[c2].va -= 1;
            c2++;
            swift5[c5].wh = si;
            swift5[c5].va += 1;
            c5++;
            swift5[c5].wh = ti + 1;
            swift5[c5].va -= 1;
            c5++;
        }
    }
    sort( swift2 , swift2 + c2 );
    sort( swift3 , swift3 + c3 );
    sort( swift5 , swift5 + c5 );
    sort( swift7 , swift7 + c7 );
    for( int i = 0 ; i < c2 ; i++ ){
        printf("%d %d\n",swift2[i].wh,swift2[i].va);
    }
    printf("\n");
    for( int i = 0 ; i < c3 ; i++ ){
        printf("%d %d\n",swift3[i].wh,swift3[i].va);
    }
    printf("\n");
    for( int i = 0 ; i < c5 ; i++ ){
        printf("%d %d\n",swift5[i].wh,swift5[i].va);
    }
    printf("\n");
    for( int i = 0 ; i < c7 ; i++ ){
        printf("%d %d\n",swift7[i].wh,swift7[i].va);
    }
    printf("\n");
    for( int i = 0 ; i <= n ; i++ ){
        int sum = 0;
        while( i == swift2[pos2].wh ){
            now2 += swift2[pos2].va;
            if( pos2 != c2 - 1 ){
                pos2++;
                break;
            }
        }
        if( i == swift3[pos3].wh ){
            now3 += swift3[pos2].va;
            if( pos3 != c3 - 1 )
            pos3++;
        }
        if( i == swift5[pos5].wh ){
            now5 +=  swift5[pos2].va;
            if( pos5 != c5 - 1 )
                pos5++;
        }
        if( i == swift7[pos7].wh ){
            now7 += swift7[pos2].va;
            if( pos7 != c7 - 1 )
                pos7++;
        }
        sum += now2 + now3 + now5 + now7;
        if( maxs < sum ){
            maxs = sum;
        }
        printf("%d %d %d %d\n",now2,now3,now5,now7);
    }
    printf("%d",maxs);
}
/*
5 10
3 0 4
2 2 3
5 4 7
6 7 9
2 3 3
*/
