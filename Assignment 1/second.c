#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const int value[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
const char * arr[] = {"M" , "CM" , "D","CD" , "C" , "XC" , "L" , "XL" , "X", "IX" , "V" , "IV" , "I"};

char * Num_to_Roman(int n){
	char * ans = (char *) malloc(1000 * sizeof(char));
	ans[0] = '\0';
	for(int i = 0; i < 13; i++){
		while(n >= value[i]){
			n = n - value[i];
			strcat(ans,arr[i]);
		}
	}
	return ans;
}

int main(){
	int n;
	scanf("%d",&n);
	char * ans = Num_to_Roman(n);
	printf("%s", ans);
	return 0;
}