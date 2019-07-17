#include<bits/stdc++.h>

using namespace std;
int q;
long long n;
long long ez[9] = { 3, 7, 31, 127, 8191, 131071, 524287, 2147483647, 2305843009213693951 };
int main()
{
    scanf("%d",&q);
    while( q-- ){
        scanf("%lld",&n);
        int idx = lower_bound( ez, ez+9, n ) - ez;
        if( ez[idx] == n ) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
