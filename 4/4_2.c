#include <stdio.h>


/*USAGE: 
	For use with long long int in C
	The functions must be initilaised before main(). The rest may come after. 
	Sorts by ascending order. 
	Call m_sort(array_name, start_index_of_array, end_index_of_array)
	Declare the array globally.
*/

void m_sort(long long int*,long long int, long long int);
void merge(long long int*, long long int, long long int);

long long int arr[1000];

int main() {

	long long int i, j, k, T, N, res = 0;;
 
	scanf("%lld %lld", &N, &k);

	for(i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}

	m_sort(arr, 0, N-1);
	//for(i = 0; i < N; i++) {
	//	printf("%lld ", arr[i]);
	//}

	for(i = 0; i < k; i++) {
		res += arr[N-1-i] - arr[i];
	}

	printf("%lld\n", res);

	/*
	long long int i, j, k, T, N;
 
	scanf("%lld", &N);

	for(i = 0; i < N; i++) {
		
	}

	printf("%lld\n", N);
	*/

	return 0;
}



/*
	Called first for merge purposes
	Recursively breaks the array into smaller arrays and passes them for merging
*/
void m_sort(long long int* a, long long int l, long long int r) {
    if(l==r)
        return;
    m_sort(a, l, ((l+r)/2));

    m_sort(a, (((l+r)/2)+1), r);
    merge(a, l, r);
    return;
}

/*
	Called by function m_sort
	Merges the smaller arrays by comparing against each element in succession
*/
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

