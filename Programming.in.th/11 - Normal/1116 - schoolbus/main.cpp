#include<bits/stdc++.h>

using namespace std;
int n, ho[1000010];
int mi[1000010];
double now, dis;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&ho[i]);
    }
    mi[n - 1] = ho[n - 1];
    for( int i = n - 2; i >= 0 ; i-- ){
        mi[i] = min( mi[i + 1] , ho[i] );
    }
    for( int i = 0 ; i < n ; i++ ){
        int te = mi[i];
        if( now < ( double )( ( ho[i] + te ) / 2.00 ) ){
            double t = ( double )ho[i];
            now = ( ho[i] + te ) / 2.00 ;
            dis = max( dis, t - now );
            //printf("n%f t%f %d\n",now,t,te);
            //printf("d%f\n",dis);
        }
        else{
            double t = ( double )ho[i];
            dis = max( dis, t - now );
            //printf("n%f t%f\n",now,t);
           //printf("d%f\n",dis);
        }
    }
    printf("%.6f",dis);
    return 0;
}
/*
5
5
2
7
8
3
*/
