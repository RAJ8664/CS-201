/*Author: Raj Roy*/
//rotation of matrix anticlockwise

#include<stdio.h>
#include<stdlib.h>

int main(){
	int row , col;
	scanf("%d%d",&row,&col);
	
	int matrix[row][col];
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			int x;
			scanf("%d",&x);
			matrix[i][j] = x;
		}
	}
	
	
	for(int j = col - 1; j >= 0; j--){
		for(int i = 0; i < row; i++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
	
}