/*Author: Raj Roy*/
//summation of each row and column

#include<stdio.h>
#include<stdlib.h>

int main(){
	int row,col;
	scanf("%d%d",&row,&col);
	
	double matrix[row][col];
	
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			double x;
			scanf("%lf", &x);
			matrix[i][j] = x;
		}
	}
	
	printf("summation of each row:\n");
	for(int i = 0; i < row; i++){
		double sum = 0;
		for(int j = 0; j < col; j++){
			sum += matrix[i][j];
		}
		printf("%lf " ,sum);
	}
	
	printf("\n");
	printf("summation of each column:\n");
	for(int j = 0; j < col; j++){
		double sum = 0;
		for(int i = 0; i < row; i++){
			sum += matrix[i][j];
		}
		printf("%lf ",sum);
	}
	return 0;
}