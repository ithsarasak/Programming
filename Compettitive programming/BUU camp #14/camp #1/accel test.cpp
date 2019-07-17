#include<bits/stdc++.h>

using namespace std;
struct help{
    int idx, va;
    bool operator<( const help &k )const{
        return va < k.va;
    }
}pointx[100010], pointy[100010], pointz[100010];;
struct node{
    long long from, go;
    long long dis;
    bool operator<( const node &k  )const{
        return dis > k.dis;
    }
}t;
priority_queue< node > alledge;
long long path;
int par[100010];
int n;
int findroot( int num ){
    if( par[num] == num ){
        return num;
    }
    else{
        return par[num] = findroot( par[num] );
    }
}
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lld %lld %lld",&pointx[i].va,&pointy[i].va,&pointz[i].va);
        pointx[i].idx = i;
        pointy[i].idx = i;
        pointz[i].idx = i;
    }
    sort( pointx, pointx + n );
    sort( pointy, pointy + n );
    sort( pointz, pointz + n );
    for( int i = 0 ; i < n - 1 ; i++ ){
        alledge.push({ pointx[i].idx, pointx[i + 1].idx , abs( pointx[i].va - pointx[i + 1].va ) });
        alledge.push({ pointy[i].idx, pointy[i + 1].idx , abs( pointy[i].va - pointy[i + 1].va ) });
        alledge.push({ pointz[i].idx, pointz[i + 1].idx , abs( pointz[i].va - pointz[i + 1].va ) });
    }
    for( int i = 0 ; i < n ; i++ ){
        par[i] = i;
    }
    while( !alledge.empty() ){
        t = alledge.top();
        //printf("%d ",t.dis);
        int a = findroot( t.from );
        int b = findroot( t.go );
        if( a != b ){
            par[b] = a;
            path += t.dis;
        }
        alledge.pop();
    }
    printf("%lld",path);
    return 0;
}
