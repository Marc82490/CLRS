#include <stdio.h>
#include <math.h>

struct maxArray {
    int maxLeft;
    int maxRight;
    int sum;
};

struct maxArray maxCrossingSubarray(int *A, int low, int mid, int high)
{
    struct maxArray maxArrayObj;
    double leftSum = -INFINITY;
    maxArrayObj.sum = 0;
    
    for(int i = mid; i >= low; i--)
    {
        maxArrayObj.sum = maxArrayObj.sum + A[i];
        
        if (maxArrayObj.sum > leftSum) {
            leftSum = maxArrayObj.sum;
            maxArrayObj.maxLeft = i;
        }
    }

    double rightSum = -INFINITY;
    maxArrayObj.sum = 0;
    
    for(int j = mid+1; j <= high; j++)
    {
        maxArrayObj.sum = maxArrayObj.sum + A[j];
        
        if (maxArrayObj.sum > rightSum) {
            rightSum = maxArrayObj.sum;
            maxArrayObj.maxRight = j;
        }
    }
    maxArrayObj.sum = leftSum + rightSum;
    
    return maxArrayObj;
}

struct maxArray maxSubarray(int *A, int low, int high)
{
    struct maxArray maxArrayObj;
    maxArrayObj.maxLeft = low;
    maxArrayObj.maxRight = high;
    maxArrayObj.sum = A[low];

    if (high == low) {
        return maxArrayObj;
    }
    
    else
    {
        int mid = (int) floor((low + high) / 2);
        struct maxArray leftArrayObj = maxSubarray(A, low, mid);
        struct maxArray rightArrayObj = maxSubarray(A, mid+1, high);
        struct maxArray crossArrayObj = maxCrossingSubarray(A, low, mid, high);
        
        if (leftArrayObj.sum >= rightArrayObj.sum && leftArrayObj.sum >= crossArrayObj.sum) {
            return leftArrayObj;
        }
        
        else if (rightArrayObj.sum >= leftArrayObj.sum && rightArrayObj.sum >= crossArrayObj.sum)
        {
            return rightArrayObj;
        }
        
        else
        {
            return crossArrayObj;
        }
        
    }
    
}

int main(void)
{
    int A[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    struct maxArray resultArray = maxSubarray(A, 0, 15);
    printf("maxLeft: %i\n", resultArray.maxLeft);
    printf("maxRight: %i\n", resultArray.maxRight);
    printf("sum: %i\n", resultArray.sum);
    return 0;
}