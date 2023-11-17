/*Author : Raj Roy */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int arr[],int low, int mid, int high){
	int i = low;
	int j = mid + 1;
	int copy[high - low + 2];
	int k = 0;
	
	while(i <= mid && j <= high){
		if(arr[i] <= arr[j]) copy[k++] = arr[i++];
		else copy[k++] = arr[j++];
	}
	
	while(i <= mid) copy[k++] = arr[i++];
	
	while(j <= high) copy[k++] = arr[j++];
	
	k = 0;
	for(int i = low; i <= high; i++){
		arr[i] = copy[k++];
	}
}

void merge_sort(int arr[], int low ,int high){
	if(low < high){
		int mid = low + (high - low) / 2;
		merge_sort(arr, low, mid);
		merge_sort(arr, mid + 1, high);
		merge(arr, low, mid, high);
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
	
	merge_sort(arr, 0, n - 1);
	for(int i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	return 0;	
}