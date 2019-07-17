#include<bits/stdc++.h>=
int n, i;
long long sum;
int main()
{
    scanf("%d",&n);
    for( int i = n ; i > 0 ; i-- ){
        sum += i * i;
    }
    printf("%lld",sum);
    return 0;
}
