#include<bits/stdc++.h>

using namespace std;
int rock, paper, sci, ma, pos;
string s[3] = { "PAPER", "SCISSORS", "ROCK" };
int main()
{
    scanf("%d %d %d",&rock,&paper,&sci);
    if( rock + paper + sci != 100 ){
        printf("BUG");
        return 0;
    }
    if( ma < rock ){
        ma = rock;
        pos = 0;
    }
    if( ma < paper ){
        ma = paper;
        pos = 1;
    }
    if( ma < sci ){
        ma = sci;
        pos = 2;
    }
    if( ( rock == paper && rock == ma ) || ( paper == sci && paper == ma ) || ( sci == rock && sci == ma ) ){
        printf("I DON'T KNOW");
        return 0;
    }
    cout << s[pos];
    return 0;
}
