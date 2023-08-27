#include <stdlib.h>
#include <stdio.h>


int power(int x ,int y){
	long ans = 1;
	for(int i = 0; i < y; i++){
		ans = ans *x;
	}
	return ans;
}


int binary_power(int x,int y){
	long ans = 1;
	while(y > 0){
		if(y % 2 == 1){
			ans = ans *x;
			y = y - 1;
		}
		else{
			x = x * x;
			y = y / 2;
		}
	}
	return ans;
}


int main(){
	int x = 2;
	int y = 4;
	printf("%d",binary_power(x,y));
	return 0;
	
}