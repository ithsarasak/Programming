#include<stdio.h>

struct stu{
    int id, level;
}student[1000], queue[2000];

int i, j, nc, ns, exit[5000], size, sizeex;
char command = 'a';

int main()
{
    scanf("%d %d",&nc,&ns);

    for( i = 0 ; i < ns ; i++ ){
        fflush(stdin);
        scanf("%d %d",&student[i].level,&student[i].id);
    }
    while( command != 'X' ){
        scanf(" %c",&command);

        if( command != 'X' ){
            if( command == 'D' ){
                if( !size ){
                    exit[0] = -1;
                    sizeex += 1;
                }
                else{
                    exit[sizeex] = queue[0].id;
                    for( i = 0 ; i < size - 1 ; i++ ){
                        queue[i].id = queue[ i + 1 ].id;
                        queue[i].level = queue[ i + 1 ].level;
                    }
                    size -= 1;
                    sizeex += 1;
                }
            }
            else{
                int id, database_lv, pos;
                bool c = true;
                scanf("%d",&id);

                for( i = 0 ; i < ns ; i++ ){
                    if( id == student[i].id ){
                        database_lv = student[i].level;
                    }
                }
                //printf("lv : %d\n",database_lv);
                for( i = 0 ; i < size ; i++ ){
                    if( queue[i].level == database_lv ){
                        pos = i;
                        c = false;
                    }
                }
                if( c ){
                    queue[size].level = database_lv;
                    queue[size].id = id;
                    size += 1;
                }
                else{
                    for( i = size ; i > pos + 1 ; i-- ){
                        queue[i].id = queue[i-1].id;
                        queue[i].level = queue[i-1].level;
                    }
                    queue[pos+1].id = id;
                    queue[pos+1].level = database_lv;
                    size += 1;
                }
            }
        }
    }
    for( i = 0 ; i < sizeex ; i++ ){
        if( exit[i] == -1 ){
            printf("empty\n");
        }
        else{
            printf("%d\n",exit[i]);
        }
    }
        printf("0");
}
