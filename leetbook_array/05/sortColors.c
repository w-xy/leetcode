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

void sortColors(int* nums, int numsSize){
    int i, j = 0, k = numsSize-1;
    for(i = 0; i <= k;)
    {
        if(nums[i] == 0)
        {
            swap(&nums[i], &nums[j]);
            ++j;
            ++i;
        }
        else if(nums[i] == 2)
        {
            swap(&nums[i], &nums[k]);
            --k;
        }
        else
        {
            ++i;
        }
    }
    return;
}

void main()
{
    int arr[] = {0};
    sortColors(arr, sizeof(arr)/sizeof(int));
    PRINT_ARR(arr);

    return;
}