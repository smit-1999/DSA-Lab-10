#include<stdio.h>
//complete test cases
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
void sort(int n,int *a,int k)
{
	int i,j,index;
	for(i=0;i<k;i++)
	{
		index=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]>a[index])
				index=j;
		}
		if(index!=i)
				swap(&a[i],&a[index]);
	}
}
int main()
{
	int i,j,n,k;
	scanf("%d%d",&n,&k);
	int l[n],r[n];
	for(i=0;i<n;i++)
		scanf("%d",&l[i]);
	for(i=0;i<n;i++)
		scanf("%d",&r[i]);
	sort(n,l,k);
	sort(n,r,k);
	printf("%d ",l[0]+r[0]);
	k--;
	int irpt=0,ilpt=0,erpt=1,elpt=1;//irpt=initial right pointer, elpt =end left pointer r=right
	while(k--)
	{
		if(l[elpt]+r[irpt] > l[ilpt]+r[erpt])
		{
			printf("%d ",l[elpt]+r[irpt]);
			elpt++;
			if(elpt==n)
			{
				ilpt++;
				elpt=ilpt+1;
			}
		}
		else if(l[elpt]+r[irpt] < l[ilpt]+r[erpt])
		{
			printf("%d ",l[ilpt]+r[erpt]);
			erpt++;
			if(erpt==n)
			{
				irpt++;
				erpt=irpt+1;
			}
		}
		else
		{
			if(k>=2)
			{
				printf("%d %d ",l[elpt]+r[irpt],l[elpt]+r[irpt]);
				k--;
				elpt++;erpt++;
				if(elpt==n)
				{
					ilpt++;
					elpt=ilpt+1;
				}
				if(erpt==n)
				{
					irpt++;
					erpt=irpt+1;
				}
			}
			else
				printf("%d ",l[elpt]+r[irpt]);
		}
	}
}
