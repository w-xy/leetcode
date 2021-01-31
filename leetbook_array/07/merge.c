#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

void printArr(int *nums, int numsSize)
{
    for(int i = 0; i < numsSize; ++i)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return;
}

#define PRINT_ARR(arr) printArr(arr, sizeof(arr)/sizeof(arr[0]))


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    if(n == 0)
    {
        return;
    }
    if(m == 0)
    {
        for(int i = 0; i < n; ++i)
        {
            nums1[i] = nums2[i];
        }
        return;
    }
    for(int i = m-1; i >= 0; --i)
    {
        nums1[i+n] = nums1[i];
    }
    int j = n, k = 0;
    for(int i = 0; i < m+n; ++i)
    {
        if(k >= n)
        {
            break;
        }
        if(j < m+n)
        {
            if(nums1[j] < nums2[k])
            {
                nums1[i] = nums1[j];
                j++;
                continue;
            }
        }
        nums1[i] = nums2[k];
        k++;
    }
    return;
}

void main()
{
    int arr1[] = {2,0}, arr2[] = {1};
    merge(arr1, 2, 1, arr2, 1, 1);
    PRINT_ARR(arr1);

    return;
}