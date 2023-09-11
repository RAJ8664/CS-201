#include<stdio.h>
#include<stdlib.h>

int main(){
	int row , col;
	scanf("%d%d",&row,&col);
	
	int arr[row][col];
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			int x;
			scanf("%d",&x);
			arr[i][j] = x;
		}
	}
	
	int ans[row][col];
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			ans[i][j] = 0;
			for(int k = 0; k < row; k++){
				ans[i][j] += arr[i][k] * arr[k][j];
			}
		}
	}
	bool found = false;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if(arr[i][j] != ans[i][j]){
				found = true;
				break;
			}
		}
		if(found){
			break;
		}
	}
	if(found){
		printf("Not Idempotent Matrix \ n");
	}
	else{
		printf("Idempotent Matrix\n");
	}
}