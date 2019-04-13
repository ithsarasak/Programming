#include<bits/stdc++.h>

using namespace std;
int mark[400], prime[400];
int num[100010];
int a[1000010], s[1000010], lps[1000010];
int n, m, ans, si;
void genprime( )
{
	memset( num, 1, sizeof num );
	int sq = sqrt( 100000 );
	for(int i=2;i<=sq;i++){
		if(!mark[i]){
			prime[si] = i;
			si++;
			for(int j=i;j<=sq;j+=i) mark[j]=1;
		}
	}
	printf("%d\n",prime[0]);
	for(int i=2;i<=100000;i++){
		int t = i;
		for(int j=0;j<si;j++){
			if(prime[j]>i) break;
			int cnt = 1;
			while( t % prime[j] == 0 ){
				cnt++;
				t /= prime[j];
			}
			num[i] *= cnt;
		}
		if( t != 1 ) num[i] *= 2;
	}
}
int main()
{
	genprime();
	scanf("%d %d",&n,&m);
	for( long long i = 0 ; i < n ; i++ ){
		scanf("%d",&a[i]);
	}
	for( long long i = 0 ; i < m ; i++ ){
		scanf("%d",&s[i]);
	}
	int len = 0, now = 1;
	lps[0] = 0;
	while( now < m ){
        if( num[s[now]] == num[s[len]] ) len++, lps[now] = len, now++;
        else{
            if(len!=0) len=lps[len-1];
            else lps[now]=0, now++;
        }
    }
	int i = 0, j = 0;
	while( i < n ){
        if( n-i < m-j ) break;
		if( num[a[i]] == num[s[j]] ) i++,j++;
		if( ans < j ) ans = j;
		if( ans == m ) break;
		if( i < n && num[a[i]] != num[s[j]] ){
            if(j!=0) j=lps[j-1];
            else i++;
        }
	}
	printf("%d",ans);
	return 0;
}
