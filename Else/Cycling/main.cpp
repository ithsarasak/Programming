#include<stdio.h>
#include<vector>

using namespace std;

struct node{
    int go, dis;
};
vector< node > vec[1001];
int town, road, i;
int main()
{
    scanf("%d %d",&town,&road);

    for( i =  0 ; i < road ; i++ ){
        int a, b, c;
        scanf("%d %d %d",&a,&b,&c);
        vec[a].push_back({ b , c });
    }
}
