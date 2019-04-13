#include<bits/stdc++.h>

using namespace std;
int n, ans;
int num[20];
int cal( int num, int po )
{
    int re = 1;
    for( int i = 0 ; i < po ; i++ ){
        re *= num;
    }
    return re;
}
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&num[i]);
        ans += cal( num[i] / 10, num[i] % 10 );
    }
    printf("%d",ans);
    return 0;
}
