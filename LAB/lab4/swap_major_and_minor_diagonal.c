/*Author: Raj Roy*/
//swap major and minor diagonal

#include<stdio.h>
#include<stdlib.h>

void swap(int &x,int &y){
	int temp = x;
	x = y;
	y = temp;
}

int main(){
	int row, col;
	scanf("%d%d",&row,&col);
	
	int arr[row][col];
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			int x;
			scanf("%d",&x);
			arr[i][j] = x;
		}
	}
	
	for(int i = 0; i < row; i++){
		swap(arr[i][i],arr[i][row - i - 1]);
	}
	
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
	
	
}