#include <stdio.h>


int main() {
    const int max_size=4;
    int a[max_size]={1,3,2,0};
    int j;
    for (int i=0; i<(max_size-1);i++)
    {
        for (int k=0; k<(max_size-i-1); k++) {
            if (a[k] > a[k + 1]) {
                j = a[k];
                a[k] = a[k + 1];
                a[k + 1] = j;
            }
        }

    }
    for (int l=0; l<max_size; l++)
    {
        printf("%d ", a[l]);
    }
}