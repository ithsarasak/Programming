#include<bits/stdc++.h>

using namespace std;

int n;
string x,a[25];
int c[25];
int s[100000];
int main(){
   cin>>n>>x;
	if(n==1){
		cout<<x;return 0;
	}
   int l = x.size();
   int now = n;
   bool p=false;
   for(int i=0;i<l;i++){
		if(i==0){
			s[i]=now--;
			continue;
		}
		if(now==n){
			for(int j =i;j<l&&j<i+n;j++){
				s[j]=now;
			}
			i+=n-1;
			p=false;
		}
		if(now==1){
			for(int j =i;j<l&&j<i+n;j++){
				s[j]=now;
			}
			i+=n-1;
			p=true;
		}

		s[i]=now;
		if(!p)now--;
		else now++;
   }
   for(int i=0;i<l;i++){
		c[s[i]]++;
   }
   for(int i=1;i<=n;i++){
		c[i]+=c[i-1];
	  //  cout<<c[i]<<endl;
   }
   for(int i=0;i<l;i++){
		char sol = x[c[s[i]-1]++];
		cout<<sol;
   }
  /* cout<<endl;
   for(int i=0;i<l;i++){
		cout<<s[i]<<" ";
   }*/
}

