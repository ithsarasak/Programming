#include<bits/stdc++.h>

using namespace std;

int T ;
bool cant[10];

int main(){
	scanf("%d",&T);
	for(int q=0;q<T;q++){
		int n ,  m ,sol = 0 ;
		char x[10] ;

		scanf("%d",&n);
		for(int i = 0 ;i<n ; i ++){
			int y  ;
			scanf("%d",&y);
			cant[y]=true;
		}
		scanf("%s",x);
		int c1 = 0 , c2 = 0 ,c = 0 ;
		for(int i=0;i<60;i++){
			int a = i/10;
			int b = i%10;
			if(!cant[a]&&!cant[b])c1++;
		}
		for(int i=0;i<100;i++){
			int a = i/10;
			int b = i%10;
			if(!cant[a]&&!cant[b])c2++;
		}
		int k = (x[3]-'0')*10+(x[4]-'0');
		for(int i=1;i<=k;i++){
			int a = i/10;
			int b = i%10;
			if(!cant[a]&&!cant[b])c++;
		}
		sol+=c*c2,c=0;
		k = (x[0]-'0')*10+(x[1]-'0');
		for(int i=1;i<=k;i++){
			int a = i/10;
			int b = i%10;
			if(!cant[a]&&!cant[b])c++;
		}
		sol+=c*c1*c2;
		k = (x[6]-'0')*10+(x[7]-'0');
		for(int i=1;i<=k;i++){
			int a = i/10;
			int b = i%10;
			if(!cant[a]&&!cant[b])sol++;
		}
		//cout<<sol<<endl;
		int a = sol/6000;
		sol%=6000;
		int b = sol/100;
		sol%=100;
		int cc = sol;
		printf("%d%d:%d%d:%d%d\n",a/10,a%10,b/10,b%10,cc/10,cc%10);
		for(int i=0;i<=9;i++)
			cant[i]=false;

	}
}
