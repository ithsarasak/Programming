#include <bits/stdc++.h>

using namespace std;
struct gg{
	int t;
	long long d;
};
struct po{
	long long x, y;
	bool operator<( const po & k )const{
		return x < k.x;
	}
}tt, t2;
struct qu{
	int no;
	long long d;
	bool operator<( const qu &k )const{
		return d > k.d;
	}
}t;
int m, qe, cnt = 1, f, to;
vector<gg> g[300], gr[300];
vector<po> v;
priority_queue<qu> q;
long long dis[300];
long long finddis( po t1, po t2 )
{
	int a = abs( t1.x - t2.x ), b = abs( t1.y - t2.y );
		if( a == b || a > b ){
			return a;
		}
		else if( a < b ){
			if( ( b - a ) % 2 ){
				return  b + 1;
			}
			else{
				return b;
			}
		}
}
int check( po temp )
{
	int ch = 0;
	for( int i = 0 ; i < v.size() ; i++ ){
		if( v[i].x == temp.x && v[i].y == temp.y ){
			ch = 1;
			break;
		}
	}
	return ch;
}
int findpos( po temp )
{
	int pos;
	for( int i = 0 ; i < v.size() ; i++ ){
		if( v[i].x == temp.x && v[i].y == temp.y ){
			pos = i;
			break;
		}
	}
	return pos;
}
int main()
{
	scanf("%d %d",&m,&qe);
	for( int i = 0 ; i < m ; i++ ){
		int ch = 0;
		scanf("%lld %lld %lld %lld",&tt.x,&tt.y,&t2.x,&t2.y);
		if( check( tt ) )f = findpos( tt );
		else{
			v.push_back({ tt.x, tt.y });
			f = v.size() - 1;
		}
		if( check( t2 ) )to = findpos( t2 );
        else {
			v.push_back({ t2.x, t2.y });
			to = v.size() - 1;
		}
		gr[f].push_back({ to, 1 });
		gr[to].push_back({ f, 1 });
	}
	for( int i = 0 ; i < v.size() ; i++ ){
		for( int j = i + 1 ; j < v.size() ; j++ ){
			gr[i].push_back({ j, finddis( v[i], v[j] )});
			gr[j].push_back({ i, finddis( v[i], v[j] )});
		}
	}
	while( qe-- ){
		int st, en, ch = 0;
		for( int i = 0 ; i < 300 ; i++ )g[i].clear();
		fill( dis, dis + 270, 1e17 );
		scanf("%lld %lld %lld %lld",&tt.x,&tt.y,&t2.x,&t2.y);
		for( int i = 0 ; i <= 200 ; i++ ){
			for( int j = 0 ; j < gr[i].size() ; j++ ){
				g[i].push_back({ gr[i][j].t, gr[i][j].d });
			}
		}
        if( check( tt ) )st = findpos( tt );
		else{
			st = v.size() + 1;
			for( int i = 0 ; i < v.size() ; i++ ){
				g[st].push_back({ i, finddis( tt, v[i] ) });
				g[i].push_back({ st, finddis( tt, v[i] ) });
			}
		}
		if( check( t2 ))en = findpos( t2 );
		else{
   			en = v.size() + 2;
			for( int i = 0 ; i < v.size() ; i++ ){
				g[en].push_back({ i, finddis( t2, v[i] ) });
				g[i].push_back({ en, finddis( t2, v[i] ) });
			}
		}
		g[st].push_back({ en, finddis( tt, t2 )});
		g[en].push_back({ st, finddis( tt, t2 )});
		q.push({ st, 0 }), dis[st] = 0;
		while( !q.empty() ){
			t = q.top();
			q.pop();
			for( int i = 0 ; i < g[t.no].size() ; i++ ){
				if( dis[g[t.no][i].t] > t.d + g[t.no][i].d ){
                    dis[g[t.no][i].t] = t.d + g[t.no][i].d;
					q.push({ g[t.no][i].t, t.d + g[t.no][i].d });
				}
			}
		}
		printf("%lld\n",dis[en]);
	}
	return 0;
}
