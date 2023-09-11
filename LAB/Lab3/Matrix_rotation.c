#include<stdio.h>
#include<stdlib.h>

int main(){
	int row , col;
	scanf("%d%d", &row,&col);
	
	int arr[row][col];
	//input;
	
	printf("Original array : \n");
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			int x;
			scanf("%d",&x);
			arr[i][j] = x;
			printf("%d ", arr[i][j]);
		}
		printf("\n");
		
	}
	
	printf("Clockwise rotation: \n");
	for(int j = 0; j < col; j++){
		for(int i = row - 1; i >= 0; i--){
			printf("%d ",arr[i][j]);	
		}
		printf("\n");
	}
	
	printf("anticlockwise rotation: \n");
	for(int j = col - 1; j >= 0; j--){
		for(int i = 0; i < row; i++){
			printf("% d" ,arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}