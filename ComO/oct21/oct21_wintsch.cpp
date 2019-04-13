#include <bits/stdc++.h>

using namespace std;
struct work{
	int f, t, mo;
	work() {}
	bool operator<( const work &k )const{
		return t < k.t;
	}
}w[1100];
struct an{
	int va, num;
	vector<int> chose;
	an() {}
}mic[1100];
int n;
int main()
{
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%d %d %d",&w[i].f,&w[i].t,&w[i].mo);
	}
	sort( w + 1, w + 1 + n );
	for( int i = 1 ; i <= n ; i++ ){
		int l = 0, r = i - 1;
		while( l < r ){
			int mid = ( l + r + 1 ) / 2;
			if( w[mid].t > w[i].f )r = mid - 1;
			else l = mid;
		}
		//printf("%d\n",l);
		if( mic[i-1].va > mic[l].va + w[i].mo ){
			mic[i] = mic[i-1];
		}
		else{
			mic[i] = mic[l];
			mic[i].num++, mic[i].va += w[i].mo;
			mic[i].chose.push_back( i );
		}
	}
	printf("%d\n%d\n",mic[n].va,mic[n].num);
	for( int i = 0 ; i < mic[n].chose.size() ; i++ ){
		printf("%d ",mic[n].chose[i]);
	}
	return 0;
}