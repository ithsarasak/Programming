#include<stdio.h>
#include<queue>

using namespace std;

int map[99][101], sol1[99][101], sol2[99][101], sol3[99][101], check1[99][101], check2[99][101], check3[99][101], ans[3];
int i, j, k, step1, step2, step3, m, n, posx1, posy1, posx2, posy2, posx3, posy3, d1, d2, d3, mins = 100000;
struct node{
    int r, c, step;
}t1, t2, t3;
queue< node > p;
int main()
{
    scanf("%d",&n);
    scanf("%d",&m);

    for( i = 1 ; i <= n ; i++ )
    {
        for( j = 1 ; j <= m ; j++ )
        {
            scanf("%d",&map[i][j]);
        }
    }
    p.push({ ( ( ( n + 1 ) / 2 ) - 1 ) , 0 , 0 });
    printf("%d %d %d\n",( ( ( n + 1 ) / 2 ) - 1 ),( ( n + 1 ) / 2 ),( ( ( n + 1 ) / 2 ) + 1 ));

    while( !p.empty() ){
        while( !p.empty() ){
            t1 = p.front();
            p.pop();
            printf("%d %d %d\n",t1.r,t1.c,t1.step);
            if( t1.step != d1 ){
                break;
            }
            printf("%d\n",p.empty());
            step1 = t1.step;
            posx1 = t1.r;
            posy1 = t1.c;
            sol1[posx1][posy1] = step1;
            printf("%d\n",sol1[posx1][posy1]);
            if( t1.c == 0 )
            {
                printf("%d",map[posx1][posy1+1]);
                printf(" %d",check1[posx1][posy1+1]);
                printf(" %d",posy1+1);
                printf(" %d",posx1);
                printf(" %d",step1+1);
                if( map[posx1][posy1+1] != 0 )
                {
                    if( posy1 + 1 <= m && check1[posx1][posy1+1] == 0 && ( step1 + 1 ) % map[posx1][posy1+1] == 0 )
                    {
                        printf(" %d",map[posx1][posy1+1]);
                        check1[posx1][posy1+1] = 1;
                        p.push({ posx1 , posy1 + 1 , step1 + 1 });
                    }
                    printf(" %d\n",p.empty());
                }
            }
            else
            {
                if( posx1 % 2 == 0 )
                {
                    if( map[posx1-1][posy1] != 0 )
                    {
                        if( posx1 - 1 >= n && check1[posx1-1][posy1] == 0 && ( ( step1 + 1 ) % map[posx1-1][posy1] == 0 ) )
                        {
                            check1[posx1-1][posy1] = 1;
                            p.push({ posx1-1 , posy1 , step1 + 1 });
                        }
                    }
                    if( map[posx1][posy1+1] != 0 )
                    {
                        if( posy1 + 1 <= m && check1[posx1][posy1+1] == 0 && ( ( step1 + 1 ) % map[posx1][posy1+1] == 0 ) )
                        {
                            check1[posx1][posy1+1] = 1;
                            p.push({ posx1 , posy1 + 1 , step1 + 1 });
                        }
                    }
                    if( map[posx1+1][posy1] != 0 )
                    {
                        if( posx1 + 1 <= n && check1[posx1+1][posy1] == 0 && ( ( step1 + 1 ) % map[posx1+1][posy1] == 0 ) )
                        {
                            check1[posx1+1][posy1] = 1;
                            p.push({ posx1+1 , posy1 , step1 + 1 });
                        }
                    }
                }
                else
                {
                    if( map[posx1-1][posy1+1] != 0 )
                    {
                        if( posx1 - 1 >= n && posy1 + 1 <= m && check1[posx1-1][posy1+1] == 0 && ( ( step1 + 1 ) % map[posx1-1][posy1+1] == 0 ) )
                        {
                            check1[posx1-1][posy1+1] = 1;
                            p.push({ posx1-1 , posy1+1 , step1 + 1 });
                        }
                    }
                    if( map[posx1][posy1+1] != 0 )
                    {
                        if( posy1 + 1 <= m && check1[posx1][posy1+1] == 0 && ( ( step1 + 1 ) % map[posx1][posy1+1] == 0 ) )
                        {
                            check1[posx1][posy1+1] = 1;
                            p.push({ posx1 , posy1 + 1 , step1 + 1 });
                        }
                    }
                    if( map[posx1+1][posy1+1] != 0 )
                    {
                        if( posx1 + 1 <= n && posy1 + 1 <=m && check1[posx1+1][posy1+1] == 0 && ( ( step1 + 1 ) % map[posx1+1][posy1+1] == 0 ) )
                        {
                            check1[posx1+1][posy1+1] = 1;
                                p.push({ posx1+1 , posy1+1, step1 + 1 });
                        }
                    }
                }

            }
            printf(" %d\n",p.empty());
        }
        d1++;
        for( i = 1; i <= n; i++)
        {
            for(int x = 1; x <= m; x++)
            {
                printf("%d ",check1[i][x]);
            }
            printf("\n");
        }
        printf("\n");

        for( i = 1; i <= n; i++)
        {
            for(int x = 1; x <= m; x++)
            {
                printf("%d ",sol1[i][x]);
            }
            printf("\n");
        }
        printf("\n");
        //break;
    }
    ans[0] = sol1[(n+1)/2][m];
    printf(" %d\n",p.empty());
    printf("---------------------------------------------------\n");
    p.push({ ( ( n + 1 ) / 2 ) , 0 , 0 });
    while( !p.empty() )
    {
        //printf("p.size : %d\n",p.size());
        /*for( i = 1; i <= n; i++)
        {
            for(int x = 1; x <= m; x++)
            {
                printf("%d ",map[i][x]);
            }
            printf("\n");
        }
        for( i = 1; i <= n; i++)
        {
            for(int x = 1; x <= m; x++)
            {
                printf("%d ",check2[i][x]);
            }
            printf("\n");
        }*/
        while( !p.empty() )
        {
            t2 = p.front();


            if( t2.step != d2 )
            {
                break;
            }
            p.pop();
            printf("%d %d %d\n",t2.r,t2.c,t2.step);
            step2 = t2.step;
            posx2 = t2.r;
            posy2 = t2.c;
            if( posx2 == (n+1)/2 && posy2 == m )
            {
                printf("%d",step2);
                break;
            }
            sol2[posx2][posy2] = step2;
            if( posx2 % 2 == 0 )
            {
                if( map[posx2-1][posy2] != 0 )
                {
                    if( posx2 - 1 >= 1 && check2[posx2-1][posy2] == 0 && ( ( step2 + 1 ) % map[posx2-1][posy2] == 0 ) )
                    {
                        //printf(" %d",check1[posx2-1][posy2]);
                        check2[posx2-1][posy2] = 1;
                        p.push({ posx2-1 , posy2 , step2 + 1 });
                        for( i = 1; i <= n; i++)
                        {
                            for(int x = 1; x <= m; x++)
                            {
                                printf("%d ",check2[i][x]);
                            }
                            printf("\n");
                        }
                        printf("\n");
                    }

                }
                //printf(" %d\n",map[posx2][posy2+1]);
                if( map[posx2][posy2+1] != 0 )
                {
                    if( posy2 + 1 <= m && check2[posx2][posy2+1] == 0 && ( ( step2 + 1 ) % map[posx2][posy2+1] == 0 ) )
                    {
                        //printf(" %d",check1[posx2][posy2+1]);
                        check2[posx2][posy2+1] = 1;
                        p.push({ posx2 , posy2 + 1 , step2 + 1 });
                        for( i = 1; i <= n; i++)
                        {
                            for(int x = 1; x <= m; x++)
                            {
                                printf("%d ",check2[i][x]);
                            }
                            printf("\n");
                        }
                        printf("\n");
                    }
                    //printf(" %d",p.empty());
                }
                if( map[posx2+1][posy2] != 0 )
                {
                    if( posx2 + 1 <= n && check2[posx2+1][posy2] == 0 && ( ( step2 + 1 ) % map[posx2+1][posy2] == 0 ) )
                    {
                        //printf(" %d",check1[posx2+1][posy2]);
                        check2[posx2+1][posy2] = 1;
                        p.push({ posx2+1 , posy2 , step2 + 1 });
                        for( i = 1; i <= n; i++)
                        {
                            for(int x = 1; x <= m; x++)
                            {
                                printf("%d ",check2[i][x]);
                            }
                            printf("\n");
                        }
                        printf("\n");
                    }
                }
            }
            else
            {
                if( map[posx2-1][posy2+1] != 0 )
                {
                    if( posx2 - 1 >= 1 && posy1 + 1 <= m && check2[posx2-1][posy2] == 0 && ( ( step2 + 1 ) % map[posx2-1][posy2+1] == 0 ) )
                    {
                        //printf(" %d",check1[posx2-1][posy2]);
                        check2[posx2-1][posy2+1] = 1;
                        p.push({ posx2-1 , posy2+1 , step2 + 1 });
                        for( i = 1; i <= n; i++)
                        {
                            for(int x = 1; x <= m; x++)
                            {
                                printf("%d ",check2[i][x]);
                            }
                            printf("\n");
                        }
                        printf("\n");
                    }
                }
                if( map[posx2][posy2+1] != 0 )
                {
                    if( posy2 + 1 <= m && check2[posx2][posy2+1] == 0 && ( ( step2 + 1 ) % map[posx2][posy2+1] == 0 ) )
                    {
                        //printf(" %d",check1[posx2][posy2+1]);
                        check2[posx2][posy2+1] = 1;
                        p.push({ posx2 , posy2 + 1 , step2 + 1 });
                        //printf("%d\n",p.empty());
                        //printf("%d\n",p.size());
                        for( i = 1; i <= n; i++)
                        {
                            for(int x = 1; x <= m; x++)
                            {
                                printf("%d ",check2[i][x]);
                            }
                            printf("\n");
                        }
                        printf("\n");
                    }

                }
                if( map[posx2+1][posy2+1] != 0 )
                {
                    if( posx2 + 1 <= n &&posy2 + 1 <= m && check2[posx2+1][posy2] == 0 && ( ( step2 + 1 ) % map[posx2+1][posy2+1] == 0 ) )
                    {
                        //printf(" %d",check1[posx2+1][posy2+1]);
                        check2[posx2+1][posy2+1] = 1;
                        p.push({ posx2+1 , posy2+1 , step2 + 1 });
                        //printf("p.size : %d\n",p.size());
                        for( i = 1; i <= n; i++)
                        {
                            for(int x = 1; x <= m; x++)
                            {
                                printf("%d ",check2[i][x]);
                            }
                            printf("\n");
                        }
                        printf("\n");
                    }
                }
                //printf("p.size : %d\n",p.size());
            }
             //printf("p.size : %d\n",p.size());
             printf("___________________________________________________\n");
        }
        ///printf("p.size : %d\n",p.size());
        d2++;
        ///printf("p.size : %d\n",p.size());
        //printf("p.size : %d\n",p.size());

        /*for( i = 1; i <= n; i++)
        {
            for(int x = 1; x <= m; x++)
            {
                printf("%d ",sol2[i][x]);
            }
            printf("\n");
        }*/
        //printf("p.size : %d\n",p.size());
        printf("\n");
        //printf("p.size : %d\n",p.size());
        //break;
    }
    ans[1] = sol2[((n+1)/2)-1][m-1];
    printf("---------------------------------------------------\n");
    p.push({ ( ( ( n + 1 ) / 2 ) + 1 ) , 0 , 0 });
    while( !p.empty() )
    {
        while( !p.empty() )
        {
            t3 = p.front();
            p.pop();
            if( t3.step != d3 )
            {
                break;
            }

            step3 = t3.step;
            posx3 = t3.r;
            posy3 = t3.c;
            sol3[posx3][posy3] = step3;
            if( t1.c == 0 )
            {
                if( map[posx3][posy3+1] != 0 )
                {
                    if( posy3 + 1 <= m && check3[posx3][posy3+1] == 0 && ( ( step3 + 1 ) % map[posx3][posy3+1] == 0 ) )
                    {
                        check3[posx3][posy3+1] = 1;
                        p.push({ posx3 , posy3 + 1 , step3 + 1 });
                    }
                }

            }
            else
            {
                if( posx3 % 2 == 0 )
                {
                    if( map[posx3-1][posy3] != 0 )
                    {
                        if( posx3 - 1 >= n && check3[posx3-1][posy3] == 0 && ( ( step3 + 1 ) % map[posx3-1][posy3] == 0 ) )
                        {
                            check3[posx3-1][posy3] = 1;
                            p.push({ posx3-1 , posy3 , step3 + 1 });
                        }
                    }
                    if( map[posx3][posy3+1] != 0 )
                    {
                        if( posy3 + 1 <= m && check3[posx3][posy3+1] == 0 && ( ( step3 + 1 ) % map[posx3][posy3+1] == 0 ) )
                        {
                            check3[posx3][posy3+1] = 1;
                            p.push({ posx3 , posy3 + 1 , step3 + 1 });
                        }
                    }
                    if( map[posx3+1][posy3] != 0 )
                    {
                        if( posx3 + 1 <= n && check3[posx3+1][posy3] == 0 && ( ( step3 + 1 ) % map[posx3+1][posy3] == 0 ) )
                        {
                            check3[posx3+1][posy3] = 1;
                            p.push({ posx3+1 , posy3 , step3 + 1 });
                        }
                    }
                }
                else
                {
                    if( map[posx3-1][posy3+1] != 0 )
                    {
                        if( posx3 - 1 >= n && posy3 + 1 <= m && check3[posx3-1][posy3] == 0 && ( ( step3 + 1 ) % map[posx3-1][posy3+1] == 0 ) )
                        {
                            check3[posx3-1][posy3+1] = 1;
                            p.push({ posx3-1 , posy3+1 , step3 + 1 });
                        }
                    }
                    if( map[posx3][posy3+1] != 0 )
                    {
                        if( posy3 + 1 <= m && check3[posx3][posy3+1] == 0 && ( ( step3 + 1 ) % map[posx3][posy3+1] == 0 ) )
                        {
                            check3[posx3][posy3+1] = 1;
                            p.push({ posx3 , posy3 + 1 , step3 + 1 });
                        }
                    }
                    if( map[posx3+1][posy3+1] != 0 )
                    {
                        if( posx3 + 1 <= n && posy3+1 <= m && check3[posx3+1][posy3] == 0 && ( ( step3 + 1 ) % map[posx3+1][posy3+1] == 0 ) )
                        {
                            check3[posx3+1][posy3+1] = 1;
                            p.push({ posx3+1 , posy3 +1, step3 + 1 });
                        }
                    }
                }
            }

        }
        d3++;
        for( i = 1; i <= n; i++)
        {
            for(int x = 1; x <= m; x++)
            {
                printf("%d ",check3[i][x]);
            }
            printf("\n");
        }
        printf("\n");

        for(int i = 1; i <= n; i++)
        {
            for(int x = 1; x <= m; x++)
            {
                printf("%d ",sol3[i][x]);
            }
            printf("\n");
        }
        printf("\n");
        //break;
    }
    ans[2] = sol3[(n+1)/2][m];

    for( i = 0 ; i < 3 ; i++ )
    {
        if( mins > ans[i] )
        {
            mins = ans[i];
        }
    }
    printf("%d",mins);
}
