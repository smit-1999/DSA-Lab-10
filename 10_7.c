#include <stdio.h>
#include <stdlib.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);		
	}
	int cnt = 0;
	for(int i=0;i<n-1;i++){
		int currSum = arr[i];
		for(int j=i+1;j<n;j++){
			currSum += arr[j];
			if(currSum*2 == j-i+1){
				cnt+=1;
			}
		}
	}
	printf("%d",cnt);
}
