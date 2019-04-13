#include<bits/stdc++.h>

using namespace std;
struct stu{
    int l, m;
}a[100100], b[100100];
int n;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d %d",&a[i].l,&a[i].m);
    }
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d %d",&b[i].l,&b[i].m);
    }
    for( int i = 0 ; i < n ; i++ ){
        int ma = 0;
        for( int j = 0 ; j < n ; j++ ){
            //printf("%d\n",a[i].m + b[j].m - abs( a[i].l - b[j].l ));
            ma = max( ma, a[i].m + b[j].m - abs( a[i].l - b[j].l ) );
        }
        printf("%d\n",ma);
    }
    return 0;
}
