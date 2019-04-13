#include<bits/stdc++.h>

using namespace std;
int n;
int per[20];
double va[20], va2[20];
double mx = 18000000.00;
void p( int num, int now )
{
    per[now] = num;
    if( now == n - 1 ){
        double sum1 = 0, sum2 = 0, cnt1 = 0, cnt2 = 0;
        for( int i = 0 ; i < n ; i++ ){
            //printf("%d",per[i]);
            if( per[i] == 1 ){
                sum1 += va[i];
                cnt1 += 1.0;
            }
            else{
                sum2 += va2[i];
                cnt2 += 1.0;
            }
        }
        //cout << " " << cnt1 << " " << sum1 << " " << cnt2 << " " << sum2 << endl;
        double sum =  ( ( 100.0 - cnt1 ) * sum1 ) + ( ( 100.0 - cnt2 ) * sum2 );
        sum = sum / 100.00;
        //cout << " " << mx << " " << sum << endl;
        if( mx - sum > 1e-6 )mx = sum;
        return ;
    }
    p( 1, now + 1 );
    p( 0, now + 1 );
}
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lf",&va[i]);
    }
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lf",&va2[i]);
    }
    p( 1, 0 );
    p( 0, 0 );
    printf("%.2lf",mx);
    return 0;
}
