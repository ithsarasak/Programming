#include <stdio.h>

int main()
{
    int num[3], ansA[100][100], ansC[100][100], idx_ans[100][2],ans[100][4] ;

	int a, b, c, d, count, count1,count2, idx, idx1, i, j;

	int Amin, Idx_Amin, Amore, Acount, Bmin, idx_Bmin;

	long A, B, C, ad, bc;

    for(i = 0 ; i < 3 ; i++ )
    {
        scanf("%d",&num[i]);
    }

	if( (num[0]<1 || num[0] >100) || (num[1]<-10000 || num[1]>10000) || (num[2]<-100 || num[2]>100))
    {
        return 0;
    }

	count1=0;

	idx=0;

	for( i = 1 ; i <= 100 ; i++ )
	{
		for ( j = 1 ; j <= 100 ; j++ )
		{
			A=i*j;

			if( A == num[0] )
			{
				a=i;

				c=j;

				ansA[idx][0]=a;

				ansA[idx][1]=c;

				count1++;

				idx++;
			}

		}

	}
	/*for( i = 0 ; i < count1 ; i++ )
    {
        for( j = 0 ; j < 2 ; j++ )
        {
            printf("%d ",ansA[i][j]);
        }
        printf("\n");
    }*/

	idx1=0;

	count2=0;

	for( i = -100 ; i <= 100 ; i++ )
	{

		for( j = -100 ; j <= 100 ; j++ )
		{

			C=i*j;

			if( C == num[2] )
			{
				b=i;

				d=j;

				ansC[idx1][0]=b;

				ansC[idx1][1]=d;

				count2++;

				idx1++;

			}

		}
	}
	/*for( i = 0 ; i < count2 ; i++ )
    {
        for( j = 0 ; j < 2 ; j++ )
        {
            printf("%d ",ansC[i][j]);
        }
        printf("\n");
    }*/
    count = 0;

    for( i = 0 ; i < count1 ; i++ )
    {
        for( j = 0 ; j < count2 ; j++ )
        {
            ad=ansA[i][0]*ansC[j][1];

            bc=ansA[i][1]*ansC[j][0];

            B=ad+bc;

            if( B == num[1] )
            {
                ans[count][0]=ansA[i][0];

                ans[count][1]=ansC[j][0];

                ans[count][2]=ansA[i][1];

                ans[count][3]=ansC[j][1];

                count++;

            }

        }

    }
    /*for( i = 0 ; i < count ; i++ )
    {
        for( j = 0 ; j < 4 ; j++ )
        {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }*/
    if(count==1)
    {
        printf("%d ", ans[0][0]);

        printf("%d ", ans[0][1]);

        printf("%d ", ans[0][2]);

        printf("%d ", ans[0][3]);

    }
    else if( count > 1 )
    {
        Amin = ans[0][0];
        Bmin = ans[0][1];

        Idx_Amin=0;

        for( i = 0 ; i < count ; i++ )
        {
            if( ans[i][0] < Amin )
            {
                Amin = ans[i][0];
                Bmin = ans[i][1];

                Idx_Amin=i;
            }
            else if( ans[i][0] == Amin )
            {
                if( ans[i][1] < Bmin )
                {
                    Amin = ans[i][0];
                    Bmin = ans[i][1];

                    Idx_Amin=i;
                }
            }
        }
        for( i = 0 ; i < 4 ; i++ )
        {
            printf("%d ",ans[Idx_Amin][i]);
        }
    }
    else
    {
        printf("No Solution");
    }

	return 0;
}
