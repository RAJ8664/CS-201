#include <stdio.h>
#include <stdlib.h>


int recursive(int n){
	if(n <= 1){
		return n;
	}
	return recursive(n - 1) + recursive(n - 2);
}


int iterative(int n){
	int a = 0;
	int b = 1;
	int c = 0;
	for(int i = 2; i <=n; i++){
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}




int dynamic(int n,int dp[]){
	if(n <= 1){
		return n;
	}
	if(dp[n] != -1){
		return dp[n];
	}
	return dp[n] = dynamic(n - 1,dp) + dynamic(n - 2,dp);
}




int hashing(int n,int hash[]){
	hash[0] = 0;
	hash[1] = 1;
	for(int i = 2; i <= n; i++){
		hash[i] = hash[i - 1] + hash[i - 2];
	}	
	return hash[n];
}





typedef long long ll;
const ll MOD = 1000000007;

typedef struct {
    ll arr[2][2];
} Matrix;



Matrix mul(Matrix a, Matrix b) {
    Matrix res = {0};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                res.arr[i][j] += a.arr[i][k] * b.arr[k][j];
                res.arr[i][j] %= MOD;
            }
        }
    }
    return res;
}





int main() {
	// Matrix base = {{{1, 0}, {0, 1}}};
    // Matrix m = {{{1, 1}, {1, 0}}};
    // for (; n > 0; n /= 2, m = mul(m, m)) {
        // if (n & 1) base = mul(base, m);
    // }
    //printf("%lld\n", base.arr[0][1]);

	int n = 4;
	int dp[n + 1];
	int hash[n + 1];
	for(int i = 0; i < n + 1; i++){
		dp[i] = -1;
	}
	//int ans = i
	printf("%d",hashing(n,hash));
	return 0;
	
}