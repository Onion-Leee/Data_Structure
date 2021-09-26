#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void removeElement(int* nums, int numsSize, int val)
{
    int a = 0;
    int c = 0;
    while (a < numsSize)
    {
        if (nums[a] != val)
        {
            nums[c] = nums[a];
            ++a;
            ++c;
        }
        else
        {
            ++a;
        }
    }
}
int main()
{
    int numsSize = 4;
    int nums[4] = { 3,2,2,3 };

    for (int i = 0; i < 4; ++i)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    removeElement(&nums, numsSize, 3);
    for (int i = 0; i < numsSize; ++i)
    {
        printf("%d ", nums[i]);
    }
    printf(" \n ");
    return 0;
}