#include<bits/stdc++.h>

using namespace std;
int n;
double num[100010];
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lf",&num[i]);
    }
    sort( num, num + n );
    if( n % 2 ) printf("%.1f",num[n/2]);
    else printf("%.1f",(num[n/2]+num[n/2-1])/2);
    return 0;
}
