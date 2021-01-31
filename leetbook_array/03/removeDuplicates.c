#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    int k = 0;
    if(numsSize == 1)
    {
        return 1;
    }
    else if(numsSize == 2)
    {
        if(nums[0] == nums[1])
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    for(int i = 1; i < numsSize; ++i)
    {
        if(nums[i] != nums[k])
        {
            k++;
            nums[k] = nums[i];
        }
    }

    return k+1;
}

int removeDuplicates2(int* nums, int numsSize){
    int k = 0;
    for(int i = 0; i < numsSize; ++i)
    {
        int j = 0;
        for(; j < k; ++j)
        {
            if(nums[i] == nums[j])
            {
                break;
            }
        }
        if(j == k)
        {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main()
{
    int nums[] = {1,1,2};
    int len = removeDuplicates2(nums, sizeof(nums)/sizeof(int));
    for(int i = 0; i < len; ++i)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}