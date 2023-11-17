/*Author : Raj Roy */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertion_sort(int arr[],int n){
	for(int i = 0; i < n; i++){
		int j = i;
		
		while(i > 0 && arr[j] < arr[j - 1]){
			int temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
	}
}

int main(){
	srand(time(0));
	int n = rand() % 100;
	
	int arr[n];
	for(int i = 0; i < n; i++){
		int x = rand() % 100000;
		arr[i] = x;
	}
	insertion_sort(arr, n);
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	return 0;	
}