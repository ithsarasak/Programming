#include<bits/stdc++.h>

using namespace std;
int n;
string s;
int main()
{
    scanf("%d",&n);
    cin >> s;
    for( int i = 0 ; i < n - 1 ; i++ ){
        if( s[i] == s[i + 1] ){
            printf("Wrong Answer\n");
            return 0;
        }
    }
    printf("Accepted");
    return 0;
}
