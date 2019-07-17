#include<bits/stdc++.h>

using namespace std;
int n;
long long a[30], b[30];
long long sum, suan, t;
long long gcd( long long a, long long b )
{
	if( a % b == 0 ) return b;
	else return gcd( b, a%b );
}
int main()
{
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ){
		scanf("%lld/%lld",&a[i],&b[i]);
		long long tt = a[i] / b[i];
		a[i] -= tt*b[i];
		t += tt;
	}
	suan = b[0];
	for( int i = 1 ; i < n ; i++ ){
		suan = ( ( b[i] * suan ) / ( gcd( b[i], suan ) ) );
	}
	//printf("%lld\n",suan);
	for( int i = 0 ; i < n ; i++ ){
		sum += a[i] * ( suan / b[i] );
	}
	long long t2 = sum / suan;
	if( t2 * suan < sum )t2++;
	t += t2;
	long long t3 = t2*suan - sum;
	printf("%lld\n",t);
	if( t3 == 0 )printf("0");
	else printf("%lld/%lld",t3/gcd(t3,suan),suan/gcd(t3,suan));
	return 0;
}
