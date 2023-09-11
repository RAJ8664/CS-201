/*Author : Raj Roy*/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int row , col;
	scanf("%d%d",&row,&col);
	
	int a[row][col];
	int b[row][col];
	
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			int x;
			scanf("%d",&x);
			a[i][j] = x;
		}
	}
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			int x;
			scanf("%d",&x);
			b[i][j] = x;
		}
	}
	
	
	int ans[row][col];
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			ans[i][j] = a[i][j] + b[i][j];
		}
	}
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}