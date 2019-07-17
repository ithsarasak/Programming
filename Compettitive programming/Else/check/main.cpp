#include<bits/stdc++.h>

using namespace std;

struct stu{
    int allscore, tasks, id;
    bool operator<( const stu &k )const{
        if( k.allscore == allscore ){
            if( k.tasks == tasks ){
                return k.id > id;
            }
            else{
                return k.tasks > tasks;
            }
        }
        else{
            return k.allscore > allscore;
        }
    }
};
multiset< stu > all;
int main()
{
    all.insert( ( stu ){ 9 , 9 , 1 } );
    all.insert( ( stu ){ 8 , 8 , 1 } );
    all.insert( ( stu ){ 7 , 7 , 1 } );
    all.insert( ( stu ){ 6 , 6 , 1 } );
    all.insert( ( stu ){ 5 , 5 , 1 } );
    all.insert( ( stu ){ 4 , 4 , 1 } );
    all.insert( ( stu ){ 3 , 3 , 1 } );

    for( multiset< stu >::iterator it = all.begin() ; it != all.end() ; it++ ){
        printf("%d ",*it);
    }
    return 0;
}
