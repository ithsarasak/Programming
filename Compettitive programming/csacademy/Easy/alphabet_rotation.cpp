#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> word;
map<string,int> m;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ) {
        string temp;
        cin >> temp;
        int len = temp.length(), x = -1*temp[0] + 26; 
        for( int j = 0 ; j < len ; j++ ) temp[j] = 'a' + ( ( temp[j] + x ) % 26 );
        m[temp]++;
        word.emplace_back( temp );
    }
    for( int i = 0 ; i < n ; i++ ) {
        if( m[word[i]] - 1 ) printf("1\n");
        else printf("0\n");
    }
    return 0;
}