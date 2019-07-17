#include <bits/stdc++.h>

using namespace std;
struct uu{
    int ch, f, t;
};
int n, q;
vector<int> num;
vector<uu> u;
int fen[200100];
string s[7] = { "sleep", "eat", "work", "eat", "work", "eat" };
void up( int f, int t )
{
    //printf("JUAY");
    for( int i = f ; i <= 200000 ; i += ( i & -i ) )fen[i] += 1;
    for( int i = t + 1 ; i <= 200000 ; i += ( i & -i ) ) fen[i] += -1; 
}
int query( int idx )
{
    int sum = 0;
    for( int i = idx ; i > 0 ; i -= ( i & -i ))sum += fen[i];
    return sum;
}
int main()
{

    scanf("%d %d",&n,&q);
    num.push_back( 0 );
    for( int i = 0 ; i < q ; i++ ){
        int c;
        scanf("%d",&c);
        if( c ){
            int f, t;
            scanf("%d %d",&f,&t);
            num.push_back( f ), num.push_back( t ), u.push_back({ c, f, t });
        }
        else{
            int a;
            scanf("%d",&a);
            num.push_back( a ), u.push_back({ c, a, 0 });
        }
    }
    sort( num.begin(), num.end() );
    num.resize( unique( num.begin(), num.end() ) - num.begin() );
    for( int i = 0 ; i < q ; i++ ){
        //printf("U\n");
        u[i].f = lower_bound( num.begin(), num.end(), u[i].f ) - num.begin();
        u[i].t = lower_bound( num.begin(), num.end(), u[i].t ) - num.begin();
    }
    for( int i = 0 ; i < q ; i++ ){
        if( u[i].ch ){
            up( u[i].f, u[i].t );
        }
        else cout << s[query(u[i].f)%6] << endl;
    }
    return 0;
}