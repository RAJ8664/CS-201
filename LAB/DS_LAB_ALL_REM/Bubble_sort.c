/*Author : Raj Roy */


#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void Bubble_sort(int arr[],int n){
	for(int i = 0; i < n - 1; i++){
		bool found = false;
		for(int j = 0; j < n -  i  - 1; j++){
			if(arr[j] > arr[j + 1]){
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
				found = true;
			}
			
		}
		if(!found) break;
	}
} 
int main(){
	srand(time(0));
	int n = rand() % 1000000;

	int arr[n];
	for(int i = 0; i < n; i++){
		int x = rand() % 100000;
		arr[i] = x;
	}
	
	Bubble_sort(arr, n);
	for(int i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	return 0;
}