#include <bits/stdc++.h>

using namespace std;

long long in;
int t;
int main()
{
    scanf("%d",&t);
    for( int i = 1 ; i <= t ; i++ ){
        scanf("%lld",&in);
        printf("%lld",9*63*in + 9);
    }
    return 0;
}