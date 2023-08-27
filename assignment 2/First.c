/*Author : RAJ ROY*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void add(char str1[], char str2[],char ans[]){
	int n1 = strlen(str1);
	int n2 = strlen(str2);
	
	int max = 0;
	if(n1 > n2){
		max = n1;
	}
	else{
		max = n2;
	}
	int carry = 0;
	int sum = 0;
	for(int i = 0; i < max; i++){
		int first = 0;
		int second = 0;
		if(i < n1){
			first = str1[n1 - i - 1] - '0';
		}
		if(i < n2){
			second = str2[n2 - i - 1] - '0';
		}
		sum = first + second + carry;
		int digit = sum % 10;
		carry = sum / 10;
		
		ans[max - i] = digit + '0'; 
		
	}
	if (carry) {
        ans[0] = carry + '0';
        ans[max + 1] = '\0';
    } else {
        ans[0] = '0';
        ans[max + 1] = '\0';
    }
	
}

int main(){
	char str1[1025];
	char str2[1025];
	char ans[3000];
	
	scanf("%s",str1);
	scanf("%s",str2);
	
	add(str1,str2,ans);
	
	for(int i = 0; i < (int)strlen(ans); i++){
		if(ans[i] =='0' && i == 0){
			continue;
		}
		else{
			printf("%c" ,ans[i]);
		}
			
		
		
	}
	return 0;
}