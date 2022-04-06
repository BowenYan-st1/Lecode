/*
 * @Author: unkonw
 * @Date: 2022-04-01 20:08:58
 * @LastEditors: aydan.yan
 * @LastEditTime: 2022-04-01 20:20:55
 * @FilePath: /剑指Offer/03. 数组中重复的数字/one.c
 * @Description: 
 * 
 * Copyright (c) 2022 by XGIMI, All Rights Reserved. 
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int findRepeatNumber(int* nums, int numsSize)
{
    char map[10] = {0};
    if (NULL == nums) {
        return -1;
    }
    for (int i = 0; i < numsSize; i++) {
        map[nums[i]]++;
        if (map[nums[i]] > 1) {
            return nums[i];
        }
    }
    return -1;
}

int main (int argc, char **atgv)
{
    int nums[] = {1,2,3,2,1};
    printf("%d\n", findRepeatNumber(nums, 5));
    return 0;
}