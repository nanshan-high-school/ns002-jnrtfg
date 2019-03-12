#include <iostream>



int main(int argc, char** argv) 
{
	int n,S[1000],success=0,failure=0;//(==1,)==2,沒有==0 
	char enter;
	scanf("%d",&n);
	for(int i=0;i<=n-1;i++)
	{
		scanf("%c",&enter);
		if(enter==40)
		{
			S[i]=1;
		}
		else
		{
			S[i]=2;
		}
	}
	for(int i=0;i<=n-1;i++)
	{
		if(S[i]==1)
		{
			S[i]=2;
		}
		else
		{
			S[i]=1;
		}
	}
	for(int j=0;j<=n-2;j++)
	{
		for(int i=0;i<=n-2;i++)
		{
			if(S[i]==1)
			{
				if(S[i+1]==2)
				{
					S[i]=0;
					S[i+1]=0;
					success++;
				}
			}
			if(S[i]==0)
			{
				S[i]=S[i+1];
				S[i+1]=0;
			}
		}
	}
	for(int i=0;i<=n-1;i++)
	{
		if(S[i]!=0)
		{
			failure++;
		}
	}
	printf("%d %d",success,failure);
	if((success*5000)-(failure*3500)>0)
	{
		printf("賺 %d",(success*5000)-(failure*3500));
	}
	else
	{
		if((success*5000)-(failure*3500)<0)
		{
			printf("賠 %d",-((success*5000)-(failure*3500)));
		}
		else
		{
			printf("不賺不賠");
		}
	}
	return 0;
}