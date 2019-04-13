#include<bits/stdc++.h>

using namespace std;
int minx, miny, maxx, maxy;
int n;
char ch = 'B';
char ma[2010][2010];
void zero()
{
    int wi = maxx - minx + 1;
    int le = maxy - miny + 1;
    for( int i = minx ; i < minx + wi ; i++ ){
        for( int j = maxy + 1 ; j <= maxy + wi ; j++ ){
            ma[i][j] = ch;
        }
    }
    ch++;
    maxy += wi;
}
void one()
{
    int wi = maxx - minx + 1;
    int le = maxy - miny + 1;
    for( int i = maxx + 1 ; i <= maxx + le ; i++ ){
        for( int j = miny ; j < miny + le ; j++ ){
            ma[i][j] = ch;
        }
    }
    ch++;
    maxx += le;
}
void two()
{
    int wi = maxx - minx + 1;
    int le = maxy - miny + 1;
    for( int i = minx ; i < minx + wi ; i++ ){
        for( int j = miny - 1 ; j >= miny - wi ; j-- ){
            ma[i][j] = ch;
        }
    }
    ch++;
    miny -= wi;
}
void three()
{
    int wi = maxx - minx + 1;
    int le = maxy - miny + 1;
    for( int i = minx - 1 ; i >= minx - le ; i-- ){
        for( int j = miny ; j < miny + le ; j++ ){
            ma[i][j] = ch;
        }
    }
    ch++;
    minx -= le;
}
int main()
{
    minx = 500, miny = 500, maxx = 500, maxy = 500;
    ma[500][500] = 'A';
    scanf("%d",&n);
    n--;
    for( int i = 0 ; i < n ; i++ ){
        if( i % 4 == 0 )zero();
        else if( i % 4 == 1 )one();
        else if( i % 4 == 2 )two();
        else if( i % 4 == 3 )three();
    }
    for( int i = minx ; i <= maxx ; i++ ){
        for( int j = miny ; j <= maxy ; j++ ){
            printf("%c",ma[i][j]);
        }
        printf("\n");
    }
    return 0;
}
