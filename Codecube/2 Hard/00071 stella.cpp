#include <bits/stdc++.h>

using namespace std;
struct qq{
	long long mana, pick, h;
	bool operator<( const qq &k )const{
		if( mana == k.mana )return pick > k.pick;
		else return mana < k.mana; 
	}
}t;
priority_queue<qq> q;
int k;
long long sum;
int main()
{
	scanf("%d",&k);
	for( int i = 1 ; i <= k ; i++ ){
		char op;
		scanf(" %c",&op);
		if( op == 'c' ){
			char tt;
			scanf(" %c",&tt);
			if( tt == 'n' ){
				long long m;
				scanf("%lld",&m);
				q.push({ m, i, 100100 });
			}
			else{
				long long m, h;
				scanf("%lld %lld",&m,&h);
				q.push({ m, i, h });
			}
		}
		else{
			while( !q.empty() ){
				t = q.top();
				q.pop();
				if( i < t.pick + t.h ){
					sum += t.mana;
					break;
				}
				else{
					if( t.mana / 2 > 0 )q.push({ t.mana / 2, t.pick + t.h, t.h });
				}
			}
		}
	}
	int cnt = 0;
	while( !q.empty() ){
		t = q.top();
		q.pop();
		if( k < t.pick + t.h ){
			cnt++;
		}
		else{
			if( t.mana / 2 > 0 )q.push({ t.mana / 2, t.pick + t.h, t.h });
		}
	}
	printf("%lld\n%d",sum,cnt);
	return 0;
}