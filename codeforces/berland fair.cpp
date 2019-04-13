#include <bits/stdc++.h>

using namespace std;
struct ss{
	long long va;
	int pos;
	bool operator<( const ss &k )const{
		if( va == k.va )return pos < k.pos;
		else return va < k.va;
	}
};
struct hh{
	long long va, help;
	bool operator<( const hh &k )const{
		return va < k.va;
	}
}buy[200100];
vector<ss> sor;
long long fen[200100], va[200100], buy2[200100], fen2[200100];
int n;
long long mo, sum, mi = 1e17, ans = 0;
long long pos[200100];
void up( int idx, long long va )
{
	for( int i = idx ; i <= n ; i += ( i & -i ) )fen[i] += va;
	for( int i = idx ; i <= n ; i += ( i & -i ) )fen2[i] += 1;
}
long long query( int idx )
{
	long long sum = 0;
	for( int i = idx ; i > 0 ; i -= ( i & -i ))sum += fen[i];
	return sum;
}
long long query2( int idx ){
	long long sum = 0;
	for( int i = idx ; i > 0 ; i -= ( i & -i ) )sum += fen2[i];
	return sum;
}
int main()
{
	scanf("%d %lld",&n,&mo);
	for( int i = 1 ; i <= n ; i++ ){
		scanf("%lld",&va[i]);
		sum += va[i];
		mi = min( mi, va[i] );
		sor.push_back({ va[i], i });
	}
	sort( sor.begin(), sor.end() );
	for( int i = 0 ; i < sor.size() ; i++ ){
		pos[sor[i].pos] = i + 1;
	}
	for( int i = 1 ; i <= n ; i++ ){
		up( pos[i], va[i] );
		buy[i].va = buy2[i] = query( pos[i] );
		buy[i].help = query2( pos[i] );
	}
	sort( buy + 1, buy + 1 + n );
	sort( buy2 + 1, buy2 + 1 + n );
	ans += n * ( mo / sum );
	mo -= ( mo / sum ) * sum;
	while( mo >= mi ){
		int idx = upper_bound( buy2 + 1, buy2 + 1 + n, mo ) - buy2;
		idx--;
		ans += buy[idx].help;
		mo -= buy[idx].va;
	}
	printf("%lld",ans);
	return 0;
}