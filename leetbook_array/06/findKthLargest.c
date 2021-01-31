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

int singleSort(int* nums, int left, int right)
{
    int key = nums[left];
    int i = left, j = right;
    while(i < j)
    {
        while((nums[j] < key) && (i < j))
        {
            j--;
        }
        if(i < j)
        {
            nums[i] = nums[j];
            i++;
        }
        while((nums[i] >= key) && (i < j))
        {
            i++;
        }
        if(i < j)
        {
            nums[j] = nums[i];
            j--;
        }
    }
    nums[i] = key;

    return i;
}

int quickSort(int* nums, int left, int right, int k)
{
    printf("sorting [%d, %d]: ", left, right);
    if(left < right)
    {
        int middle = singleSort(nums, left, right);
        printArr(&nums[left], right-left+1);
        if(k == middle)
        {
            return middle;
        }
        else if(k < middle)
        {
            return quickSort(nums, left, middle - 1, k);
        }
        else
        {
            return quickSort(nums, middle + 1, right, k);
        }
    }
    return left;
}

int findKthLargest(int* nums, int numsSize, int k){
    quickSort(nums, 0, numsSize-1, k-1);
    return nums[k-1];
}

void main()
{
    int arr[] = {3,2,3,1,2,4,5,5,6};
    int ret = findKthLargest(arr, sizeof(arr)/sizeof(int), 4);
    printf("%d\n", ret);

    return;
}