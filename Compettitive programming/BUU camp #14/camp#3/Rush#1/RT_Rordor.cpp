#include<bits/stdc++.h>

using namespace std;
char op[10010];
int l, r, b;
int main()
{
    scanf("%s",op);
    int len = strlen( op );
    for( int i = 0 ; i < len ; i++ ){
        if( op[i] == 'L' ) l++;
        else if( op[i] == 'R' ) r++;
        else if( op[i] == 'B' ) b++;
    }
    l %= 4;
    r %= 4;
    b %= 2;
    int t = l-r;
    if( t == 1 || t == -3 ){
        if( b == 1 ) printf("E");
        else printf("W");
    }
    else if( t == 2 || t == -2 ){
        if( b == 1 )printf("N");
        else printf("S");
    }
    else if( t == 3 || t == -1 ){
        if( b == 1 )printf("W");
        else printf("E");
    }
    else if( t == 0 ){
        if( b == 1 )printf("S");
        else printf("N");
    }
    return 0;
}
