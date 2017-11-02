#include <stdio.h>

long long int dp[10000001]; // array to store the max sum of any number

long long int dodp(long long int);

int main() {
	long long int i, j, k, n;
	for(i = 0; i < 10000001; i++) { //dp[i] = -1 means that no value has been computed
		dp[i] = -1; 
	}
	dp[0] = 0; // known, base case
	dp[1] = 1; // known, base case

	scanf("%lld", &n); //input
	printf("%lld\n", dodp(n)); //output
	
	return 0;
}
/*
	Function to calculate the max sum of a number if not already computed, and return precomputed value if such exists
*/
long long int dodp(long long int n) {
	if(dp[n] == -1) { // if the max sum isn't known, we try computing
		long long int a, b, c;
		//just initialising
		a = n/2;
		b = n/3;
		c = n/4;

		if(dp[a] == -1) { // if dp[a] is not computed, we can't calculate the dp[n] (since the algorithm depends on maximum sum possible).  
			dodp(a); // so we calulate dp[each]
		}
		if(dp[b] == -1) { // for
			dodp(b); // every other variable
		}
		if(dp[c] == -1) { // if
			dodp(c); // necessary
		}

		//Now we know the maximum values of the components, so if their sum exceeds the number itself, that's the max. Else the number is the max.
		if(dp[a]+dp[b]+dp[c] <= n) {
			dp[n] = n;
			return dp[n];
		}
		else {
			dp[n] = dp[a]+dp[b]+dp[c];
			return dp[n];
		}
		
	}
	else { // else we return precomputed value
		return dp[n];
	}
}