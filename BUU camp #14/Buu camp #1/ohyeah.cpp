#include<bits/stdc++.h>

using namespace std;

long long n, op;
long long number[200010], sum, s = 1, mark[200010];
int main()
{
    scanf("%lld",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lld",&op);
        //printf("s : %lld\n",s);
        if( op == 1 ){
            long long ai, xi;
            scanf("%lld %lld",&ai,&xi);
            if( ai > s ){
                ai = s;
            }
            //printf("%lld %lld\n",ai,xi);
            mark[ai - 1] += xi;
            //printf("%lld %lld\n",ai,xi);
            sum += ai * xi;
        }
        else if( op == 2 ){
            long long ki;
            scanf("%lld",&ki);
            sum += ki;
            number[s] = ki;
            s++;
        }
        else{
            //printf("%d\n",number[s - 1]);
            sum -= ( number[s - 1] + mark[s - 1] );
            mark[s - 2] += mark[s - 1];
            number[s - 1] = 0;
            mark[s - 1] = 0;
            s--;
        }
        printf("%lld %lld\n",sum,s);
    }
    return 0;
}
