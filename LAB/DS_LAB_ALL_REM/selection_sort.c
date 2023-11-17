/*Author : Raj Roy */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selection_sort(int arr[],int n){
	for(int i = 0; i < n - 1; i++){
		int min = i;
		for(int j = i + 1; j < n; j++){
			if(arr[min] > arr[j]){
				min = j;
			}
		}
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}


int main(){
	srand(time(0));
	clock_t start, end;
	int n = rand() % 1000000;
	
	int arr[n];
	for(int i = 0; i < n; i++){
		int x = rand() % 100000;
		arr[i] = x;
	}
	
	start = clock();
	selection_sort(arr, n);
	for(int i = 0; i < n; i++){
		printf("%d " , arr[i]);
	}
	end = clock();
	
	double total = (double)( end - start) * 1000/ CLOCKS_PER_SEC;
	
	printf("Time elapsed : %f :" ,total);
	return 0;
}