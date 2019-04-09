#include <stdio.h>
#include <stdlib.h>
int main(){
	int n;
	scanf("%d",&n);
	
	int arr[n+1];
	for(int p=0;p<n;p++){
		scanf("%d",&arr[p]);
	}
	arr[n] = 10000;
	for(int i=0;i<n/2;i++){
		int a = arr[(2*i)+1];
		int b = arr[2*(i+1)];
		if(arr[i]>a || arr[i]>b){
			printf("false");
			exit(0);
		}
	}
	printf("true");
}
