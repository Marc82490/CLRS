#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *A, int p, int r)
{
    int x = A[r];
    int i = p - 1;
    
    for(int j = p; j <= r - 1; j++)
    {
        
        if (A[j] <= x) {
            i++;
            swap(&A[i], &A[j]);
        }
        
    }
    
    swap(&A[i+1], &A[r]);

    return i + 1;
}

int randomizedPartition(int *A, int p, int r)
{
    // generate random int from the range [p, r]
    int i = p + rand() % (r - p + 1);
    swap(&A[r], &A[i]);
    return partition(A, p, r);
}

void randomizedQuicksort(int *A, int p, int r)
{
    
    if (p < r) {
        int q = randomizedPartition(A, p, r);
        randomizedQuicksort(A, p, q-1);
        randomizedQuicksort(A, q+1, r);
    }
    
}

int main(void)
{
    int A[] = {2, 8, 7, 1, 3, 5, 6, 4};
    size_t length = sizeof(A) / sizeof(A[0]);

    randomizedQuicksort(A, 0, length - 1);

    for(int i = 0; i < length; i++)
    {
        printf("%i ", A[i]);
    }

    return 0;
}