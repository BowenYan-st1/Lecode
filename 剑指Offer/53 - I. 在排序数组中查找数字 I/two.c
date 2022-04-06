/*
 * @Author: your name
 * @Date: 2022-04-02 21:53:48
 * @LastEditTime: 2022-04-04 15:42:34
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置:
 * https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /剑指Offer/53 - I. 在排序数组中查找数字 I/two.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int helper(int *nums, int numsSize, int target);
//总结：二分法不仅可以查找数字，还可以查找边界,最终right为边界元素，left为最后一个元素
int search(int *nums, int numsSize, int target)
{
    if (NULL == nums || numsSize < 0) {
        return 0;
    }
    int left = 0, right = 0;
    right = helper(nums, numsSize, target);
    left = helper(nums,numsSize,target-1);
    return right - left;
}

//本质来说，二分法可以用来找排序表中的插入点
int helper(int *nums, int numsSize, int target)
{
    if (NULL == nums || numsSize < 0) {
        return 0;
    }
    int left = 0, right = numsSize - 1;
    int mid = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (target >= nums[mid]) {
            left = mid + 1;
        } else if (target < nums[mid]) {
            right = mid - 1;
        }
    }
    return right;
}

int main(int argc, char **argv)
{
    int nums[] = {5, 7, 7, 8, 8, 8, 8, 8, 10};
    printf("%d\n", search(nums, sizeof(nums) / sizeof(int), 7));
    return 0;
}