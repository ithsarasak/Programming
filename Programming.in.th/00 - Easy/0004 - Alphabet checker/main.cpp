#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<iostream>

using namespace std;

main()
{
	char word[100000];
	int i,j;
	int len;
	int a=0,b=0;

	scanf("%s",word);

	len=strlen(word);

	for(i=0;i<len;i++)
	{
		if(islower(word[i])==0)
		{
			a++;
		}
		else if(isupper(word[i])==0)
		{
			b++;
		}
	}
	//cout << a << b << len;
	if(a==len)
	{
		printf("All Capital Letter\n");
	}
	else if(b==len)
	{
		printf("All Small Letter\n");
	}
	else
	{
		printf("Mix\n");
	}
}
