#include <stdio.h>

int sumArray(int* nums, int i, int j)
{
    int sum = 0;
    for(;i < j; ++i)
    {
        printf("%d,", nums[i]);
        sum += nums[i];
    }
    return sum;
}

int minSubArrayLen(int s, int* nums, int numsSize){
    int i = 0, j = 0, minlen, sum, len;
    for(minlen = 0; minlen <= numsSize; ++minlen)
    {
        if(sumArray(nums, 0, minlen) >= s)
        {
            break;
        }
    }
    if(minlen > numsSize)
    {
        return 0;
    }
    for(i = 1; i < numsSize; ++i)
    {
        len = (minlen < numsSize-i) ? minlen : (numsSize-i);
        while(sumArray(nums, i, i+len) >= s)
        {
            minlen = len--;
        }
    }
    return minlen;
}

void main()
{
    int arr[] = {2,3,1,2,4,3};
    printf("%d\n", minSubArrayLen(7, arr, sizeof(arr)/sizeof(int)));
}