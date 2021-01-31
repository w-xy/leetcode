#include <stdio.h>
 
int maxArea(int* height, int heightSize){
    int left = 0, right = heightSize-1;
    int area, lower, higher;
    int maxarea = 0;
    int maxhegiht = 0;
    while (left < right)
    {
        if(height[left] < height[right])
        {
            lower = height[left];
            higher = height[right];
        }
        else
        {
            lower = height[right];
            higher = height[left];
        }
        area = lower*(right - left);
        if(area > maxarea)
        {
            maxarea = area;
        }

        if(height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return maxarea;
}

void main()
{
    int arr[] = {1,2,1};
    printf("%d\n", maxArea(arr, sizeof(arr)/sizeof(int)));
    return;
}