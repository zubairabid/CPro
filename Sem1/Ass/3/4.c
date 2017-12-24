#include <stdio.h>
#include <string.h>

int main() {
	char str[1000010];
	long long int count = 0;
	long long int N = 0, i = 0, j = 0, found;

	scanf("%lld", &N);
	scanf("%s", &str);
	count = 0;
	found = 0;
	for(j = 0; j < N; j++) {
		if(str[j] == '(')
			count++;
		else if(str[j] == ')')
			count--;

		if(count < 0) {
			found = 1;
			printf("NO\n");
			break;
		}
		//printf("%d\n", count);
	}

	if(count == 0 && found == 0) {
		printf("YES\n");
	}
	else if (count != 0 && found == 0){
		printf("NO\n");
	}	
	return 0;
}
