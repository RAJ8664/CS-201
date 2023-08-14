/*Author : RAJ ROY*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char * one[] = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine",
"Ten","Eleven","Twelve","Thirteen","Fourteen" ,"Fifteen","Sixteen" ,"Seventeen"
,"Nineteen"};

const char * ten[] = {"" , "" , "Twenty" ,"Thirty", "Forty","Fifty","Sixty","Seventy",
"Eighty","Ninety"};


char * create(int n , char * s){
	//Initialize the size;
	char * ans = (char *) malloc(1000 * sizeof(char));
	//Initially set the string as empty;
	ans[0] = '\0';
	if(n > 19){
		char * first = ten[n / 10];
		strcat(ans,first);
		strcat(ans," ");
		
		char * second = one[n % 10];
		strcat(ans,second);
		
		strcat(ans, " ");
		
	}
	else if(n > 0){
		char * temp = one[n];
		strcat(ans, temp);
		strcat(ans, " ");
	}
	if(n != 0){
		strcat(ans, s);
	}
	strcat(ans, " ");
	return ans;
}

char * Number_to_Word(int n){
	char * ans = (char *) malloc (1000 * sizeof(char));
	ans[0] = '\0';
	
	char * first = create((n / 10000000) , "Crore");
	strcat(ans,first); 
	
	char * second = create((n / 100000) % 100 , "Lakh");
	strcat(ans,second);
	
	char * third = create((n / 1000) % 100,"Thousand");
	strcat(ans,third);
	
	char * fourth = create((n / 100) % 10 ,"Hundred");
	strcat(ans,fourth);
	
	char * fifth = create(n % 100 , " ");
	strcat(ans,fifth);
	return ans;
	
}

int main () {
	int n;
	scanf("%d" , &n);
	char * ans = Number_to_Word(n);
	printf("%s", ans);
	return 0;
}