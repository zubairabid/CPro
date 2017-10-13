#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>

//USAGE: function init before main, rest after. Sorts by ascending order. 
//       call m_sort(array_name, start, end_of_array)
//       decalre array globally

void m_sort(long long int*,long long int, long long int);
void merge(long long int*, long long int, long long int);

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

