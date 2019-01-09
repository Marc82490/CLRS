#include <stdio.h>
#include <math.h>

int parent(int i)
{
    // differs from CLRS pseudocode to deal with 0-indexed arrays
    return (int) floor((i - 1) / 2);
}

int leftChild(int i)
{
    // differs from CLRS pseudocode to deal with 0-indexed arrays
    return 2 * i + 1;
}

int rightChild(int i)
{
    // differs from CLRS pseudocode to deal with 0-indexed arrays
    return 2 * i + 2;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void maxHeapify(int *A, int i, int heapsize)
{
    int l = leftChild(i);
    int r = rightChild(i);
    int largest;
    
    if (l <= heapsize && A[l] > A[i]) {
        largest = l;
    }
    
    else
    {
        largest = i;
    }
    
    if (r <= heapsize && A[r] > A[largest]) {
        largest = r;
    }
    
    if (largest != i) {
        swap(&A[i], &A[largest]);
        maxHeapify(A, largest, heapsize);
    }

}

int buildMaxHeap(int *A, int length)
{
    int heapsize = length - 1;

    for(int i = (int) floor((length - 1) / 2); i >= 0; i--)
    {
        maxHeapify(A, i, heapsize);
    }
    
    return heapsize;
}

void heapsort(int *A, int length)
{
    int heapsize = buildMaxHeap(A, length);

    for(int i = length-1; i > 0; i--)
    {
        swap(&A[0], &A[i]);
        heapsize--;
        maxHeapify(A, 0, heapsize);
    }
    
}

int main(void)
{
    int A[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    size_t length = sizeof(A) / sizeof(A[0]);
    heapsort(A, length);
    
    for(int i = 0; i < length; i++)
    {
        printf("%i ", A[i]);
    }

    return 0;
}