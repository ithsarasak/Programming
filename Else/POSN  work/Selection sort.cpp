#include<bits/stdc++.h>

using namespace std ;

vector< int > input, ans;
int n, mins = 999999999, visit[100], pos;

int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        int t;
        scanf("%d",&t);
    input.push_back( t );
    }
    while( !input.empty() ){
        mins = 9999999;
        for( int i = 0 ; i < input.size() ; i ++ ){
            if( input[i] < mins ){
                mins = input[i];
                pos = i;
            }
        }
        ans.push_back( mins );
        input.erase( input.begin() + pos );
    }
    for( int i = 0 ; i < ans.size() ; i++ ){
        printf("%d ",ans[i]);
    }
    return 0;
}
