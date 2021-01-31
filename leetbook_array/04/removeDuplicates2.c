#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    int i, j = 2;
    if(numsSize <= 2)
    {
        return numsSize;
    }
    for(i = 2; i < numsSize; ++i)
    {
        if(nums[i] != nums[j-2])
        {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}


int main()
{
    int nums[] = {0,0,1,1,1,1,2,3,3};
    int len = removeDuplicates(nums, sizeof(nums)/sizeof(int));
    for(int i = 0; i < len; ++i)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}