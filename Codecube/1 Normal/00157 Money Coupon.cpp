#include<bits/stdc++.h>

using namespace std;
long long mon;
int n, t, ch;
char c;
vector<int> p,mi,mul;
int main()
{
    scanf("%d",&n);
    while(n--){
        scanf(" %c %d",&c,&t);
        if(c=='+'&&t!=0)p.push_back(t);
        else if(c=='x'){
            if(t==0) ch=1;
            else mul.push_back(t);
        }
        else if(c=='-'&&t!=0)mi.push_back(t);
    }
    for(int i=0;i<p.size();i++) mon+=(long long)p[i];
    for(int i=0;i<mul.size();i++) mon*=(long long)mul[i];
    if( !ch ) for(int i=0;i<mi.size();i++) mon-=(long long)mi[i];
    printf("%lld",mon);
    return 0;
}
