#include<stdio.h>
#include<string.h>
#include<math.h>

int power(int a,int b){
	int ans=1;
	while(b--)
		ans*=a;
	return ans;
}
int bintodec(char arr[],int r)
{
	int sum=0;
	int c=0;
	for(int i=0;i<r;i++)
	{
		int val=arr[i]-'0';
		sum=sum+(val*power(2,c));
		c++;
	}
	return sum;
}
int main(){
	char s[100];
	scanf("%s",&s);
	int n=strlen(s);
	int r=0;
	char str[100];
	int r1=r;
	int l2=0;
	int i;
	for(i=0;i<n;i++)
	{
		if(power(2,i)>n)
			break;
		r++;
	}
	char red[100];
	l2=0;
	int l1=n;
	for(i=0;i<r;i++)
	{
		int x=power(2,i);
		int c=0;
		int start=l1-x;
		for(int j=start;j>=0;)
		{
			//printf("%d ",j);
			int x1=x;
			int j1=j;			
			while(x1--)
				if(s[j1--]=='1' && j>=0) c++;
			j=j-2*x;
			
		}
		if(c%2)
		red[l2++]='1';
		else
		red[ l2++]='0';
	}
	for(i=0;i<r;i++)
		printf("%c\t",red[i]);
	printf("\n");
	int f=0;
	int ans=0;
	for(int i=0;i<r;i++)
	{
		if(red[i]!='0'){
			f=1;
			break;
		}
	}
	if(f==0)
		printf("Good Message");
	else{
		ans=bintodec(red,r);
		printf("Bad Message error at %d",ans);
	}
}
