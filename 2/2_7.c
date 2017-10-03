#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>

void m_sort(int*,int, int);
void merge(int*, int, int);
int main() {
    int i, j, n;
    //data input
    scanf("%d", &n);
    int a[n];

    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    m_sort(a, 0, n-1);
    //\data input
    //mean
    int s = 0, m = a[0], freq = 0, max = a[0], mfreq = 0;
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

    int mean = s/n;
    int mode = max;
    int median = a[n/2];

    printf("%d %d %d\n", mean, median, mode);//TODO print the 3

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

    int cl = l, cr = r, cm = m;
    while(start <= r-l) {
        if(((a[cl] <= a[cm])||(cm>r)) && (cl<m)) {
            b[start++] = a[cl++];       }
        else {
            b[start++] = a[cm++];
        }
    }
    for(int i = l, j = 0; i <= r; i++, j++) {
        a[i] = b[j];
    }
    return;
}

