#include <bits/stdc++.h>

using namespace std;

const long long mul = 1e9 + 7;
int n, mx;
long long ha[30];
map<long long, int> m;
int main()
{
    ha[0] = 1LL;
    for( int i = 1 ; i <= 25 ; i++ ) ha[i] = ha[i-1] * mul;
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) {
        string temp;
        cin >> temp;
        int len = temp.length();
        long long sum = 0;
        for( int j = 0 ; j < len ; j++ ) sum += ha[temp[j]-'a'];
        m[sum]++;
    }
    for( auto it = m.begin() ; it != m.end() ; it++ ) {
        mx = max( mx, it->second );
    }
    printf("%d",mx);
    return 0;
}