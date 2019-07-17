#include <bits/stdc++.h>

using namespace std;
struct mm{
	int l, r, va;
}ma, sum, m;
struct an{
	int l, r, va;
	char c;
}ans;
int n;
int righ[100100], lef[100100];
int sumr, suml;
int main()
{
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ){
		char c;
		int be;
		scanf(" %c %d",&c,&be);
		if( c == 'R' ){
			righ[i] = -1*be;
			lef[i] = be;
			sumr += be;
		}
		else{
			righ[i] = be;
			lef[i] = -1*be;
			suml += be;
		}
	}
	ma.l = 1, ma.r = 0, ma.va = 0;
	sum.l = 1, sum.r = 0, sum.va = 0;
	m.l = 0, m.r = 0, m.va = -1e9;
	for( int i = 1 ; i <= n ; i++ ){
		//printf("%d %d\n",sum.va,i);
		if( sum.va + righ[i] < 0 ){
			sum.l = i + 1;
			sum.r = i;
			sum.va = 0;
		}
		else{
			sum.r++;
			sum.va += righ[i];
		}
		if( ma.va < sum.va ){
			ma = sum;
		}
		if( m.va < righ[i] ){
			m.l = m.r = i;
			m.va = righ[i];
		}
	}
	if( ma.va == 0 )ma = m;
	ans.va = sumr + ma.va;
	ans.l = ma.l;
	ans.r = ma.r;
	ans.c = 'R';
	ma.l = 1, ma.r = 0, ma.va = 0;
	sum.l = 1, sum.r = 0, sum.va = 0;
	m.l = -1e9, m.r = 0, m.va = 0;
	for( int i = 1 ; i <= n ; i++ ){
		if( sum.va + lef[i] < 0 ){
			sum.l = i + 1;
			sum.r = i;
			sum.va = 0;
		}
		else{
			sum.r++;
			sum.va += lef[i];
		}
		if( ma.va < sum.va ){
			ma = sum;
		}
		if( m.va < lef[i] ){
			m.l = m.r = i;
			m.va = lef[i];
		}
	}
	if( ma.va == 0 )ma = m;
	if( ans.va < suml + ma.va ){
		ans.va = suml + ma.va;
		ans.l = ma.l;
		ans.r = ma.r;
		ans.c = 'L';
	}
	printf("%c %d %d %d",ans.c,ans.va,ans.l,ans.r);
	return 0;
}