#include <stdio.h>
//#include <string.h>
//#include <math.h>

long long int A[1000007];
//long long int track[1000007];
long long int change[1000007];

int main() {
	/*
	//defvals
	long long int i, j, k=1, M, T, N, tr = 0, c = -1, max = 0;

	scanf("%lld %lld", &N, &M);

	for(i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
		if(A[i] == 1) {
			k = 1;
		}
		else {
			track[i] = k++;
			if(k > M) {
				k = 1;
			}
		}
	}

	for(i = 0; i < N; i++) {
		printf("%lld - ", track[i]);
	}
	printf("\n");

	for(i = 0; i <= N; i++) {
		c++;
		if(track[i] >= 1) {
			tr++;
		}
		if(tr > M-1 || i == N) {
			if(c > max) {
				max = c;
			}
			if(c == M) {
				tr = 0;
				c = 0;
				break;
			}
			tr = 0;
			c = c - T - 1;
		}
		if(track[i] == 1) {
			T = i;
		}
	}

	printf("%lld\n", max);

	/*
	default constructs
	
	long long int i, j, k, T, N;

	//Input into N
	scanf("%lld", &N);

	
	//Loop from 0 -- > N-1
	for(i = 0; i < N; i++) {
		
	}
	
	Print statement
	printf("%lld\n", N);
	
	*/

	//default constructs	
	long long int i, j, k, T, N, M, c = 0, length = 0, max = 2<<31;
	//Input into N, M. N is number of inputs, M the number of flippables
	scanf("%lld %lld", &N, &M);
	
	//Loop from 0 -- > N-1 to input into array
	for(i = 0; i < N; i++) {
		scanf("%lld", &A[i]);		
	}
	
	i = 0;
	j = 0; // tracks additions to change
	k = 0; // tracks access to change
	c = 0;
	length = 0;
	max = 2<< 31;
	// possible backtracking, but still theoretically 2N at max.
	while(i < N) {
		//printf("%lld\n", i);
		if(A[i] == 1) {
			;
		}
		else {
			c++;
			//TODO: set the change variable
			//if(c == 1) {
			//	change = i;
			//}
			//change[j++] = i;
		}

		if(c > M) { // when the number of flipped bits is more than accounted for, 

			if(length > max) { // if length is max evah, use it
				max = length;
			}
			// since we don't need, reset length, flip counter, i.
			length = length - change[k++]; 
			i--;
			c--; // backtrack last change
			c--; // account for missing flip
			//j--; // because we'd have fucked this up by a bit.
			////CORNER CASE BITXHES
			//if(A[i] == 0) {
			//	change[j++] = i;
			//	
			//}
			i++;
			continue; // we don't want an accidental i++ again.
		}
		else {
			length++; //yeh obvio
		}
		change[j]++;
		if(A[i] != 1) {
			j++;
			//change[j++] = length-((j-1)<0?0:(change[j-1]));
		}

		if(i == N-1) {
			//also, accounting for last minute (i == N-1)
			if(length > max) {
				max = length;
			}
			break;
		}

		i++; //don't forget to
	}
	
	printf("%lld\n", max);

	//Print statement
	//printf("%lld\n", N);
	
	return 0;
}
