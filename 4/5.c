#include <stdio.h>
long long int a[10000000];

void m_sort(long long int*,long long int, long long int);
void merge(long long int*, long long int, long long int);
//USAGE: function init before main, rest after. Sorts by ascending order. 
//       call m_sort(array_name, start, end_of_array)
//       decalre array globally

int main() {
	long long int T, N, num, sum = 0, i, j, mid = 0; 
	scanf("%lld", &T); // no. of test cases
	//printf("Tests: %d\n", T);
	for(i = 0; i < T; i++) { // each test case
		scanf("%lld", &N); //size of each array
		if(N==0)
			continue;
		num = 0;
		sum = 0;
		mid = 0;
		for(j = 0; j < N; j++) {
			//printf("Entered input loop\n");
			scanf("%lld", &a[j]); //array input
			mid += a[j];
		}
		//mid++;
		mid = mid / 2;
		//printf("Exited input loop, entering m_sort\n");
		m_sort(a, 0, N-1);

		for(j = N-1; sum <= mid; j--) {
			//printf("Considering %lld now. \n", a[i]);
			sum += a[j];
			num++;
		}

		printf("%lld\n", num);
	}


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