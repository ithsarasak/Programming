#include <bits/stdc++.h>

using namespace std;

int n, cnt = 1;
unordered_map<int, int> m;

int find( int num ) {
    num++;
    while( num % 10 == 0 ) num /= 10;
    return n = num;
}

int main() 
{
    scanf("%d",&n);
    m[n] = 1;
    int x = find( n );
    while( !m[x] ) {
        cnt++, m[x] = 1;
        x = find( n );
    }
    printf("%d",cnt);
    return 0;
}