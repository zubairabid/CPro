#include <stdio.h>

//unsigned long long int t = 11111111110000000000;
unsigned long long int ar[1000000];
//int c = 0;
int track = 0;

unsigned long long int n10(int exp) {
	unsigned long long int res = 1;
	int i = 0;
	for(i = 0; i < exp; i++) {
		res*=10;
	}
	return res;
}

void convstr(unsigned long long int num, long long int len) {
	int i;
	for(i = len-1; i >= 0; i--) {
		printf("%c", (((num/n10(i))%10)==1?'(':')'));
	}
	printf("\n");
}

void generate(long long int N, int c) {
	//c tracks the initial state of the system
	if(N==0 && c==0) {
		ar[track+1] = ar[track];
		track++;
		return;
	}
	else if(N==0 && c != 0) {
		return;
	}


	if(c > 0) { // => existence of excess open brackets
		ar[track] = ar[track]*10; //+0
		generate(N-1, c-1);
		ar[track]/=10; //original state
		ar[track] = ar[track]*10 + 1;
		generate(N-1, c+1);
		ar[track]/=10;
	}

	if(c == 0) { // ==> equal no. of brackets.
		ar[track] = ar[track]*10+1;
		//c++;
		generate(N-1, c+1);
		ar[track]/=10;
		ar[track] = ar[track]*10; //+0
		generate(N-1, c-1);
		ar[track]/=10; //original state
		
	}
}


void m_sort(unsigned long long int*,unsigned long long int, unsigned long long int);
void merge(unsigned long long int*, unsigned long long int, unsigned long long int);

/*
	Called first for merge purposes
	Recursively breaks the array into smaller arrays and passes them for merging
*/
void m_sort(unsigned long long int* a, unsigned long long int l, unsigned long long int r) {
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
void merge(unsigned long long int* a, unsigned long long int l, unsigned long long int r) {
    unsigned long long int m = (l+r)/2 + 1;
    unsigned long long int start = 0;
    unsigned long long int b[r-l+1];
	unsigned long long int i, j;
	
    unsigned long long int cl = l, cr = r, cm = m;
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




int main() {
	
	//printf("%llu\n", t);
	
	long long int i, j, k, T, N;
	 
	scanf("%lld", &N);
	
	generate(2*N, 0);
	m_sort(ar, 0, track-1);

	for(i = track-1; i >=0 ; i--) {
		//printf("%llu\n", ar[i]);
		convstr(ar[i], (2*N));
	}
	//printf("%d\n", (track));

	/*
	long long int i, j, k, T, N;
	 
	scanf("%lld", &N);
	
	for(i = 0; i < N; i++) {
		
	}
	
	printf("%lld\n", N);
	*/

	return 0;
}




