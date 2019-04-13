#include<bits/stdc++.h>

using namespace std;

int n, t;
double em[300], tp[300];
struct A{
    double mat[250][250];
};
A mul( A a , A b )
{
    A temp;
    memset( temp.mat, 0, sizeof temp.mat );
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            for( int k = 0 ; k < n ; k++ ){
                temp.mat[i][j] += a.mat[i][k] * b.mat[k][j];
            }
        }
    }
    return temp;
}
A mic[21];
double ans2[260];
int main()
{
    A ans;
    memset(ans.mat,0,sizeof(ans.mat));
    scanf("%d %d",&n,&t);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lf",&em[i]);
        ans.mat[i][i]=1;
    }
    for( int i = 0 ; i < n ; i++ )
        for( int j = 0 ; j < n ; j++ )
            scanf("%lf",&mic[0].mat[i][j]);
    for(int i=1;i<=20;i++)
        mic[i]=mul(mic[i-1],mic[i-1]);
    for(int i=0;i<=20;i++)
        if(t&(1<<i))
            ans = mul(ans,mic[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ans2[j]+=ans.mat[i][j]*em[i];
    for(int i=0;i<n;i++)
        printf("%.2lf ",ans2[i]);
    return 0;
}
/*#include<bits/stdc++.h>

using namespace std;
int n, t;
double h[300][300], em[300], temp[300];
int main()
{
    scanf("%d %d",&n,&t);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lf",&em[i]);
    }
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            scanf("%lf",&h[i][j]);
        }
    }
    for( int k = 0 ; k < t ; k++ ){
        for( int i = 0 ; i < n ; i++ ){
            temp[i] = em[i];
        }
        for( int j = 0 ; j < n ; j++ ){
            double t = 0.00;
            for( int i = 0 ; i < n ; i++ ){
                t += ( double )( temp[i] * h[i][j] );
            }
            em[j] = t;
        }
    }
    for( int i = 0 ; i < n ; i++ ){
        printf("%.2f ",em[i]);
    }
    return 0;
}*/
