#include <stdio.h>
#include <stdlib.h>

void foo2(int);
void foo1(int n){
	if(n <= 10){
		printf("%d\t" ,n);
		n++;
		foo2(n);
	}
}
void foo2(int n){
	if(n <= 10){
		printf("%d\t", n);
		n++;
		foo1(n);
	}
}



int fool1( ){
	static int n = 100;
	if(n <= 0){
		return 0;
	}
	return n--;
}



int f(int n){
	static int r = 0;
	if(n <= 0){
		return 1;
	}
	if(n > 3){
		r = n;
		return 	f(n - 2) + 2;
	}
	return f(n - 1) + r;
}

int main(){
	
	//foo1(1);
	//output 5a = 1 2 3 4 5 6 7 8 9 10
	
	// for(fool1();fool1();fool1()){
		// printf("%d\t",fool1());
	// }
	
	//output 5b = 98 95	92 89 86 83	80 77 74 71 68 65 62 59	56 53 50 47	44 41 38 35	32 29 26 23 20 17 14 11 8 5	2	
	
	// printf("%d",f(5));
	
	//output 5c = 18;
	return 0;
}
