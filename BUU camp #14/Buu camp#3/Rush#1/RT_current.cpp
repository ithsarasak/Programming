#include<bits/stdc++.h>

using namespace std;
int n;
struct what{
    int op, num;
}all[300010];
vector<int> cpy;
map<int,int> h;
int fenwick[300100];
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d %d",&all[i].op,&all[i].num);
        if( all[i].op == 1 ){
            cpy.push_back( all[i].num );
        }
    }
    sort( cpy.begin(), cpy.end() );
    for( int i = 0 ; i < cpy.size() ; i++ ){
        h[cpy[i]] = i+1;
    }
    for( int i = 0 ; i < n ; i++ ){
        if( all[i].op == 1 ){
            for( int j = h[all[i].num] ; j <= 300000 ; j += j & -j ){
                fenwick[j]++;
            }
        }
        else{
            int sum = 0;
            for( int j = h[all[i].num] ; j > 0 ; j -= j &-j ){
                sum += fenwick[j];
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
