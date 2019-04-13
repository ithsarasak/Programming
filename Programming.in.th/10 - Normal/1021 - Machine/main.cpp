#include<stdio.h>
#include<queue>

using namespace std;

int main()
{
    priority_queue<int>l;
    priority_queue<int>g;

    int i,num;

    scanf("%d",&num);

    for(i=0;i<num;i++)
    {
        char ch;

        scanf(" %c",&ch);

        if(ch=='P')
        {
            int value;

            scanf("%d",&value);

            l.push(value);
        }
        else
        {
            if(l.empty())
                printf("-1\n");
            else
            {
                printf("%d\n",l.top());
                g.push(-1*l.top());
                l.pop();
            }
        }
    }

}
