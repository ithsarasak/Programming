#include<bits/stdc++.h>

using namespace std;
struct dq{
	long long val, pos;
}te;
struct can{
	long long c,x;
	bool operator<( const can &k )const{
		return x < k.x;
	}
}ca[100100];
deque<dq> q;
int n, k;
long long mic[100100];
int main()
{
	scanf("%d %d",&n,&k);
	for( int i = 1 ; i <= n ; i++ ){
		scanf("%lld %lld",&ca[i].x,&ca[i].c);
	}
	sort( ca + 1 , ca + n + 1 );
	for( int i = 1 ; i <= n ; i++ ){
		while( !q.empty() && ca[i].x-q.front().pos > k )q.pop_front();
		if( q.empty() ){
			mic[i] = mic[i-1];
			q.push_back({ mic[i-1] + ca[i].c + ca[i].x, ca[i].x });
			continue;
		}
		te = q.front();
		mic[i] = te.val + ca[i].c - ca[i].x;
		while( !q.empty() && q.back().val < mic[i-1] + ca[i].c + ca[i].x )q.pop_back();
		q.push_back({ mic[i-1] + ca[i].c + ca[i].x, ca[i].x });
		mic[i] = max( mic[i], mic[i-1] );
	}
	printf("%lld",mic[n]);
	return 0;
}

