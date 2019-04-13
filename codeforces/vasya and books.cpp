#include <bits/stdc++.h>

using namespace std;
deque<int> q;
int mark[200100], order[200100], n;
int main()
{
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ){
		int nu;
		scanf("%d",&nu);
		q.push_back( nu );
	}
	for( int i = 0 ; i < n ; i++ ){
		scanf("%d",&order[i]);
	}
	for( int i = 0 ; i < n ; i++ ){
		int cnt = 0;
		while( !mark[order[i]] ){
			cnt++;
			mark[q.front()] = 1;
			q.pop_front();
		}
		printf("%d ",cnt);
	}
	return 0;
}