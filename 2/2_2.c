#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>

int main() {
    int N, seg, i, j, flag, sum = 0;
    scanf("%d", &N);
    int a[N];
    for(i = 0; i < N; i++) //array input
        scanf("%d", &a[i]);

    int freq[10];
    if(N > 10)
        seg = 10;
    else
        seg = N;

    while(seg > 0) {
        //printf("Segment length: %d\n", seg);
        for(i = 0; i <= N-seg; i++) {//to iterate through all like lengthed subarrays

            //printf("Iteration bounds: %d %d\n", i, (N-seg));
            flag = 0;
            for(j = 0; j < 10; j++)
                freq[j] = 0;

            for(j = i; j < i+seg; j++) {//iterates through subarray
                //printf("%d ", a[j]);

                if(freq[a[j]] == 0) {//this is fine
                    freq[a[j]] = 1;
                }
                else {//this isn't. Abort
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) //If it's untouched
                sum += seg;//Add

            //printf("Sum: %d\n", sum);
        }
        seg--;
    }

    printf("%d\n", sum);

    return 0;
}

