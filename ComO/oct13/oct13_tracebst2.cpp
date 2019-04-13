#include<bits/stdc++.h>

using namespace std;
struct vv{
    int p1;
    string op;
    bool operator<( const vv &k )const{
        return op < k.op;
    }
};
struct vv2{
    int p1, p2;
    bool operator<( const vv2 &k )const{
        return p1 < k.p1;
    }
};
vector<vv> v;
vector<vv2> v2;
int n;
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        string s;
        cin >> s;
        s[s.length()-1] = 'O';
        v.push_back({ i, s });
    }
    sort( v.begin(), v.end() );
    for( int i = 1 ; i <= n ; i++ ){
        v2.push_back({ v[i-1].p1, i });
    }
    sort( v2.begin(), v2.end() );
    for( int i = 0 ; i < v2.size() ; i++ ){
        printf("%d\n",v2[i].p2);
    }
    return 0;
}
