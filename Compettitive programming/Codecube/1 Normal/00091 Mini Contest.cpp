#include<bits/stdc++.h>

using namespace std;
int n, pos;
int mark[100100];
char str[100100];
int main()
{
    scanf("%d",&n);
    scanf("%s",&str[1]);
    for( int i = 1 ; i <= n ; i++ ){
        if( str[i] != 'X' ){
            pos = i;
            break;
        }
    }
    str[0] = 'X';
    str[n+1] = 'X';
    if( pos == 0 ){
        str[1] = 'B';
        for( int i = 2 ; i <= n ; i++ ){
            if( str[i-1] == 'B' )str[i] = 'W';
            if( str[i-1] == 'W' )str[i] = 'B';
        }
        for( int i = 1 ; i <= n ; i++ )printf("%c",str[i]);
        return 0;
    }
    for( int i = pos + 1 ; i <= n ; i++ ){
        if( str[i] != 'X' )continue;
        if( str[i+1] == 'X' ){
            if( str[i-1] == 'B' )str[i] = 'W';
            else str[i] = 'B';
        }
        else{
            if( str[i-1] != str[i+1] )str[i] = 'G';
            else if( str[i-1] == 'B' )str[i] = 'W';
            else str[i] = 'B';
        }
    }
    for( int i = pos-1 ; i >= 1 ; i-- ){
        if( str[i] != 'X' ) continue;
        if( str[i-1] == 'X' ){
            if( str[i+1] == 'B' )str[i] = 'W';
            else str[i] = 'B';
        }
        else{
            if( str[i-1] != str[i+1] )str[i] = 'G';
            else if( str[i+1] == 'B' )str[i] = 'W';
            else str[i] = 'B';
        }
    }
    for( int i = 1 ; i <= n ; i++ )printf("%c",str[i]);
    return 0;
}
