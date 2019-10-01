#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int n, ans;
char w[100], word[6][100] = { "CAT", "RAT", "DOG", "PIG", "COW"};
int main()
{
    scanf("%s",w);
    for( int j = 0 ; j < 5 ; j++ ) 
    for( int i = 0 ; i < 3 ; i++ ) {
        ans += abs( w[i] - word[j][i] );
    }
    printf("%d",ans);
    return 0;
}