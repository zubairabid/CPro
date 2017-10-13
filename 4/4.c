#include <stdio.h>
#include <string.h>

int main() {
	char str[100001];
	long long int count = 0;
	long long int T = 0, i = 0, j = 0, found;

	scanf("%lld", &T);
	char stat[10];
	for(i = 0; i < T; i++) {
		scanf("%s", &str);
		count = 0;
		found = 0;
		for(j = 0; j < strlen(str); j++) {
			if(str[j] == '(')
				count++;
			else if(str[j] == ')')
				count--;

			if(count < 0) {
				found = 1;
				stat[2] = '\0';
				stat[0] = 'N';
				stat[1] = 'O';
				break;
			}
		}

		if(count == 0 && found == 0) {
			stat[0] = 'Y';
			stat[1] = 'E';
			stat[2] = 'S';
		}
		else if (count != 0 && found == 0){
			stat[2] = '\0';
			stat[0] = 'N';
			stat[1] = 'O';
		}

		printf("%s\n", stat);
	}

	return 0;
}