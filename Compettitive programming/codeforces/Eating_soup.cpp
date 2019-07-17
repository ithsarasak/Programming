#include <bits/stdc++.h>

using namespace std;

int n, mm, chk;

int main()
{
    scanf("%d %d",&n,&mm);
    if( !mm ) return !printf("1\n");
    for( int i = 1 ; i < n && mm ; i += 2 ) mm--, chk++;
    if( n & 1 ) mm--;
    if( mm > 0 ) chk -= mm;
    printf("%d\n",chk);
    return 0;
}