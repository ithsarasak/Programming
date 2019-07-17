#include<bits/stdc++.h>

using namespace std;
int n;
int k2;
double num[300100], num2[300100];
double sum, mx;
double s, k;
deque<double> q;
int main()
{
    scanf("%d %d",&n,&k2);
    k = ( double )k2;
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lf",&num[i]);
    }
    for( int i = 0 ; i < k2 ; i++ ){
        q.push_back( num[i] );
        sum += num[i];
    }
    s = k;
    mx = sum / k;
    //printf("%f\n",mx);
    for( int i = k2 ; i < n ; i++ ){
        double a = q.front();
        q.push_back( num[i] );
        sum += num[i];
        s += 1.0;
        while( s > k && (sum-a)/(s-1.00)-(sum/s) > 1e-6 ){
            sum -= a;
            s -= 1.0;
            q.pop_front();
            a = q.front();
        }
        if( ( sum / s ) - mx > 1e-6 ){
            mx = sum/s;
        }
    }
    printf("%.1lf",mx);
    return 0;
}
