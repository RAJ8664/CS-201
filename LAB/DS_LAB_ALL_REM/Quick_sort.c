/*Author : Raj Roy */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j) {
        while (arr[i] <= pivot && i <= high) {
            i++;
        }

        while (arr[j] > pivot && j >= low) {
            j--;
        }

        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int par_index = partition(arr, low, high);
        quickSort(arr, low, par_index - 1);
        quickSort(arr, par_index + 1, high);
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
	
	quickSort(arr, 0 , n - 1);
	for(int i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	return 0;	
}