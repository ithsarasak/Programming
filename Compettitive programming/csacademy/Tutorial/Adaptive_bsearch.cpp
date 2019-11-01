#include <bits/stdc++.h>

using namespace std;

int n;
int main()
{
    scanf("%d",&n);
    int l = 1, r = n;
    while( l < r ) {
        int mid = ( l + r ) >> 1, ans;
        printf("Q %d\n",mid);
        scanf("%d",&ans);
        if( ans == 0 ) r = mid;
        else l = mid + 1;
    }
    printf("A %d",l);
    return 0;
}