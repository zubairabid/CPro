#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>

void m_sort(long long int*,long long int, long long int);
void merge(long long int*, long long int, long long int);
int main() {
    long long int i, n;
    //data input
    scanf("%lld", &n);
    long long int a[n];

    for(i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    m_sort(a, 0, n-1);
    //\data input
    //mean
    long long int s = 0, m = a[0], freq = 0, max = a[0], mfreq = 0;
    for(i = 0; i < n; i++) {
        s+= a[i]; //sum

        if(a[i] == m) { //mode
            freq++;
            if(freq > mfreq) {
                mfreq = freq;
                max = m;
            }
        }
        else {
            m = a[i];
            freq = 1;
        }
    }

    long long int mean = s/n;
    long long int mode = max;
    long long int median = a[n/2];

    printf("%lld %lld %lld\n", mean, median, mode);//TODO print the 3

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

    long long int cl = l, cr = r, cm = m;
    while(start <= r-l) {
        if(((a[cl] <= a[cm])||(cm>r)) && (cl<m)) {
            b[start++] = a[cl++];       }
        else {
            b[start++] = a[cm++];
        }
    }
    long long int i, j;
    for(i = l, j = 0; i <= r; i++, j++) {
        a[i] = b[j];
    }
    return;
}

