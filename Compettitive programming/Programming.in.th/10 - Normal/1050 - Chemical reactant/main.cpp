#include<bits/stdc++.h>

using namespace std;

struct chem{
    int t[11] = { 0 };
    int pos;
    bool operator<( const chem &c )const{
        for( int ii = 0 ; ii < 10 ; ii++ ){
            if( c.t[ii] != t[ii] ){
                return t[ii] < c.t[ii];
                break;
            }
        }
    }
}all[100010], finds, temp;
int n, p, i, j, last, mid, first;
int main()
{
    scanf("%d %d",&n,&p);
    for( i = 0 ; i < n ; i++ ){
        for( j = 0 ; j < p ; j++ ){
            scanf("%d",&all[i].t[j]);
        }
        all[i].pos = i + 1;
    }
    for( i = 0 ; i < p ; i++ ){
        scanf("%d",&finds.t[i]);
    }
    sort( all , all + n );
    first = 0;
    last = n - 1;
    int check1 = 1;
    while( first <= last ){
        mid = ( first + last ) / 2;
        check1 = 1;
        for( i = 0 ; i < p ; i++ ){
            if( all[mid].t[i] > finds.t[i] ){
                last = mid - 1;
                check1 = 0;
                break;
            }
            else if( all[mid].t[i] < finds.t[i] ){
                first = mid + 1;
                check1 = 0;
                break;
            }
        }
        if( check1 ){
            printf("%d",all[mid].pos);
            return 0;
        }
    }
    for( j = 0 ; j < n ; j++ ){
        first = j + 1;
        last = n - 1;
        while( first <= last ){
            //printf("%d %d %d\n",first,last,finds.t[i] - all[j].t[i]);
            mid = ( first + last ) / 2;
            check1 = 1;
            for( i = 0 ; i < p ; i++ ){
                if( all[mid].t[i] > finds.t[i] - all[j].t[i] ){
                    last = mid - 1;
                    check1 = 0;
                    break;
                }
                else if( all[mid].t[i] < finds.t[i] - all[j].t[i] ){
                    first = mid + 1;
                    check1 = 0;
                    break;
                }
            }
            if( check1 ){
                if( all[j].pos < all[mid].pos )
                    printf("%d %d",all[j].pos,all[mid].pos);
                else
                    printf("%d %d",all[mid].pos,all[j].pos);
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}
