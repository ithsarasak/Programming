#include <bits/stdc++.h>

using namespace std;

struct stu{
    int allscore, tasks, id;
    bool operator<( const stu &k )const{
        if( k.allscore == allscore ){
            if( k.tasks == tasks ){
                return k.id > id;
            }
            else{
                return k.tasks < tasks;
            }
        }
        else{
            return k.allscore < allscore;
        }
    }
};
int t[2010], i, j, n, p, T;
int score[2010][2010];
multiset<stu> all;
multiset<stu>::iterator it;
int main()
{
    scanf("%d %d %d",&n,&T,&p);
    for( i = 0 ; i < n ; i++ ){
        for( j = 0 ; j < T ; j++ ){
            scanf("%d",&score[i][j]);
            t[j] += ( 1 - score[i][j] );
            //printf("j : %d t[%d] : %d score : %d\n",j,j,t[j],score[i][j]);
        }
    }
    /*for( i = 0 ; i < T ; i++ ){
        printf("%d ",t[i]);
    }
    printf("\n\n");*/
    for( i = 0 ; i < n ; i++ ){
        int sumscore = 0, task = 0;
        for( j = 0 ; j < T ; j++ ){
            sumscore += t[j] * score[i][j];
            task += score[i][j];
        }
        all.insert(( stu ){ sumscore , task, i + 1 } );
    }
    int counts = 1;
    for( it = all.begin() ; it != all.end(); it++ ){
        //printf("%d %d %d\n",(*it).allscore,(*it).tasks,(*it).id);
        if( (*it).id == p ){
            printf("%d %d",(*it).allscore,counts);
            break;
        }
        counts++;
    }
    return 0;
}
