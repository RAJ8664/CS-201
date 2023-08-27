#include <stdio.h>
#include <stdlib.h>


bool is_prime(int n){
	if(n <= 1){
		return false;
	}
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}



//iterative
void prime_Numbers(int n){
	for(int i = 2; i <= n; i++){
		if(is_prime(i)){
			printf("%d ",i);
		}
	}
}



//sieve
void prime_numbers(int n,bool prime[]){
	
	for (int i = 0; i < n; i++) {
        prime[i] = true;
    }
 
	prime[0] = false;
	prime[1] = false;
	
	for(int i = 2; i <= n; i++){
		if(prime[i] == true){
			for(int j = 2 * i; j <= n; j += i){
				prime[j] = false;
			}
		}
	}
	 for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            printf("%d\n", i);
        }
    }

}

int main(){
	int n = 20;
	bool prime[n + 1]; 
	
	prime_numbers(n,prime);
	return 0;
	
	
}