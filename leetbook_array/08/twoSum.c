#include <stdio.h>
#include <malloc.h>

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

#define ARR_SIZE(arr) sizeof(arr)/sizeof(arr[0])
#define PRINT_ARR(arr) printArr(arr, sizeof(arr)/sizeof(arr[0]))

int search(int* numbers, int left, int right, int rest)
{
    int middle = (left+right)/2;
    if(left == right)
    {
        return -1;
    }
    else if(left+1 == right)
    {
        return (rest == numbers[right]) ? right : -1;
    }
    else if(rest == numbers[middle])
    {
        return middle;
    }
    else if(rest < numbers[middle])
    {
        return search(numbers, left, middle-1, rest);
    }
    else
    {
        return search(numbers, middle+1, right, rest);
    }
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int i, j = -1;
    for(i = 0; i < numbersSize-1; ++i)
    {
        int rest = target - numbers[i];
        if(numbers[numbersSize-1] == rest)
        {
            j = numbersSize-1;
            break;
        }
        else if(numbers[numbersSize-1] > rest)
        {
            j = search(numbers, i, numbersSize-1, rest);
            if(j > 0)
            {
                break;
            }
        }
    }
    if(j > 0)
    {
        int *ret = (int *)malloc(2*sizeof(int));
        if(ret != NULL)
        {
            *ret = i+1;
            *(ret+1) = j+1;
            *returnSize = 2;
            return ret;
        }
    }
    *returnSize = 0;
    return NULL;
}

int main()
{
    int numbers[] = {3,24,50,79,88,150,345};
    int size;
    int *ret = twoSum(numbers, ARR_SIZE(numbers), 200, &size);
    if(ret != NULL)
    {
        printArr(ret, size);
    }
    return 0;
}