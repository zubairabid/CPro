#include <stdio.h>
long long int a[1000000], b[1000000], c[1000000];
int main() {
	long long int n, i;
	//<input>
	scanf("%lld", &n);
	for(i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	for(i = 0; i < n; i++) {
		scanf("%lld", &b[i]);
	}
	for(i = 0; i < n; i++) {
		scanf("%lld", &c[i]);
	}
	//</input>

	for(i = 0; i < n; i++) {
		if((a[i] + b[i] <= c[i]) || (a[i] + c[i] <= b[i]) || (c[i] + b[i] <= a[i]))
			printf("No\n");
		else
			printf("Yes\n");
	}

	return 0;
}