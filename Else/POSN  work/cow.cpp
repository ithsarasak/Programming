#include<bits/stdc++.h>

using namespace std;

int l = 0, r, n, cow, cow2, use[10010];
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&use[i]);
    }
    scanf("%d",&cow2);
    sort( use , use + n );
    cow2 -= 1;
    r = use[n - 1] - use[0];
    while( l < r ){
        cow = cow2;
        int m = ( l + r ) / 2 + 1;
        //printf("%d %d %d\n",l,m,r);
        int i = 0;
        while( i < n ){
            //printf("cow : %d i : %d\n",cow,i);
            if( use[i] + m > use[n - 1] ){
               break;
            }
            else{
                for( int j = i + 1 ; j <= n ; j++ ){
                    if( use[j] >= use[i] + m ){
                        cow--;
                        i = j;
                        break;
                    }
                }
            }
            if( cow == 0 ){
                break;
            }
        }
        if( cow != 0 ){
            r = m - 1;
        }
        else{
            l = m;
        }
    }
    if( l <= 1 ){
        printf("Cant");
    }
    else{
        cow = cow2;
        int i = 0;
        while( i < n ){
            printf("%d ",use[i]);
            if( cow == 0 ){
                break;
            }
            for( int j = i + 1 ; j <= n ; j++ ){
                if( use[j] >= use[i] + l ){
                    cow--;
                    i = j;
                    break;
                }
            }
        }
        printf("\n%d",l);
    }
        return 0;
}
