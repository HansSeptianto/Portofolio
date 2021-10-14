#include<stdio.h>

int count=0;

int check(int source[], int target[][5], int n, int m, int minTarget[], int maxSource){
	for(int i=0;i<m;i++){
		count=0;
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(target[i][k] == source[j]){
					count++;
				}
				
				if(count == n){
					return 1;	
				}else if(minTarget[i] >= maxSource){
					return 0;
				}
			}
		}
	}
	return 0;
	
}

int main(){
	int n=5, m=6, maxSource;
	int minTarget[m];
	int source[n] = {14, 13, 15, 11, 12};
	int target[m][5] = {{4, 2, 1, 3, 5}, {6, 8, 7, 10, 9}, {14, 15, 12, 11, 13}, {17, 20, 16, 18, 19}, {22, 21, 24, 23, 25}, {30, 29, 28, 27, 26}};
	
	maxSource = source[0];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(source[j] >= maxSource){
				maxSource = source[j];
			}
		}
	}
	
	for(int i=0;i<m;i++){
	minTarget[i] = target[i][0];
		for(int j=0;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(target[i][k] <= minTarget[i]){
					minTarget[i] = target[i][k];
				}
			}
		}
	}
	check(source, target, n, m, minTarget, maxSource);
	if(check(source, target, n, m, minTarget, maxSource) == 1){
		printf("True\n");
	}else{
		printf("False\n");
	}
	return 0;
}
