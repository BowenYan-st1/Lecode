/*
 * @Author: your name
 * @Date: 2022-04-04 15:45:57
 * @LastEditTime: 2022-04-04 16:12:46
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置:
 * https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /剑指Offer/53 - II. 0～n-1 中缺失的数字/one.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

示例 1:
输入: [0,1,3]
输出: 2

示例 2:
输入: [0,1,2,3,4,5,6,7,9]
输出: 8

限制：
1 <= 数组长度 <= 10000
*/

//实际上，查找数组值与数组索引是否相等，当发生数字缺失时，缺失后的数组值与索引值会不同
//因为数组是顺序表，所以可通过二分查找，快速找到数字缺失处
//使用二分查找，查找数组值与索引值相等的边界
int missingNumber(int *nums, int numsSize)
{
    if (NULL == nums || numsSize < 0) {
        return -1;
    }
    int left = 0, right = numsSize -1;
    int mid = 0;
    while (left <= right) {
        mid = (right + left)/ 2;
        if (nums[mid] == mid) {
            left = mid + 1;
        } else {
            right = mid -1;
        }
    }
    return left;
}

int main(int argc, char **argv)
{
    int nums[] = {0};
    printf("%d\n", missingNumber(nums, sizeof(nums) / sizeof(int)));
    return 0;
}
