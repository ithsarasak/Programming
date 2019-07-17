#include <bits/stdc++.h>

using namespace std;
struct qq{
	int idx;
	long long pr;
	bool operator<( const qq &k )const{
		if( pr == k.pr )return k.idx < idx;
		else return k.pr < pr;
	}
}tt;
int n, m;
long long a[100100], c[100100];
priority_queue<qq> q;
int main()
{
	scanf("%d %d",&n,&m);
	for( int i = 1 ; i <= n ; i++ )scanf("%lld",&a[i]);
	for( int i = 1 ; i <= n ; i++ ){
		scanf("%lld",&c[i]);
		q.push({ i, c[i] });
	}
	while( m-- ){
		int t;
		long long d, sum = 0;
		scanf("%d %lld",&t,&d);
		if( a[t] >= d ){
			printf("%lld\n",c[t]*d);
			a[t] -= d;
			continue;
		}
		sum += a[t]*c[t];
		// printf("%lld %lld %lld %lld\n",sum,a[t],c[t],d);
		d -= a[t], a[t] = 0;
		while( !q.empty() && d > 0 ){
			tt = q.top();
			// printf("%d %lld %lld %lld\n",tt.idx,a[tt.idx],c[tt.idx],sum);
			long long ith = min( d, a[tt.idx] );
			sum += c[tt.idx] * ith;
			d -= ith;
			a[tt.idx] -= ith;
			if( a[tt.idx] == 0 )q.pop();
		}
		if( !d )printf("%lld\n",sum);
		else printf("0\n");
	}
	return 0;
}