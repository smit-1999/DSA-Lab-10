#include <stdio.h>
#include <stdlib.h>
void swap(int * a,int *b){
	int t = *a;
	*a = *b;
	*b = t;
}
void updateHeap(int * arr,int n){
	/*for(int i=1;i<=n;i++){
			printf("%d ",arr[i]);
		}
		printf("\n");*/
	for(int i=1;i<=(n/2)+1;i++){
		int c1 = arr[2*i];
		int c2 = arr[(2*i) + 1];
		int maxi = (c1>=c2)?c1:c2;
		//printf("root%d child1:%d child2:%d\n",arr[i],c1,c2);
		if(arr[i]<maxi){
			if(maxi == c1){
				int  t = arr[i];
				arr[i] = arr[2*i];
				arr[2*i] = t;	
				i = (2*i)-1;			
			}
			else{
				int t = arr[i];
				arr[i] = arr[(2*i)+1];
				arr[(2*i)+1] = t;
				i = (2*i)+1-1;
			}
			//swap(&arr[i],maxi==c1?&arr[2*i]:&arr[(2*i)+1]);
			//i = (maxi == c1)?2*i:(2*i)+1;
		}
		else {
			break;
		}
	/*	for(int i=1;i<=n;i++){
			printf("%d ",arr[i]);
		}
		printf("\n");*/
		
	}
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int arr[n+2];
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	arr[n+1]=0;
	//building heap
	for(int i=(n/2);i>0;i--){
		int root = arr[i];
		int c1 = arr[2*i];
		int c2 = arr[(2*i) + 1];
		int max = (c1>c2)?c1:c2;
		if(root<max){
			int tmp = arr[i];
			arr[i] = max;
			arr[(max==c1)?2*i:(2*i)+1] = tmp;
		}
	/*	for(int j=1;j<=n;j++){
		printf("%d ",arr[j]);
	}
	printf("\n");*/
	}
	for(int i=1;i<=n/2;i++){
		if(arr[i]<arr[2*i] || arr[i]<arr[(2*i)+1]){
			int maxi = arr[2*i]>arr[(2*i)+1]?arr[2*i]:arr[(2*i)+1];
			int tmp = arr[i];
			arr[i] = maxi;
			arr[(maxi==arr[2*i])?2*i:(2*i)+1]=tmp;
		}
	}
	//heap built
		for(int i=1;i<=n;i++){
			printf("%d ",arr[i]);
		}
		printf("\n");
	int ans = 0;
	while(k!=0){
		ans+=arr[1];
		arr[1]=arr[1]/2;
	//	printf("k:%d\n",k);
		updateHeap(arr,n);
		k-=1;		
		
	/*	for(int i=1;i<=n;i++){
			printf("%d ",arr[i]);
		}
		printf("\n");*/
	}
	printf("%d",ans);
	
}
/*
5
5
9 7 8 12 18
*/
