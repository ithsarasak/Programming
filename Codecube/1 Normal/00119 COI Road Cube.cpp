#include<bits/stdc++.h>

using namespace std;
struct aa{
    int idx, va;
};
int mic[110][10100], ma[110][10100], n, m, ans, k;
deque<aa> q;
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for( int i = 1 ; i <= n ; i++ ){
		for( int j = 1 ; j <= m ; j++ ){
			scanf("%d",&ma[i][j]);
		}
	}
	for( int i = 1 ; i <= m ; i++ ) mic[n][i] = ma[n][i];
	for( int i = n - 1 ; i > 0 ; i-- ){
        while( !q.empty() )q.pop_back();
        for( int j = 1 ; j <= k ; j++ ){
            while( !q.empty() && q.back().va < mic[i+1][j] ) q.pop_back();
            q.push_back({ j, mic[i+1][j] });
        }
		for( int j = 1 ; j <= m ; j++ ){
			while( !q.empty() && q.front().idx < j - k )q.pop_front();
			while( !q.empty() && j + k <= m && q.back().va < mic[i+1][j+k] )q.pop_back();
			q.push_back({ j+k, mic[i+1][j+k] });
			mic[i][j] = ma[i][j] + q.front().va;
		}
	}
	for( int i = 1 ; i <= m ; i++ )ans = max( ans, mic[1][i] );
	printf("%d",ans);
	return 0;
}
