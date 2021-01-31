#include <stdio.h>

void moveZeroes(int* nums, int numsSize){
    int j = 0;
    for(int i = 0; i < numsSize; ++i)
    {
        if(nums[i] != 0)
        {
            nums[j] = nums[i];
            ++j;
        }
    }
    for(; j < numsSize; ++j)
    {
        nums[j] = 0;
    }
}

int main()
{
    int nums[] = {0,1,0,3,12};
    moveZeroes(nums, 5);
    for(int i = 0; i < 5; ++i)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}