#include <bits/stdc++.h>

using namespace std;

map<string,int> mp, mp2;
int n;

int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) {
        string s;
        cin >> s;
        mp[s]++;
    }
    for( int i = 1 ; i < n ; i++ ) {
        string s;
        cin >> s;
        mp2[s]++;
    }
    for( auto m : mp ) {
        if( mp2[m.first] != m.second ) {
            cout << m.first;
            return 0;
        }
    }
}