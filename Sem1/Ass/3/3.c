#include <stdio.h>

long long int a[10000005];


void m_sort(long long int*,long long int, long long int);
void merge(long long int*, long long int, long long int);

int main() {
	long long int n, i, min1, min2, min;
	scanf("%lld", &n);

	for( i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}

	m_sort(a, 0, n-1);
	min1 = a[0];
	min2 = a[1];

	if(n < 2) {
		printf("WHAT THE FUCK OJ YOU LIL BITCH\n");
		return 1;
	}
	min = a[1] - a[0];
	for(i = 1; i < n-1; i++) {
		if( min > a[i+1] - a[i]) {
			min = a[i+1] - a[i];
			min1 = a[i];
			min2 = a[i+1];
			//printf("%lld %lld %lld %lld\n", a[i], a[i+1], min1, min2);
		}
	}

	printf("%lld %lld\n", min1, min2);
	//for(i = 0; i < n; i++) {
	//	printf("%lld\n", a[i]);
	//}

	return 0;
}

void m_sort(long long int* a, long long int l, long long int r) {
    if(l==r)
        return;
    m_sort(a, l, ((l+r)/2));

    m_sort(a, (((l+r)/2)+1), r);
    merge(a, l, r);
    return;
}

void merge(long long int* a, long long int l, long long int r) {
    long long int m = (l+r)/2 + 1;
    long long int start = 0;
    long long int b[r-l+1];
	long long int i, j;
	
    long long int cl = l, cr = r, cm = m;
    while(start <= r-l) {
        if(((a[cl] <= a[cm])||(cm>r)) && (cl<m)) {
            b[start++] = a[cl++];       }
        else {
            b[start++] = a[cm++];
        }
    }
    for(i = l, j = 0; i <= r; i++, j++) {
        a[i] = b[j];
    }
    return;
}

