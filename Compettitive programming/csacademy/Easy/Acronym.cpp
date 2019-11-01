#include <bits/stdc++.h>

using namespace std;

int n, cnt[30], ans;
vector<string> word;
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) {
        string temp;
        cin >> temp;
        word.emplace_back( temp );
        cnt[temp[0]-'a']++;
    }
    for( int i = 0 ; i < n ; i++ ) {
        string temp = word[i];
        int len = temp.length(), mk = 0, cnt2[30];
        for( int j = 0 ; j < 26 ; j++ ) cnt2[j] = cnt[j];
        cnt2[temp[0]-'a']--;
        for( int j = 0 ; j < len ; j++ ) {
            cnt2[temp[j]-'a']--;
            if( cnt2[temp[j]-'a'] < 0 ) {
                mk = 1;
                break;
            }
        }
        if( !mk ) ans++;
    }
    printf("%d",ans);
    return 0;
}