/*
 * @Author: your name
 * @Date: 2022-04-04 17:17:55
 * @LastEditTime: 2022-04-04 18:24:54
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置:
 * https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /剑指Offer/11. 旋转数组的最小数字/one.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
给你一个可能存在 重复 元素值的数组 numbers ，它原来是一个升序排列的数组，并按上述情形进行了一次旋转。
请返回旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5]
的一次旋转，该数组的最小值为 1。   注意，数组 [a[0], a[1], a[2], ..., a[n-1]]
旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

示例 1：
输入：numbers = [3,4,5,1,2]
输出：1
示例 2：

输入：numbers = [2,2,2,0,1]
输出：0
 
提示：
n == numbers.length
1 <= n <= 5000
-5000 <= numbers[i] <= 5000
numbers 原来是一个升序排序的数组，并进行了 1 至 n 次旋转
*/

int minArray(int *numbers, int numbersSize)
{
    if (NULL == numbers || numbersSize <= 0) {
        return 0;
    }
    int left = 0, right = numbersSize - 1;
    int mid = 0;
    if (numbers[left] < numbers[right]) {
        return numbers[0];
    }
    while (left < right) {
        mid = (right + left) / 2;
        if (numbers[mid] > numbers[right]) {
            left = mid + 1;
        } else if (numbers[mid] < numbers[right]) {
            right = mid;
        } else {
            right--;
        }
    }
    return numbers[left];
}

int main(int argc, char **argv)
{
    int numbers[] = {10,1,10,10,10};
    printf("result = %d\n", minArray(numbers, sizeof(numbers) / sizeof(int)));
    return 0;
}
