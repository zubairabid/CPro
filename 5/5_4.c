#include <stdio.h>
#include <string.h>
//#include <math.h>
#define MAX 5002

char str[MAX];
long long int freq[MAX];
long long int delpoint[MAX];

long long int len, k, t = 0, r = 0;
	
long long int number();
void refresh();

int main() {
	//defvals
	long long int i, j, T, N, additions = 0;
	scanf("%s", str);
	scanf("%lld", &k);

	for(i = 0; i < MAX; i++) {
		delpoint[i] = -1;
	}

	len = strlen(str);
	additions = number();
	/*printf("After numbering: ");
	for (i = 0; i < len; ++i)
	{
		printf("%lld ", freq[i]);
	}
	printf("\nDelpoints: ");
	for(i = 0; i < t; i++) {
		printf("%lld ", delpoint[i]);
	}
	printf("\nt: %lld r: %lld\n", t, r);*/
	while(1==1) {
		
		refresh();
		//printf("After refresh: %s\n", str);
		if(strlen(str) == 0) {
			printf("-1\n");
			break;
		}

		len = strlen(str);
		additions = number();
		if(additions == 0) {
			printf("%s\n", str);
			break;
		}
		/*//printf("After numbering: ");
		for (i = 0; i < len; ++i)
		{
			printf("%lld ", freq[i]);
		}
		
		/*printf("\nDelpoints: ");
		for(i = 0; i < t; i++) {
			printf("%lld ", delpoint[i]);
		}
		printf("\nt: %lld r: %lld\n", t, r);*/
	}
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
	return 0;
}

long long int number() {
	long long int track = 1, i;
	freq[0] = 1;
	for(i = 1; i < len; i++) {
		if(str[i] == str[i-1]) {
			freq[i] = freq[i-1] + 1;
			if(freq[i] == k) {
				delpoint[t++] = i-k+1;
			}
			if(freq[i-1] == k) {
				freq[i] = 1;
			}
		}
		else {
			freq[i] = 1;
		}
	}
	if(freq[len] == 0) {
		track = 0;
	}
	freq[len] = 0;
	return track;
}

void refresh() {
	long long int ncnt = 0, ocnt = 0, i;
	for(i = 0; i < len; i++) {
		if(i == delpoint[r]) {
			i = i + k - 1;
			ocnt = ocnt + k;
			r++;
			continue;
		}
		str[ncnt++] = str[ocnt++];
	}
	str[ncnt] = '\0';
}