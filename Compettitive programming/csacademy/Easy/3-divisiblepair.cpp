#include<bits/stdc++.h>

using namespace std;
long long n, num[100100], mark[3];
int main()
{
    scanf("%lld",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lld",&num[i]);
        mark[num[i] % 3]++;
    }
    printf("%lld",mark[1]*mark[2]+(mark[0]*(mark[0]-1))/2);
}