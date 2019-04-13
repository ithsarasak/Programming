#include<bits/stdc++.h>

using namespace std;
int t, ch, bucket[128];
string s;
int main()
{
    scanf("%d",&t);
    for( int j = 1 ; j <= t ; j++ ){
        cin >> s;
        ch = 0;
        memset( bucket , 0 , sizeof bucket );
        for( int i = 0 ; i < s.length() ; i++ ){
            bucket[s[i]]++;
        }
        if( bucket[88] ){
            printf("Case #%d: No - Runtime error\n",j);
        }
        else if( bucket[84] ){
            printf("Case #%d: No - Time limit exceeded\n",j);
        }
        else if( bucket[45] ){
            printf("Case #%d: No - Wrong answer\n",j);
        }
        else{
            printf("Case #%d: Yes\n",j);
        }
    }
}
