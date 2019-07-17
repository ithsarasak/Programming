#include<bits/stdc++.h>

using namespace std;
int m;
int fen[100100], no[100100], pa[100100], lv = 1;
int main()
{
    scanf("%d",&m);
    while( m-- ){
        int op;
        scanf("%d",&op);
        if( op == 1 ){
                //printf("sd");
            int pri;
            scanf("%d",&pri);
            no[pri] = lv;
            pa[lv] = pri;
            for( int i = pri ; i <= 100000 ; i += ( i & -i ) ){
                fen[i] += 1;
            }
            lv++;
        }
        else if( op == 2 ){
           // printf("sdfsd");
            int sum = 0;
            for( int i = 100000 ; i > 0 ; i -= ( i & -i ) ){
                sum += fen[i];
            }
            if( sum == 0 ){
                printf("0");
                continue;
            }
            int l = 1, r = 1e5;
            //printf("%d\n",sum);
            while( l < r ){
                int mid = ( l + r ) / 2;
                int su = 0;
                for( int i = mid ; i > 0 ; i -= ( i & -i ) ){
                    su += fen[i];
                }
                if( su >= 1 )r = mid;ห
                else l = mid + 1;
            }
            //printf("%d\n",l);
            printf("%d\n",no[l]);
            for( int i = l ; i <= 100000 ; i += ( i & -i ) ){
                fen[i] += -1;
            }
        }
        else{
            int x;
            scanf("%d",&x);
            int su = 0;
            for( int i = pa[x] ; i > 0 ; i -= ( i & -i ) ){
                su += fen[i];
            }
            printf("%d\n",su-1);
        }
    }
}
