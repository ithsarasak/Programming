#include <bits/stdc++.h>

using namespace std;
int t;
long long n, m;
long long calwhite( long long x1, long long y1, long long x2, long long y2 )
{
	long long len = x2 - x1 + 1, wid = y2 - y1 + 1;
	long long whi = len / 2, sum = 0;
	if( len % 2 ){
		if( ( x1 + y1 ) % 2  == 0 ){
			whi++;
		}
		sum = ( wid / 2 ) * ( whi * 2 - 1 );
		if( wid % 2 )sum += whi;
	}
	else{
		sum = wid * whi;
	}
	return sum;
}
long long calblack( long long x1, long long y1, long long x2, long long y2 )
{
	//printf("calwhite %lld\n",calwhite( x1, y1, x2, y2 ) );
	return ( x2 - x1 + 1 ) * ( y2 - y1 + 1 ) - calwhite( x1, y1, x2, y2 );
}

int main()
{
	scanf("%d",&t);
	while( t-- ){
		long long x1, y1, x2, y2, x3, y3, x4, y4;
		scanf("%lld %lld",&n,&m);
		long long allwhite = calwhite( 1, 1, m, n );
		long long allblack = calblack( 1, 1, m, n );
		scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
		long long del = calblack( x1, y1, x2, y2 );
		//printf("%lld %lld %lld\n",allwhite, allblack, del);
		allwhite += del, allblack -= del;
		scanf("%lld %lld %lld %lld",&x3,&y3,&x4,&y4);
		//printf("WTF\n");
		long long f1 = max( x1, x3 ), f2 = min( x2, x4 ), t1 = max( y1, y3 ), t2 = min( y2, y4 );
		if( f1 >= x1 and f1 <= x2 and f1 >= x3 and f1 <= x4 and t1 >= y1 and t1 <= y2 and t1 >= y3 and t1 <= y4 and f2 >= x1 and f2 <= x2 and f2 >= x3 and f2 <= x4 and t2 >= y1 and t2 <= y2 and t2 >= y3 and t2 <= y4 ){
			allwhite -= ( f2 - f1 + 1 ) * ( t2 - t1 + 1 );
			allblack += ( f2 - f1 + 1 ) * ( t2 - t1 + 1 );
			//printf("%lld %lld %lld %lld %lld %lld\n",allwhite, allblack, f1, t1, f2, t2 );
			del = calwhite( x3, y3, x4, y4 ) - calwhite( f1, t1, f2, t2 );
			//printf("%lld %lld\n",calwhite( x3, y3, x4, y4 ),calwhite( f1, t1, f2, t2 ));
			allwhite -= del, allblack += del;
			//printf("%lld %lld %lld\n",del,allwhite,allblack);
		}
		else{
			long long del = calwhite( x1, y1, x2, y2 );
			allwhite -= del, allblack += del;
			//printf("%lld %lld %lld\n",del,allwhite,allblack);
		}
		//printf("\n");
		printf("%lld %lld\n",allwhite,allblack);
	}
	return 0;
}