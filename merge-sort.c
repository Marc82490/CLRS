#include <stdio.h>
#include <math.h>
#include <limits.h>

int merge(int *A, int p, int q, int r)
{
    int n_1 = q - p + 1;
    int n_2 = r - q;
    int *L = malloc((n_1+1) * sizeof(int));
        
    if (L == NULL) {
        printf("Failed to allocate L memory");
        return 1;
    }
        
    int *R = malloc((n_2+1) * sizeof(int));
    
    if (R == NULL) {
        printf("Failed to allocate R memory");
        return 1;
    }
    
    
    for(int i = 0; i < n_1; i++)
    {
        L[i] = A[p + i];
    }
    
    for(int j = 0; j < n_2; j++)
    {
        R[j] = A[q + j + 1];
    }
    
    L[n_1] = INT_MAX;
    R[n_2] = INT_MAX;

    int i = 0;
    int j = 0;
    
    for(int k = p; k <= r; k++)
    {
        
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i = i + 1;
        }
        
        else
        {
            A[k] = R[j];
            j = j + 1;
        }
        
    }
    free(L);
    free(R);
}

void mergeSort(int *A, int p, int r)
{
    
    if (p < r) {
        int q = (int) floor((p + r) / 2);
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
        merge(A, p, q, r);
    }
    
}

int main(void)
{
    int A[] = {5, 6, 4, 2, 4, 3, 10};
    size_t n = sizeof(A) / sizeof(A[0]);
    mergeSort(A, 0, n-1);
    
    for(int i = 0; i < n; i++)
    {
        printf("%i ", A[i]);
    }
    
    return 0;
}