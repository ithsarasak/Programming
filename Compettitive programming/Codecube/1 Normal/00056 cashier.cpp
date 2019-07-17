#include<bits/stdc++.h>
using namespace std;
vector<int> v[22],ans;
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		int cnt;
		scanf("%d",&cnt);
		for(int j=1;j<=cnt;j++)
		{
			int xi;
			scanf("%d",&xi);
			v[i].push_back(xi);
		}
		sort(v[i].begin(),v[i].end());
	}
	for(int i=1;i<=q;i++)
	{
		int op,x;
		scanf("%d%d",&op,&x);
		if(op==0&&v[x].size()>0) v[x].erase(v[x].begin());
		else if(op==1)
		{
			int mn = 2e6;
			bool t=0;
			int po;
			vector<int>::iterator it,it2;
			for(int j=1;j<=n;j++)
			{
				if(v[j].size()==0) {t=1; po=j; break;}
				int first=0,last=v[j].size()-1;
				while(first<=last)
				{
					int mid = (first+last)/2;
					if(v[j][mid]<x) first=mid+1;
					else last=mid-1;
				}
			if(mn>first) { mn=first; po=j; }
			}
			if(t) v[po].push_back(x);
			else{
			it2=upper_bound(v[po].begin(),v[po].end(),x);
			v[po].insert(it2,x);
			}
			ans.push_back(po);
		}
	}
	for(auto j : ans) printf("%d\n",j);
}

