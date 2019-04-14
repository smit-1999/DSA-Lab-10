#include <stdio.h>
#include <stdlib.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n+2];
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	arr[n+1] = 0;
	
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
	for(int i=1;i<=n;i++){
		printf("%d ",arr[i]);
	}
	
}

/*
6
3 5 9 6 8 20
*/
