#include <stdio.h>

int removeElement(int* nums, int numsSize, int val){
    int j = 0;
    for(int i = 0; i < numsSize; ++i)
    {
        if(nums[i] != val)
        {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}

int main()
{
    int nums[] = {3,2,2,3};
    int len = removeElement(nums, sizeof(nums)/sizeof(int), 3);
    for(int i = 0; i < len; ++i)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}