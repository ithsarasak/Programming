#include <bits/stdc++.h>

using namespace std;
struct ss{
	int pos, h;
};
int n, m;
stack<ss> s;
int height[100100], sol[100100];
int main()
{
	scanf("%d %d",&n,&m);
	for( int i = 1 ; i <= n ; i++ ){
		scanf("%d",&height[i]);
	}
	s.push({ 1, height[1] });
	sol[1] = 0;
	for (int i = 2 ; i <= n ; ++i ){
		while( !s.empty() && s.top().h > height[i] )s.pop();
		if( s.empty() ){
			sol[i] = 0;
		}
		else sol[i] = max( sol[s.top().pos], height[i] - s.top().h );
		s.push({ i, height[i] });
	}
	sort( sol + 1, sol + 1 + n );
	// cout << n << endl;
	//for( int i = 1 ; i <= n ; i++ )printf("%d ",sol[i]);
	while( m-- ){
		int po;
		scanf("%d",&po);
		int idx = upper_bound( sol + 1, sol + 1 + n, po ) - sol;
		//printf("idx : %d\n", idx);
		printf("%d\n",n-idx+1);
	}
	return 0;
}