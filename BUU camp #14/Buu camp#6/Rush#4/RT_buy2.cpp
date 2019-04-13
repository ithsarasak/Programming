#include<bits/stdc++.h>

using namespace std;
int n;
int num[100100];
long long sum;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&num[i]);
        sum += ( long long )num[i];
    }
    sort( num, num + n, greater<int>() );
    for( int i = 2 ; i < n ; i += 3 ){
        sum -= ( long long )num[i];
    }
    printf("%lld",sum);
    return 0;
}
