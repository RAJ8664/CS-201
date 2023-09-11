#include<stdio.h>
#include<stdlib.h>

//upper and lower triangular matrix;
int main(){
	int row , col;
	scanf("%d%d",&row,&col);
	
	int arr[row][col];
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			int  x;
			scanf("%d",&x);
			arr[i][j] = x;
			
		}
	}
	
	printf("Upper triangular matrix:\n");
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if(i <= j){
				printf("%d ",arr[i][j]);
			}
			else{
				printf("%d ", -1);
			}
		}
		printf("\n");
	}
	
	printf("\n");
	printf("Lower triangular matrix:\n");
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if(i >= j){
				printf("%d ", arr[i][j]);
			}
			else{
				printf("%d " ,- 1);
			}
		}
		printf("\n");
	}
}