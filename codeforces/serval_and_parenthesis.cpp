#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 100;

int n, a, b, sum;
char s[N];
int main() 
{
    scanf("%d %s",&n,&s[1]);
    if( n % 2 ) {
        printf(":(");
        return 0;
    }
    for( int i = 1 ; i <= n ; i++ ) {
        if( s[i] == '(' ) a++;
        else if( s[i] == ')' ) b++;
    }
    a = n / 2 - a, b = n / 2 - b;
    if( a < 0 || b < 0 ) {
        printf(":(");
        return 0;
    } 
    for( int i = 1 ; i <= n ; i++ ) {
        if( s[i] == '?' ) {
            if( a > 0 ) s[i] = '(', a--;
            else s[i] = ')', b--;
        }
    }
    for( int i = 1 ; i <= n ; i++ ) {
        if( s[i] == '(' ) sum++;
        else sum--;
        if( sum < 0 || ( sum == 0 && i < n ) ) {
            printf(":(");
            return 0;
        }
    }
    if( sum ) {
        printf(":(");
        return 0;
    }
    for( int i = 1 ; i <= n ; i++ ) printf("%c",s[i]);
    return 0;
}