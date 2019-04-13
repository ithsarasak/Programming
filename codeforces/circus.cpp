#include <bits/stdc++.h>

using namespace std ;

const int N = 5e3+500 ;
char a[N],c[N];
vector<int> can[4];
vector<int> arc, clo, both, both2;
int n, i, j, m;
int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
    scanf("%d",&n);
    scanf("%s",&c[1]);
    scanf("%s",&a[1]); 
    for( int i = 1 ; i <= n ; i++ ){
        if(c[i]=='0'&&a[i]=='0')can[0].push_back( i );
        if(c[i]=='0'&&a[i]=='1')can[1].push_back( i );
        if(c[i]=='1'&&a[i]=='0')can[2].push_back( i );
        if(c[i]=='1'&&a[i]=='1')can[3].push_back( i );
    }

    for( auto it:can[1] )arc.push_back( it );

    for( auto it:can[2] )clo.push_back( it );

    for( auto it:can[3] ){
        if( arc.size() + both.size() <= clo.size() + both2.size() )both.push_back( it );
        else both2.push_back( it );
    }

    int cnta =arc.size() + both.size(), cntb = clo.size() + both2.size();
    while( cntb > cnta && !clo.empty() ){
        cntb--;
        both.push_back(clo.back());
        clo.pop_back();
    }
    while(cnta>cntb&&!arc.empty()){
        cnta--;
        both2.push_back(arc.back());
        arc.pop_back();
    }

    if( cnta != cntb )printf("-1");
    else{
        for(auto it:can[0]){
            if(arc.size()+both.size()<=clo.size()+both2.size())both.push_back(it);
            else both2.push_back(it);
        }
        if(arc.size()+both.size()!=clo.size()+both2.size()){
            cout << "-1";
        }
        else{
            for(auto it:clo)cout << it << " ";
            for(auto it:both2)cout << it << " ";
        }
    }
    return 0;
}