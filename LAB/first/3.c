#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int sqrt(int n){
	int ans = -1;
	for(int i = 0; i <= n;i++){
		int x = i * i;
		if(x <= n){
			ans = i;
		}
	}
	return ans;

}


int sqrt_binary(int n){
	int low = 0;
	int high = n;
	int ans = -1;
	while(low <= high){
		int mid = low + (high - low ) / 2;
		if(mid * mid <= n){
			ans = mid;
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	return ans;
	
	
	
}

int main(){
	int n = 25;
	printf("%d",sqrt_binary(n));
	return 0;
	
}