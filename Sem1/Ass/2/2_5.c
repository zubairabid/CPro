#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>

void m_sort(int*,int, int);
void merge(int*, int, int);

int main() {
    int i, j, k, T, N, V, s;
    scanf("%d", &T);

    for(i = 0; i < T; i++) {
        s = 0;
        k = 0;
        scanf("%d %d", &N, &V);
        int A[N];
        for(j = 0; j < N; j++) {
            scanf("%d", &A[j]);
        }
        m_sort(A, 0, N-1);
        k = N-1;
        /*printf("After Sorting:\n");
        for(j = 0; j < N; j++) {
            printf("%d", A[j]);
        }
        printf("\n");
        */
        while(s<V && k > -1) {
            s+=A[k--];
        }
        if(s < V) {
        	printf("-1\n");
        }
        else {
        	printf("%d\n", (N-1-k));
        }
    }
    return 0;
}

void m_sort(int* a, int l, int r) {
    if(l==r)
        return;
    m_sort(a, l, ((l+r)/2));

    m_sort(a, (((l+r)/2)+1), r);
    merge(a, l, r);
    return;
}

void merge(int* a, int l, int r) {
    int m = (l+r)/2 + 1;
    int start = 0;
    int b[r-l+1];
	int i, j;
	
    int cl = l, cr = r, cm = m;
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

