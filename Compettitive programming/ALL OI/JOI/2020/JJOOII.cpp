#include<bits/stdc++.h>
using namespace std;
 
int cnt[4][200200];
char str[200200];
unordered_map<char, int> m;
 
int main()
{
	m['J'] = 1;
	m['O'] = 2;
	m['I'] = 3;
	int n, k, ans = 1e9;
	scanf(" %d %d",&n,&k);
	scanf(" %s",str+1);
	for(int i=1 ; i<=n ; i++)
	{
		cnt[m[str[i]]][i]++;
		for(int j=1 ; j<=3 ; j++)
			cnt[j][i] += cnt[j][i-1];
	}
	for(int i=1 ; i<=n-k-k ; i++)
	{
		if(cnt[1][i] >= k)
		{
			int l = 1, r = i;
			while(l!=r)
			{
				int mid = (l+r+1)>>1;
				if(cnt[1][i] - cnt[1][mid-1] >=k) l = mid;
				else r = mid-1;
			}
			int x = l;
			l = i+1, r = n;
			while(l!=r)
			{
				int mid = (l+r)>>1;
				if(cnt[2][mid] - cnt[2][i] >= k) r = mid;
				else l = mid+1;
			}
			if(cnt[2][l] - cnt[2][i] < k || cnt[3][n] - cnt[3][l] < k) goto out;
			int j = l;
			l = j+1, r = n;
			while(l!=r)
			{
				int mid = (l+r)>>1;
				if(cnt[3][mid] - cnt[3][j] >= k) r = mid;
				else l = mid+1;
			}
			int y = l;
			ans = min(ans, y-x+1-k-k-k);
		}
		out: ;
	}
	printf((ans == 1e9) ? "-1\n" : "%d\n", ans);
	return 0;
}