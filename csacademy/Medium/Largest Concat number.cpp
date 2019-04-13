#include<bits/stdc++.h>

using namespace std;
int n;
bool cmp( string s1, string s2 )
{
    string s3 = s1 + s2;
    string s4 = s2 + s1;
    return s3 > s4;
}
int main()
{
    scanf("%d",&n);
    string w[n+1];
    for( int i = 0 ; i < n ; i++ ){
        cin >> w[i];
    }
    sort( w, w + n, cmp );
    if( w[0] == "0" ){
        printf("0");
        return 0;
    }
    for( int i = 0 ; i < n ; i++ ){
        cout << w[i];
    }
    return 0;
}
