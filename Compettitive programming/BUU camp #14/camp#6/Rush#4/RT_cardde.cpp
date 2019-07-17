#include<bits/stdc++.h>

using namespace std;
char s[1100];
int len;
unordered_map<char,int> ma;
int mark[6][15];
int ans[4] = { 13, 13, 13 ,13 };
int main()
{
    ma['P'] = 0;
    ma['K'] = 1;
    ma['H'] = 2;
    ma['T'] = 3;
    scanf("%s",s);
    len = strlen( s );
    if( len % 3 != 0 ){
        printf("Wrong");
        return 0;
    }
    for( int i = 0 ; i < len ; i += 3 ){
        if( s[i] != 'P' && s[i] != 'K' && s[i] != 'H' && s[i] != 'T' ){
            //printf("%c",s[i]);
            printf("Wrong");
            return 0;
        }
        if( !isdigit( s[i+1] ) || !isdigit( s[i+2] ) ){
            //printf("RR");
            printf("Wrong");
            return 0;
        }
        int num = 10*(s[i+1]-'0')+s[i+2]-'0';
        if( num == 0 || num > 13 || mark[ma[s[i]]][num] == 1 ){
            //printf("R");
            printf("Wrong");
            return 0;
        }
        mark[ma[s[i]]][num] = 1;
        ans[ma[s[i]]]--;
    }
    for( int i = 0 ; i < 4 ; i++ ){
        printf("%d ",ans[i]);
    }
    return 0;
}
