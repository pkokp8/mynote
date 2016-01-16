#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define zxw_PRINTF(string,args...) printf("\033[35m%s[%d]: "string"\033[0m",__FUNCTION__,__LINE__,##args)

int arraymv(char *array,int len)
{
	int i = 0;
	for(i=len;i>0;i--)
	{
		array[i]=array[i-1];
	}
}

int cmpnum(char *a,char *b,char **max,char **min)//比较ab的大小
{
	int i =0;
	int len_a = 0;
	int len_b = 0;
	len_a = calcnum(a);
	len_b = calcnum(b);
	if(len_a>len_b)
	{
		memcpy(*max,a,len_a);
		memcpy(*min,b,len_b);
	}
	else if(len_a<len_b)
	{
		memcpy(*max,b,len_b);
		memcpy(*min,a,len_a);
	}
	else
	{
		for(i=0;i<len_a;i++)
		{
			if(a[i]-'0'-b[i]-'0'<0)
			{
				memcpy(*max,b,len_b);
				memcpy(*min,a,len_a);
				return 0;
			}
			else if(a[i]-'0'-b[i]-'0'>0)
			{
				memcpy(*max,a,len_a);
				memcpy(*min,b,len_b);
				return 0;
			}
			else
			{
				continue;
			}
		}
		if(i == len_a)//一样大
		{
			memcpy(*max,a,len_a);
			memcpy(*min,b,len_b);
		}
	}
}

int calcnum(char *str)
{
	int i=0;
	for(i=0;str[i]!='\0';i++)
	{
		;
	}
	//printf("len = %d\n",i);
	return i;
}
char* add(char* a,char* b)
{
	char *max=(char*)malloc(100);
	char *min=(char*)malloc(100);
	char *result=(char*)malloc(101);
	memset(max,0,100);
	memset(min,0,100);
	memset(result,0,101);
	int i = 0;
	int j = 0;
	char flag = 0;//进位
	cmpnum(a,b,&max,&min);
	int len_max = 0;
	int len_min = 0;
	len_max = calcnum(max);
	len_min = calcnum(min);
	while(len_max-i)
	{
		if(len_min-1-j>=0)
		{
			result[len_max-1-i]=max[len_max-1-i]+min[len_min-1-j]-'0'+flag;
			flag=0;
			if(result[len_max-1-i] >= 10+'0')
			{
				result[len_max-1-i]=result[len_max-1-i]-10;
				flag=1;
			}
		}
		else
		{
			result[len_max-1-i]=max[len_max-1-i]+flag;
			flag=0;
			if(result[len_max-1-i] >= 10+'0')
			{
				result[len_max-1-i]=result[len_max-1-i]-10;
				flag=1;
			}
		}
		i++;
		j++;
	}
	if(flag == 1)
	{
		arraymv(result,101);
		result[0]=flag+'0';
		flag=0;
	}
	free(max);
	free(min);
	return result;
}

int main()
{
	char* a;
	char* b;
	a=(char*)malloc(100);
	b=(char*)malloc(100);
	printf("num1:");
	scanf("%s",a);
	printf("num2:");
	scanf("%s",b);
	char *p=add(a,b);
	printf("%s+%s=%s\n",a,b,p);
	free(p);
	free(a);
	free(b);
}
